#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll x,y;
char s[N];
int main()
{
    n=read();
    x=read(),y=read();
    scanf("%s",s+1);
    if(n==1)
    {
        if(s[1]=='1')
        {
            puts("0");
            return 0;
        }
        else
        {
            cout<<y<<endl;
            return 0;
        }
    }
    int blk=0;
    for(int i=1;i<=n;i++)
    if(s[i]!=s[i-1])blk++;

    if(blk==1)
    {
        if(s[1]=='1')
        {
            puts("0");
            return 0;
        }
        else
        {
            cout<<y<<endl;
            return 0;
        }
    }
    if(blk&1)
    {
        if(s[1]=='1')blk--;
        else blk++;
    }
    blk/=2;
    ll ans=0;
    ans=min((blk-1)*x+y,blk*y);
    printf("%lld\n",ans);
}