#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1005
#define ll long long
using namespace std;
#define mod 998244353
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int p[N][N];
int t[N],a[N],b[N];
int n,m;
int w,h;
int main()
{
    w=read(),h=read();
    int ans=1;
    while(w--)ans=(ans<<1)%mod;
    while(h--)ans=(ans<<1)%mod;
    cout<<ans<<endl;
}