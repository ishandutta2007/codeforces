#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

const int maxn=4e5; 
const ll mod=998244353; 
int n,a[maxn+5];
int flag[maxn+5],p[maxn+5],cnt,id[maxn+5],dfn[maxn+5],tot,siz[maxn+5]; 
vector<int> pos[maxn+5]; 
int fa[maxn+5][20],dep[maxn+5]; 
vector<int> g[maxn+5]; 

void prework() {
	for (int i=2;i<=maxn;i++) {
		if (!flag[i]) {
			p[++cnt]=i;
			id[p[cnt]]=cnt; 
		}
		for (int j=1;j<=cnt&&i*p[j]<=maxn;j++) {
			flag[i*p[j]]=1;
			if (i%p[j]==0) break ; 
		}
	}
}
void dfs(int u,int pre) {
	dfn[u]=++tot; 
	for (auto v:g[u]) {
		if (v==pre) continue ; 
		dep[v]=dep[u]+1; 
		dfs(v,u);
		fa[v][0]=u; 
	}
} 
int key[maxn+5],Fa[maxn+5]; 
int LCA(int u,int v) {
	if (dep[u]<dep[v]) swap(u,v);
	for (int j=19;j>=0;j--) {
		if (fa[u][j] && dep[fa[u][j]]>=dep[v]) u=fa[u][j]; 
	}
	if (u==v) return u;
	for (int j=19;j>=0;j--) {
		if (fa[u][j]!=fa[v][j]) {
			u=fa[u][j],v=fa[v][j]; 
		} 
	}
	return fa[u][0]; 
}
int main() {
	scanf("%d",&n);
	prework(); 
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]); 
		for (int j=1;j<=cnt&&p[j]*p[j]<=a[i];j++) {
			if (a[i]%p[j]==0) {
				pos[j].push_back(i);
				while (a[i]%p[j]==0) a[i]/=p[j];
			}
		}
		if (a[i]>1) {
			pos[id[a[i]]].push_back(i);
		}
	} 
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	dfs(1,0); 
	for (int j=1;(1<<j)<=n;j++) {
		for (int i=1;i<=n;i++) {
			fa[i][j]=fa[fa[i][j-1]][j-1]; 
		}
	}
	ll ans=0; 
	for (int i=1;i<=cnt;i++) {
		if (pos[i].size()<3) continue ; 
		int all=pos[i].size(); 
		tot=0; 
		for (auto x:pos[i]) {
			key[++tot]=x;  
		}
		sort(key+1,key+tot+1,[&](int x,int y){
			return dfn[x]<dfn[y]; 
		}); 
		for (int i=1;i<tot;i++) {
			key[tot+i]=LCA(key[i],key[i+1]); 
		}
		tot=2*tot-1; 
		sort(key+1,key+tot+1,[&](int x,int y){
			return dfn[x]==dfn[y]?x<y:dfn[x]<dfn[y]; 
		});
		tot=unique(key+1,key+tot+1)-key-1;
		for (int i=1;i<=tot;i++) {
			siz[key[i]]=0;
		}
		for (auto x:pos[i]) siz[x]=1;
		for (int i=tot;i>=2;i--) {
			Fa[key[i]]=LCA(key[i],key[i-1]); 
			siz[Fa[key[i]]]+=siz[key[i]]; 
		}ll P=0; 
		for (int i=2;i<=tot;i++) {
			int bian=dep[key[i]]-dep[Fa[key[i]]]; 
			ans+=1ll*bian*(all-2)%mod*(all-siz[key[i]])%mod*siz[key[i]]%mod;
			P+=1ll*bian*(all-siz[key[i]])%mod*siz[key[i]]%mod;
			ans%=mod;  
		}
//		cout<<i<<' '<<P<<'\n'; 
	}
	ll inv2=(mod+1)/2; 
	printf("%lld\n",1ll*ans*inv2%mod); 
	return 0;
}