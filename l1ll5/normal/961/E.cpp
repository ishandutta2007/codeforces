#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
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
int a[N];
namespace bit
{
    int c[N];
    void add(int x)
	{
		for(;x<=n;x+=x&(-x))
		c[x]++;
	}
	int ask(int x)
	{
		int ret=0;
		for(;x;x-=x&(-x))ret+=c[x];
		return ret;
	}
}
vector<int> v[N];
ll ans;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),a[i]=min(a[i],n);

    for(int i=1;i<=n;i++)
    {
        int pos=min(i-1,a[i]);
        v[pos].push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
        bit::add(a[i]);
        for(int j=0;j<v[i].size();j++)
        {
            int x=v[i][j];
            ans+=(i-bit::ask(x-1));
        }
    }
    printf("%lld\n",ans);
}