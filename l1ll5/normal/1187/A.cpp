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
int T,n,s,t;
int main()
{
    T=read();
    while(T--)
    {
        n=read(),s=read(),t=read();
        int mx=min(s,t);
        int ans=n-mx+1;
        cout<<ans<<endl;
    }
}