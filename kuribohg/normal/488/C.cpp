#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int h1,h2,a1,a2,d1,d2,h,a,d,ans=2e9,con;
int main()
{
    scanf("%d%d%d%d%d%d%d%d%d",&h1,&a1,&d1,&h2,&a2,&d2,&h,&a,&d);
    for(int Atk=d2+1;Atk<=d2+h2;Atk++)
        for(int Def=1;Def<=a2;Def++)
        {
            con=max(Atk-a1,0)*a+max(Def-d1,0)*d;
            int Round=(h2+Atk-d2-1)/(Atk-d2);
            int Hp=Round*max(a2-Def,0)+1;
            con+=max(Hp-h1,0)*h;
            ans=min(ans,con);
        }
    printf("%d\n",ans);
    return 0;
}