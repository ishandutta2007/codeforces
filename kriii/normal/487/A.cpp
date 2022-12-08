#include <stdio.h>
#include <algorithm>
using namespace std;

int hy,ay,dy,hm,am,dm,h,a,d,ans;
int need[20001];

void upd(int hp, int atk, int def)
{
    int cost = hp * h + atk * a + def * d;
    ans = min(ans,cost);
}

int main()
{
    scanf ("%d %d %d",&hy,&ay,&dy);
    scanf ("%d %d %d",&hm,&am,&dm);
    scanf ("%d %d %d",&h,&a,&d);

    ans = 0x7fffffff;

    for (int i=0;i<=20000;i++) need[i] = 2000000;
    for (int atk=20000;atk>=0;atk--){
        int mdmg = max(0,ay+atk-dm);
        if (mdmg == 0) break;
        int turn = (hm + mdmg - 1) / mdmg;
        need[turn] = atk;
    }
    for (int i=1;i<=20000;i++){
        if (need[i] > need[i-1])
            need[i] = need[i-1];
    }
    for (int hp=0;hp<=15000;hp++){
        for (int def=0;def<=100;def++){
            int dmg = max(0,am-dy-def);
            if (dmg == 0){
                int mdmg = max(0,ay-dm);
                if (mdmg == 0){
                    int atk = dm - ay + 1;
                    upd(hp,atk,def);
                }
                else upd(hp,0,def);
            }
            else{
                int turn = (hy + hp - 1) / dmg;
                upd(hp,need[turn],def);
            }
        }
    }

    printf ("%d\n",ans);

    return 0;
}