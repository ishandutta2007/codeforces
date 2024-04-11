#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1<<20,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
inline int qpow(int x,int y){
	int ret=1;
	for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)ret=1ll*ret*x%mod;
	return ret;
}
int all,ans,cnt,f[maxn],fa[maxn],g[maxn],id[20],mid,n,p[6][6];
void dfs1(int now,int lim,int pro){
	ri x=now/n,y=now%n;
	if(x>=lim){
		ri mask=0;
		for(ri i=0;i<cnt;++i){
			for(ri j=id[i];j;j=(j-1)&id[i]){
				ri k=0,l=j;
				while(l){
					ri m=__lg(l);
					k|=fa[m];
					l^=1<<m;
				}
				if(__builtin_popcount(k)<__builtin_popcount(j))goto skip;
			}
			mask|=1<<i;
			skip:;
		}
		if((f[mask]+=pro)>=mod)f[mask]-=mod;
		return;
	}
	dfs1(now+1,lim,1ll*pro*(1+mod-p[x][y])%mod);
	fa[y]|=1<<x;
	dfs1(now+1,lim,1ll*pro*p[x][y]%mod);
	fa[y]^=1<<x;
}
void dfs2(int now,int lim,int pro){
	ri x=now/n,y=now%n;
	if(x>=lim){
		ri mask=0;
		for(ri i=0;i<cnt;++i){
			for(ri j=id[i];j;j=(j-1)&id[i]){
				ri k=0,l=j;
				while(l){
					ri m=__lg(l);
					k|=fa[m];
					l^=1<<m;
				}
				if(__builtin_popcount(k)<__builtin_popcount(j))goto skip;
			}
			mask|=1<<i;
			skip:;
		}
		if((g[mask]+=pro)>=mod)g[mask]-=mod;
		return;
	}
	dfs2(now+1,lim,1ll*pro*(1+mod-p[x][y])%mod);
	fa[y]|=1<<x;
	dfs2(now+1,lim,1ll*pro*p[x][y]%mod);
	fa[y]^=1<<x;
}
inline void fwt_and(int *f){
	for(ri k=1,kk=2;kk<=1<<cnt;k<<=1,kk<<=1)
		for(ri i=0;i<1<<cnt;i+=kk)
			for(ri j=0;j<k;++j)
				if((f[i|j]+=f[i|j|k])>=mod)
					f[i|j]-=mod;
}
inline void ifwt_and(int *f){
	for(ri k=1,kk=2;kk<=1<<cnt;k<<=1,kk<<=1)
		for(ri i=0;i<1<<cnt;i+=kk)
			for(ri j=0;j<k;++j)
				if((f[i|j]-=f[i|j|k])<0)
					f[i|j]+=mod;
}
int main(){
	scanf("%d",&n);
	for(ri i=0,inv=qpow(100,mod-2);i<n;++i)
		for(ri j=0,x;j<n;++j)
			scanf("%d",&x),p[i][j]=1ll*x*inv%mod;
	all=(1<<n)-1,mid=n>>1;
	for(ri i=0;i<=all;++i)
		if(__builtin_popcount(i)==mid)
			id[cnt++]=i;
	dfs1(0,mid,1);
	for(ri i=0;i<cnt;++i)id[i]^=all;
	dfs2(mid*n,n,1);
	fwt_and(f),fwt_and(g);
	for(ri i=0;i<1<<cnt;++i)f[i]=1ll*f[i]*g[i]%mod;
	ifwt_and(f);
	if((ans=1+mod-f[0])>=mod)ans-=mod;
	printf("%d",ans);
	return 0;
}