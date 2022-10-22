#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define M 1000005
#define ll long long
#define mid (l+r>>1)
int T,n,m,p[M],g[M],f[M];ll a[N];bool vs[M];struct Seg {ll v[2];}sg[N<<2];
ll max(ll x,ll y) {return x>y?x:y;}
void sieve(int n)
{
	vs[1]=g[1]=f[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i,g[i]=f[i]=2;
		for(int j=1;i*p[j]<=n;++j)
		{
			vs[i*p[j]]=1;
			if(i%p[j]) g[i*p[j]]=2,f[i*p[j]]=f[i]*f[p[j]];
			else {g[i*p[j]]=g[i]+1,f[i*p[j]]=f[i]/g[i]*g[i*p[j]];break;}
		}
	}
}
void pu(int p)
{
	sg[p].v[0]=sg[p<<1].v[0]+sg[p<<1|1].v[0];
	sg[p].v[1]=max(sg[p<<1].v[1],sg[p<<1|1].v[1]);
}
void build(int p,int l,int r)
{
	if(l==r) {sg[p].v[0]=sg[p].v[1]=a[l];return;}
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pu(p); 
}
void upd(int p,int l,int r,int qL,int qR)
{
	if(l==r) {sg[p].v[0]=sg[p].v[1]=f[sg[p].v[0]];return;}
	if(qL<=mid && sg[p<<1].v[1]>2) upd(p<<1,l,mid,qL,qR);
	if(qR>mid && sg[p<<1|1].v[1]>2) upd(p<<1|1,mid+1,r,qL,qR);pu(p);
}
ll qSm(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p].v[0];ll res=0;
	if(qL<=mid) res=qSm(p<<1,l,mid,qL,qR);
	if(qR>mid) res+=qSm(p<<1|1,mid+1,r,qL,qR);return res;
}
int main()
{
	sieve(1e6);scanf("%d",&n);scanf("%d",&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);build(1,1,n);
	for(int i=1,op,l,r;i<=m;++i)
	{
		scanf("%d %d %d",&op,&l,&r);if(l>r) l^=r^=l^=r;
		if(op==1) upd(1,1,n,l,r);if(op==2) printf("%lld\n",qSm(1,1,n,l,r));
	}return 0;
}