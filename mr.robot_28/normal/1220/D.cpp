#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<deque>
#include<bitset>
#include<map>
#define inf 1e9
#define eps 1e-6
#define N 200010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
ll c[N],ans;
ll a[N],b[N],n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(register ll i=1;i<=n;i++)
	{
		ll x=b[i]=read();
		ll tmp=0;
		while(x%2==0)tmp++,x/=2;
		c[tmp]++;a[i]=tmp;
	}
	for(register ll i=1;i<=62;i++)if(c[i]>c[ans])ans=i;
	printf("%I64d\n",n-c[ans]);
	for(register ll i=1;i<=n;i++)if(a[i]!=ans)printf("%I64d ",b[i]);
	printf("\n");
	return 0;
}