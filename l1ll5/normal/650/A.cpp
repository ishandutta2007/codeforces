#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200010
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
int x[N],y[N];
map<int,int> p,q;
map<pair<int,int>,int> z;
ll ans;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
    for(int i=1;i<=n;i++)
    {
        int A=p[x[i]],B=q[y[i]],C=z[make_pair(x[i],y[i])];
        ans+=A,ans+=B,ans-=C;
        p[x[i]]++,q[y[i]]++,z[make_pair(x[i],y[i])]++;
    }
    cout<<ans<<endl;
}