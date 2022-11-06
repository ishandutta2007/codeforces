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

const ll MAXN=200005,K=18;

ll spf[MAXN];

vector<ll> pr,a,ord;

ll ub[MAXN];

vector<int> g[1<<K];int n;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	ord.pb(x);
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

ll dist(ll x, ll y){
	return D[x]+D[y]-2*D[lca(x,y)];
}

vector<ll> oc[MAXN];

const ll MOD=998244353;

bool comp(ll x, ll y){
	return ub[x]<ub[y];
}

vector<pair<ll,ll>> vt[MAXN];

ll vis[MAXN],su[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:vt[x]){
		if(vis[i.fst])continue;
		dfs(i.fst);
		su[x]+=su[i.fst];
	}
}

ll tom3(ll n){
	return (n*(n-1)*(n-2)/6)%MOD;
}

ll solve(vector<ll> v){
	if(SZ(v)<=2)return 0;
	sort(ALL(v),comp);
	set<ll> st;
	for(auto i:v)st.insert(i);
	fore(i,1,SZ(v)){
		ll l=lca(v[i-1],v[i]);
		st.insert(l);
	}
	vector<ll> nv;
	for(auto i:st)nv.pb(i);
	sort(ALL(nv),comp);
	vector<ll> s={nv[0]};
	fore(i,1,SZ(nv)){
		while(SZ(s)&&lca(nv[i],s.back())!=s.back())s.pop_back();
		assert(SZ(s));
		ll x=nv[i],y=s.back();
		ll d=dist(x,y);
		vt[x].pb({y,d});
		vt[y].pb({x,d});
		s.pb(x);
	}
	for(auto i:v)su[i]=1;
	dfs(nv[0]);
	ll res=0;
	for(auto i:nv){
		for(auto j:vt[i]){
			if(D[j.fst]>D[i]){
				ll te=0;
				te=(te+tom3(SZ(v)))%MOD;
				te=(te+MOD-tom3(su[j.fst]))%MOD;
				te=(te+MOD-tom3(SZ(v)-su[j.fst]))%MOD;
				te=te*j.snd%MOD;
				res=(res+te)%MOD;
			}
		}
	}
	for(auto i:nv){
		vt[i].clear();
		vis[i]=0;
		su[i]=0;
	}
	return res;
}

int main(){FIN;
	mset(spf,-1);
	fore(i,2,MAXN){
		if(spf[i]!=-1)continue;
		pr.pb(i);
		for(ll j=i;j<MAXN;j+=i){
			if(spf[j]==-1)spf[j]=i;
		}
	}
	cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll x,y; cin>>x>>y; x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	lca_init();
	fore(i,0,n)ub[ord[i]]=i;
	fore(i,0,n){
		ll val=a[i];
		while(val>1){
			auto p=spf[val];
			if(spf[val/p]!=p)oc[p].pb(i);
			val/=p;
		}
	}
	ll res=0;
	for(auto i:pr){
		res=(res+solve(oc[i]))%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}