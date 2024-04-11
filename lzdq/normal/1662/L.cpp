#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,MAXS=7.5e6;
int n,m,a[MAXN],V;
ll b[MAXN],t[MAXN],at[MAXN];
int cntp,pt[MAXN];
int cnte,h[MAXS],to[MAXS*2],nx[MAXS*2],ind[MAXS];
inline void adde(int u,int v){
	if(!v) return ;
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	ind[v]++;
}
int p[MAXN];
inline bool cmp1(int x,int y){
	if(a[x]==a[y]) return t[x]>t[y];
	return a[x]<a[y];
}
inline bool cmp2(int x,int y){
	if(a[x]==a[y]) return t[x]>t[y];
	return a[x]>a[y];
}
int f[MAXS],ans;
void Dfs(int u){
	ind[u]=-1;
	if(u>1&&u<=n) f[u]++;
	ans=max(ans,f[u]);
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		f[v]=max(f[v],f[u]);
		if(!--ind[v]) Dfs(v);
	}
	return ;
}
int main(){
	scanf("%d%d",&n,&V);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		b[i+1]=1ll*t*V;
	}
	for(int i=1; i<=n; i++)
		scanf("%d",a+i+1);
	n++;
	for(int i=1; i<=n; i++)
		p[i]=i,at[i]=t[i]=b[i]+a[i];
	sort(at+1,at+n+1);
	m=unique(at+1,at+n+1)-at-1;
	sort(p+1,p+n+1,cmp1);
	cntp=n;
	for(int i=1; i<=n; i++){
		int w=lower_bound(at+1,at+m+1,t[p[i]])-at;
		for(int j=w; j<=m; j+=j&-j)
			adde(p[i],pt[j]);
		for(int j=w; j; j&=j-1){
			int u=++cntp;
			adde(u,pt[j]);
			adde(u,p[i]);
			pt[j]=u;
		}
	}
	memset(pt,0,sizeof(pt));
	for(int i=1; i<=n; i++)
		at[i]=t[i]=b[i]-a[i];
	sort(at+1,at+n+1);
	m=unique(at+1,at+n+1)-at-1;
	sort(p+1,p+n+1,cmp2);
	for(int i=1; i<=n; i++){
		int w=lower_bound(at+1,at+m+1,t[p[i]])-at;
		for(int j=w; j<=m; j+=j&-j)
			adde(p[i],pt[j]);
		for(int j=w; j; j&=j-1){
			int u=++cntp;
			adde(u,pt[j]);
			adde(u,p[i]);
			pt[j]=u;
		}
	}
	memset(f,0xc0,sizeof(f));
	f[1]=0;
	for(int i=1; i<=cntp; i++)
		if(!ind[i]) Dfs(i);
	printf("%d\n",ans);
	return 0;
}