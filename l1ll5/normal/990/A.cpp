#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,m,a,b;
int main()
{
    cin>>n>>m>>a>>b;
    if(n%m==0)
    {
        cout<<0<<endl;
        return 0;
    }
    ll ret=n%m;
    ll ans=min(ret*b,(m-ret)*a);
    cout<<ans<<endl;
}