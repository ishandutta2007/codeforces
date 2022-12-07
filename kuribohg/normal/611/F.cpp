#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,a,b,posx,posy,maxx,maxy,minx,miny;
char str[500010];
vector<int> positions;
LL ans;
bool work(LL x,int type)
{
    LL k=x;x%=n;
    if(type==0)
    {
        if(str[x]=='L') posy--;
        else if(str[x]=='R') posy++;
        else if(str[x]=='U') posx--;
        else posx++;
    }
    else
    {
        if(str[x]=='L') posy=miny-1;
        else if(str[x]=='R') posy=maxy+1;
        else if(str[x]=='U') posx=minx-1;
        else posx=maxx+1;
    }
    bool res=false;
    if(posx>maxx||posx<minx)
    {
        ans=(ans+(k+1)%MOD*b%MOD)%MOD;
        a--;
        if(posx<minx) minx=posx;
        if(posx>maxx) maxx=posx;
        res=true;
    }
    if(posy>maxy||posy<miny)
    {
        ans=(ans+(k+1)%MOD*a%MOD)%MOD;
        b--;
        if(posy<miny) miny=posy;
        if(posy>maxy) maxy=posy;
        res=true;
    }
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",str);
    for(int i=0;i<n;i++)
        if(a!=0&&b!=0) work(i,0);
    if(posx==0&&posy==0) {puts("-1");return 0;}
    for(int i=n;i<n+n;i++)
        if(a!=0&&b!=0)
            if(work(i,0)) positions.push_back(i%n);
    for(int i=2;a!=0&&b!=0;i++)
        for(int k=0;k<positions.size();k++)
            if(a!=0&&b!=0) work((LL)i*n+positions[k],1);
    printf("%I64d\n",ans);
    return 0;
}