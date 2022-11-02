#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 800005
#define ll long long
using namespace std;
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define OUT 20000000
char Out[OUT],*ou=Out;
int Outn[30],Outcnt;
inline void write(ll x)
{
    if(!x)*ou++=48;
    else
    {
        for(Outcnt=0;x;x/=10)Outn[++Outcnt]=x%10+48;
        while(Outcnt)*ou++=Outn[Outcnt--];
    }
}
int n;
struct zgz
{
    ll x;
    int flag;
    friend bool operator <(const zgz &a,const zgz &b)
    {return a.x<b.x;}
}a[N];
int cnt;
ll ans[N];
void init()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        ll x=read(),y=read();
        a[++cnt]=(zgz){x,1},a[++cnt]=(zgz){y+1,-1};
    }
    sort(a+1,a+cnt+1);
}
void solve()
{
    ll x=1;
    int j=0;
    for(int i=1;i<=cnt;i++)
    {
        ans[j]+=a[i].x-x;
        j+=a[i].flag;
        while(a[i].x==a[i+1].x)i++,j+=a[i].flag;
        x=a[i].x;
    }
}
int main()
{
    init();
    solve();
    for(int i=1;i<=n;i++)write(ans[i]),*ou++=' ';
    fwrite(Out,1,ou-Out,stdout);
}