#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
const ll base=233,mod1=167772161,mod2=998244353;
ll base_inv1,base_inv2;
inline ll qpow(ll x,ll y,ll mod){
	ll ret=1;
	for(;y;x=x*x%mod,y>>=1)if(y&1)ret=ret*x%mod;
	return ret;
}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
char a[maxn];
int cnt,dep[maxn],fa[maxn],m,n,rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
ll bs1[maxn],bs2[maxn],bs_inv1[maxn],bs_inv2[maxn],ha_lf1[maxn],ha_lf2[maxn],ha_rt1[maxn],ha_rt2[maxn];
inline ll module1(ll k){
	if(k<0)k+=mod1;
	if(k>mod1)k-=mod1;
	return k;
}
inline ll module2(ll k){
	if(k<0)k+=mod2;
	if(k>mod2)k-=mod2;
	return k;
}
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	ha_rt1[p]=module1(ha_rt1[f]*base%mod1+a[p]);
	ha_rt2[p]=module2(ha_rt2[f]*base%mod2+a[p]);
	ha_lf1[p]=module1(ha_lf1[f]+a[p]*bs1[dep[f]]%mod1);
	ha_lf2[p]=module2(ha_lf2[f]+a[p]*bs2[dep[f]]%mod2);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++cnt;
	rev[cnt]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline int getfa(int x,int k){
	while(dep[x]-dep[top[x]]<k)k-=dep[x]-dep[top[x]]+1,x=fa[top[x]];
	return rev[seg[x]-k];
}
inline ll getha_lf1(int st,int ed){
	return module1(ha_lf1[st]-ha_lf1[fa[ed]])*bs_inv1[dep[ed]-1]%mod1;
}
inline ll getha_rt1(int st,int ed){
	return module1(ha_rt1[ed]-ha_rt1[fa[st]]*bs1[dep[ed]-dep[st]+1]%mod1);
}
inline ll getha1(int st,int ed,int p,int k){
	if(dep[st]-dep[p]+1<k){
		ll ret1=getha_lf1(st,p);
		k-=dep[st]-dep[p]+1;
		ed=getfa(ed,dep[ed]-dep[p]-k);
		ri len=dep[ed]-dep[p];
		ll ret2=getha_rt1(getfa(ed,len-1),ed);
		return module1(ret1*bs1[len]%mod1+ret2);
	}
	return getha_lf1(st,getfa(st,k-1));
}
inline ll getha_lf2(int st,int ed){
	return module2(ha_lf2[st]-ha_lf2[fa[ed]])*bs_inv2[dep[ed]-1]%mod2;
}
inline ll getha_rt2(int st,int ed){
	return module2(ha_rt2[ed]-ha_rt2[fa[st]]*bs2[dep[ed]-dep[st]+1]%mod2);
}
inline ll getha2(int st,int ed,int p,int k){
	if(dep[st]-dep[p]+1<k){
		ll ret1=getha_lf2(st,p);
		k-=dep[st]-dep[p]+1;
		ed=getfa(ed,dep[ed]-dep[p]-k);
		ri len=dep[ed]-dep[p];
		ll ret2=getha_rt2(getfa(ed,len-1),ed);
		return module2(ret1*bs2[len]%mod2+ret2);
	}
	return getha_lf2(st,getfa(st,k-1));
}
int main(){
	scanf("%d%s",&n,a+1);
	bs1[0]=bs2[0]=bs_inv1[0]=bs_inv2[0]=1;
	base_inv1=qpow(base,mod1-2,mod1),base_inv2=qpow(base,mod2-2,mod2);
	for(ri i=1;i<=n;++i){
		bs1[i]=bs1[i-1]*base%mod1;
		bs2[i]=bs2[i-1]*base%mod2;
		bs_inv1[i]=bs_inv1[i-1]*base_inv1%mod1;
		bs_inv2[i]=bs_inv2[i-1]*base_inv2%mod2;
	}
	for(ri i=1;i<n;++i){
		ri x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	scanf("%d",&m);
	while(m--){
		ri d,dd,x,xx,y,yy,z,zz;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		z=lca(x,y),zz=lca(xx,yy);
		d=dep[x]+dep[y]-2*dep[z]+1,dd=dep[xx]+dep[yy]-2*dep[zz]+1;
		ri ans=0,l=1,r=min(d,dd);
		while(l<=r){
			ri mid=l+r>>1;
			if(getha1(x,y,z,mid)==getha1(xx,yy,zz,mid)&&getha2(x,y,z,mid)==getha2(xx,yy,zz,mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}