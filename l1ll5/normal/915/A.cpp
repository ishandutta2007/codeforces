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
int n,k;
int a[N],ans;
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    ans=100000;
    for(int i=1;i<=n;i++)
    if(k%a[i]==0)ans=min(ans,k/a[i]);
    cout<<ans<<endl;
}