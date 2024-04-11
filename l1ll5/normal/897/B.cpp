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
ll k,p,sum;
ll cal(ll x)
{
    ll ret=x,tmp=x,the_len=0;
    while(tmp)tmp/=10,the_len++;
    for(int i=1;i<=the_len;i++)
    ret=ret*10+x%10,x/=10;
    return ret;
}
int main()
{
    k=read(),p=read();
    for(int i=1;i<=k;i++)sum+=cal(i),sum%=p;
    cout<<sum<<endl;
}