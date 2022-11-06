#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll K=20;
vector<int> g[1<<K];int n;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

bool cmp(ll i, ll j){
	return D[i]<D[j];
}

int main(){FIN;
	ll m; cin>>n>>m;
	ll u,v;
	fore(i,0,n-1){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init();
	fore(i,0,m){
		ll k; cin>>k;
		vector<ll> v;
		fore(j,0,k){
			ll lle; cin>>lle;
			if(lle!=1)v.pb(lle-1);
		}
		fore(j,0,SZ(v))v[j]=F[0][v[j]];
		sort(ALL(v),cmp);
		ll br=0;
		fore(i,0,SZ(v)-1){
			if(lca(v[i],v[i+1])!=v[i]){
				cout<<"NO\n";/*<<v[i]<<" "<<v[i+1]<<"\n";*/ br++; break;
			}
		}
		if(br)continue;
		cout<<"YES\n";
	}
	
	return 0;
}