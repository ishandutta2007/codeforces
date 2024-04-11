#include<bits/stdc++.h>
using namespace std;
#define re register
struct eg{int to;eg*nx;}e[400100],*la[200100],*cnt=e;
const int mod=998244353;
void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int fac[200100],f[200100],n;
void dfs(re int a,re int fa)
{
	re int d=0;f[a]=1;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dfs(i->to,a);
		f[a]=(long long)f[a]*f[i->to]%mod*(++d)%mod;
	}
	if(a==1)f[a]=(long long)f[a]*n%mod;
	else f[a]=(long long)f[a]*(++d)%mod;
}
int main()
{
	re int x,y;
	scanf("%d",&n);
	for(re int i=1;i<n;i++)scanf("%d%d",&x,&y),addE(x,y);
	fac[0]=1;
	for(re int i=1;i<=n;i++)fac[i]=(long long)fac[i-1]*i%mod;
	dfs(1,0);
	printf("%d\n",f[1]);
}