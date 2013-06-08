#include "GameState.h"

#include "BackgroundPanel.h"
USING_NS_CC;
USING_NS_CC_EXT;


BackgroundPanel::BackgroundPanel()
{

}


BackgroundPanel::~BackgroundPanel()
{

}

const char* darkpanelpngs[] = {
   //   "ninjasprite.png"
      "lightsout-1-gray.png"
};

const char* lightpanelpngs[] = {
   "lightsout-1-color.png"
};

void BackgroundPanel::toggleOn(bool on)
{
   m_bLightOn = on;
   // flip tex
   const char** namelist = m_bLightOn ? lightpanelpngs : darkpanelpngs;
   CCTexture2D* tex = CCTextureCache::sharedTextureCache()->addImage(namelist[0]);
   setTexture(tex);

   //CCSize texsize = tex->getContentSize();
   //CCLog("updategs width  %f %f", texsize.width, texsize.height);
   /*
   panel->setContentSize(texsize);
   panel->setColor(ccc3(255,255,255));
   panel->setVisible(true);
   */
}


BackgroundPanel* BackgroundPanel::createHack()
{
   BackgroundPanel* panel = new BackgroundPanel;
   panel->m_bLightOn = STATE->isLightOn();
   // flip tex
   const char** namelist = panel->m_bLightOn ? lightpanelpngs : darkpanelpngs;
   if (panel && panel->initWithFile(namelist[0])) {
      // set the scale to match the size in height
      CCSize s = CCDirector::sharedDirector()->getWinSize();
      panel->setScale(.8 * s.height / panel->getContentSize().height);

      panel->autorelease();
      return panel;
   }
   CC_SAFE_DELETE(panel);
   return panel;
}
