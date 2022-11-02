#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 500005

#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define int long long
int n,m;
int ans;
int fac[N];
main()
{
    n=read()+1,m=read();
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%m;
    for(int i=1;i<=n;i++)
    {
        ans+=(n-i)*fac[i]%m*fac[n-i]%m;
        ans%=m;
    }
    cout<<ans<<endl;
}
// i! (n-i)!