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

const int K=18;

vector<int> g[1<<K];ll n;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
ll s[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
		s[x]+=s[y];
	}
	s[x]++;
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)s[i]=0;
		lca_init();
		vector<ll> res(n+1);
		res[0]=n*(n-1)/2;
		res[1]=res[0];
		for(auto i:g[0]){
			res[1]-=s[i]*(s[i]-1)/2;
		}
		ll tot=1;
		for(auto i:g[0]){
			if(lca(i,1)!=i)tot+=s[i];
		}
		pair<ll,ll> cm={1,-1};
		fore(i,2,n+1){
			if(cm.snd==-1){
				res[i]=s[cm.fst]*tot;
			}else{
				res[i]=s[cm.fst]*s[cm.snd];
			}
			if(i==n)break;
			ll lc0=lca(cm.fst,i);
			ll lc1=-1;
			if(cm.snd!=-1)lc1=lca(cm.snd,i);
			if(lc0==cm.fst||lc0==i){
				cm.fst=lc0^cm.fst^i;
			}else if(cm.snd==-1){
				if(lc0==0)cm.snd=i;
				else break;
			}else if(lc1==cm.snd||lc1==i){
				cm.snd=lc1^cm.snd^i;
			}else{
				break;
			}
		}
		fore(i,0,n)res[i]-=res[i+1];
		fore(i,0,n+1)cout<<res[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}