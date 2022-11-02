#include <map>
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
int n,p,k;
int a[N];
map<int,int> buc;
int pow4(int x)
{
    ll y=(ll)x*x%p;
    ll z=y*y%p;
    return z;
}
ll ans;
int main()
{
    n=read(),p=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        int x=pow4(a[i])-(ll)k*a[i]%p;
        x=x+p;
        x=x%p;
        ans+=buc[x];
        buc[x]++;
    }
    cout<<ans<<endl;
}