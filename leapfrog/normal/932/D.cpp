#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,c,a,b,lst,cnt=1,f[400005][25];long long w[400005],st[400005][25],INF=(long long)0x3f3f3f3f3f3f3f3f;
inline void add(int u,int v)
{
	if(w[u]>=w[v]) f[v][0]=u;
	else for(int i=20;i>=0;i--) {if(w[f[u][i]]<w[v]) u=f[u][i];f[v][0]=f[u][0];}
	st[v][0]=w[f[v][0]];
	for(int i=1;i<=20;i++)
	{
		f[v][i]=f[f[v][i-1]][i-1];
		if(f[v][i]!=0&&st[f[v][i-1]][i-1]!=INF) st[v][i]=st[v][i-1]+st[f[v][i-1]][i-1];else st[v][i]=INF;
	}
}
inline int query(int r,long long x)
{
	if(w[r]>x) return 0;else x-=w[r];int ans=1;
	for(int i=20;i>=0;i--) if(x-st[r][i]>=0) x-=st[r][i],ans+=1<<i,r=f[r][i];
	return ans;
}
signed main()
{
	memset(st[1],0x3f,sizeof(st[1])),w[0]=INF;
	for(scanf("%lld",&q),lst=0;q--;)
	{
		scanf("%lld%lld%lld",&c,&a,&b),a^=lst,b^=lst;
		if(c==1) w[++cnt]=b,add(a,cnt);else lst=query(a,b),printf("%lld\n",lst);
	}
	return 0;
}