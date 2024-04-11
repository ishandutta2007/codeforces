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

ll n,m;

vector<ll> g[5050];

ll vis[5050];

ll c[5050];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			c[i]=(c[v]+1)%2;
			dfs(i);
		}else{
			if(c[i]==c[v]){
				cout<<"NO";
				exit(0);
			}
		}
	}
}

/*---------------- Union Find (DSU) ------------------*/
const ll N=5050;
int pa[N],sz[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

ll dp[5050][5050];

pair<ll,ll> p[5050];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(x==n){
		return r=(y==0);
	}
	r=0;
	if(p[x].fst<=y){
		r=max(r,f(x+1,y-p[x].fst));
	}
	if(p[x].snd<=y){
		r=max(r,f(x+1,y-p[x].snd));
	}
	return r;
}

int main(){FIN;
	cin>>n>>m;
	ll cant[3];
	fore(i,0,3)cin>>cant[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)dfs(i);
	dsu_init(n);
	fore(i,0,n){
		for(auto j:g[i]){
			join(i,j);
		}
	}
	fore(i,0,n){
		if(c[i]){
			p[find_pa(i)].snd++;
		}else{
			p[find_pa(i)].fst++;
		}
	}
	mset(dp,-1);
	if(!f(0,cant[1])){
		cout<<"NO";
		return 0;
	}
	set<ll> cm;
	ll y=cant[1];
	fore(i,0,n){
		if(p[i].fst<=y&&f(i+1,y-p[i].fst)==1){
			y-=p[i].fst;
		}else{
			y-=p[i].snd;
			cm.insert(i);
		}
	}
	vector<ll> par[2];
	fore(i,0,n){
		if(c[i]){
			if(cm.count(find_pa(i)))par[0].pb(i);
			else par[1].pb(i);
		}else{
			if(cm.count(find_pa(i)))par[1].pb(i);
			else par[0].pb(i);
		}
	}
	ll res[n];
	mset(res,0);
	for(auto i:par[0])res[i]=2;
	fore(i,0,SZ(par[1])){
		if(i<cant[0])res[par[1][i]]=1;
		else res[par[1][i]]=3;
	}
	cout<<"YES\n";
	fore(i,0,n)cout<<res[i];
	
	return 0;
}