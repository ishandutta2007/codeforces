#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,MAXS=1e7,mod=998244353,G=3,invG=(mod+1)/3;
int n;
ll m;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[MAXN],siz[MAXN],son[MAXN];
void Dfs1(int u){
	siz[u]=1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs1(v);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
	return ;
}
int top[MAXN],seg[MAXN],rev[MAXN],ed[MAXN];
int buf[MAXN],g[MAXN];
int tmp[MAXS],*ans[MAXN<<2],*mul[MAXN<<2],*pt,len[MAXN<<2];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void ntt(int *a,int n,int tp){
	int bit=0;
	while(1<<bit<n) bit++;
	static int rev[MAXN<<2];
	for(int i=1; i<n; i++){
		rev[i]=rev[i>>1]>>1|((i&1)<<bit-1);
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int mid=1; mid<n; mid<<=1){
		ll w=1,w1=Fstpw(tp==1?G:invG,(mod-1)/mid/2);
		for(int j=0; j<mid; j++,w=w*w1%mod)
			for(int i=0; i<n; i+=mid*2){
				int x=a[i+j],y=w*a[i+j+mid]%mod;
				a[i+j]=(x+y)%mod;
				a[i+j+mid]=(x-y+mod)%mod;
			}
	}
	if(tp==-1){
		ll t=Fstpw(n,mod-2);
		for(int i=0; i<n; i++)
			a[i]=a[i]*t%mod;
	}
	return ;
}
int* NTT(int *a,int n,int *b,int m,int *res){
	int siz=1;
	while(siz<=n+m) siz<<=1;
	static int f[MAXN<<2],g[MAXN<<2];
	for(int i=0; i<siz; i++){
		f[i]=i<=n?a[i]:0;
		g[i]=i<=m?b[i]:0;
	}
	ntt(f,siz,1);
	ntt(g,siz,1);
	for(int i=0; i<siz; i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,siz,-1);
	int k=n+m;
	for(int i=0; i<=k; i++)
		res[i]=f[i];
	return res+k+1;
}
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
void Dfs3(int k,int l,int r){
	if(l==r){
		int u=rev[l];
		if(g[u]){
			len[k]=siz[g[u]]+1;
			ans[k]=pt;
			ans[k][0]=0;
			ans[k][1]=1;
			for(int i=2; i<=len[k]; i++)
				ans[k][i]=buf[seg[g[u]]+i-2];
			pt+=len[k]+1;
			mul[k]=pt;
			memcpy(mul[k],ans[k],len[k]+1<<2);
			pt+=len[k]+1;
		}else{
			len[k]=1;
			ans[k]=pt;
			ans[k][0]=0;
			ans[k][1]=1;
			pt+=2;
			mul[k]=pt;
			mul[k][0]=0;
			mul[k][1]=1;
			pt+=2;
		}
		/*
		printf("Dfs3 %d\n",u);
		for(int i=0; i<=len[k]; i++) printf("%d ",ans[k][i]);puts("");
		for(int i=0; i<=len[k]; i++) printf("%d ",mul[k][i]);puts("");
		*/
		return ;
	}
	int mid=l+r>>1;
	Dfs3(ls);
	Dfs3(rs);
	len[k]=len[lc]+len[rc];
	mul[k]=pt;
	pt=NTT(mul[lc],len[lc],mul[rc],len[rc],mul[k]);
	ans[k]=pt;
	pt=NTT(ans[rc],len[rc],mul[lc],len[lc],ans[k]);
	for(int i=0; i<=len[lc]; i++)
		ans[k][i]=(ans[k][i]+ans[lc][i])%mod;
	/*
	printf("k %d\n",k);
	for(int i=0; i<=len[k]; i++) printf("%d ",ans[k][i]);puts("");
	for(int i=0; i<=len[k]; i++) printf("%d ",mul[k][i]);puts("");
	*/
	return ;
}
void Dfs2(int u){
	//printf("Dfs2 %d\n",u);
	seg[u]=++*seg;
	rev[*seg]=u;
	g[u]=0;
	if(son[u]){
		top[son[u]]=top[u];
		Dfs2(son[u]);
	}else ed[top[u]]=u;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]||v==son[u]) continue;
		top[v]=v;
		Dfs2(v);
		g[u]=v;
	}
	if(top[u]==u){
		pt=tmp;
		Dfs3(1,seg[u],seg[ed[u]]);
		memcpy(buf+seg[u],ans[1]+1,siz[u]<<2);
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%lld",&n,&m);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	Dfs1(1);
	top[1]=1;
	Dfs2(1);
	int ans=0;
	ll t=1;
	for(int i=1; i<=n; i++){
		ans=(ans+t*buf[i])%mod;
		t=(m+i)%mod*t%mod*Fstpw(i,mod-2)%mod;
	}
	printf("%d\n",ans);
	return 0;
}