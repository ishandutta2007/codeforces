#include<cstdio>
const int N=200002,M=1000000007;
typedef long long ll;
int n,i,j,k,a,b,h[N],t[N],v[N],fa[N],o[N];
ll f[N],g[N],ans[N],pref[N],nxtf[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d",&n);
	for(b=2;b<=n;b++){
		scanf("%d",&a);
		fa[b]=a;
		add(a,b);
	}
}
void dfs1(int i){
	f[i]=1;
	for(int j=h[i];j;j=t[j]){
		dfs1(v[j]);
		f[i]=f[i]*(f[v[j]]+1)%M;
	}
}
ll ksm(ll x,int b){
	ll s=1;
	while(b){
		if(b&1)
			s=s*x%M;
		b>>=1;
		x=x*x%M;
	}
	return s;
}
void dfs2(int i){
	f[i]=f[i]*(g[fa[i]]+1)%M;
	ll Pre=1,Nxt=1;
	k=0;
	for(int j=h[i];j;j=t[j])
		o[++k]=v[j];
	for(int j=1;j<=k;j++){
		pref[o[j]]=Pre;
		Pre=Pre*(f[o[j]]+1)%M;
	}
	for(int j=k;j;j--){
		nxtf[o[j]]=Nxt;
		Nxt=Nxt*(f[o[j]]+1)%M;
	}
	for(int j=h[i];j;j=t[j]){
		g[i]=(g[fa[i]]+1)*pref[v[j]]%M*nxtf[v[j]]%M;
		dfs2(v[j]);
	}
}
int main(){
	init();
	dfs1(1);
	dfs2(1);
	for(i=1;i<=n;i++)
		printf("%lld ",f[i]);
	//while(1);
	return 0;
}