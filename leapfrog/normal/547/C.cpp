//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,q,mu[500005],cn[500005],pc,pr[500005],a[200005],f[500005];
char pv[500005],fg[200005];vector<int>fc[500005];ll rs=0;
inline void upd(int w,int fg) {for(auto x:fc[w]) rs-=1ll*mu[x]*f[x]*f[x],f[x]+=fg,rs+=1ll*mu[x]*f[x]*f[x];}
int main()
{
	read(n),read(q);for(int i=1;i<=n;i++) read(a[i]),m=max(m,a[i]);
	mu[1]=1,pv[1]=1;for(int i=1;i<=m;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1;
		for(int j=1;j<=pc&&i*pr[j]<=m;j++)
		{
			mu[i*pr[j]]=i%pr[j]?-mu[i]:0;
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
	for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i) fc[j].push_back(i);
	for(int w;q--;)
	{
		read(w);if(fg[w]) cn[a[w]]--,upd(a[w],-1),fg[w]=0;
		else cn[a[w]]++,upd(a[w],1),fg[w]=1;
		printf("%lld\n",(rs-cn[1])/2);
	}
	return 0;
}