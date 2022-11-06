#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll K=18;
vector<pair<ll,ll>> g[1<<K];ll n;  // K such that 2^K>=n
ll F[K][1<<K],D[1<<K],W[K][1<<K];
void lca_dfs(ll x){
	fore(i,0,g[x].size()){
		ll y=g[x][i].fst;if(y==F[0][x])continue;
		W[0][y]=g[x][i].snd;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;W[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	fore(k,1,K)fore(x,0,n)
		if(W[k-1][x]<0)W[k][x]=-1;
		else W[k][x]=max(W[k-1][x],W[k-1][F[k-1][x]]);
}
ll lca(ll x, ll y){
	ll res=-1;	
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])/*cout<<"aaaa",*/res=max(res,W[k][x]),x=F[k][x];
	if(x==y){/*cout<<"cccc";*/return res;}
	for(ll k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])/*cout<<"bbbb",*/res=max(res,max(W[k][x],W[k][y])),x=F[k][x],y=F[k][y];
	res=max(res,max(W[0][x],W[0][y]));
	return res;
}

const ll MAXN=200005;
ll uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

set<pair<ll,ll>> st;
vector<pair<ll,pair<ll,ll> > > es; // edges (cost,(u,v))
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		ll x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y)){r+=es[i].fst; g[x].pb({y,es[i].fst});g[y].pb({x,es[i].fst});st.insert({x,y});st.insert({y,x});} // (x,y,c) belongs to mst
	}
	return r; // total cost
}

vector<pair<ll,pair<ll,ll> > > ed;
int main(){FIN;
	ll m; cin>>n>>m;
	ll a,b,c;
	fore(i,0,m){
		cin>>a>>b>>c; a--; b--;
		ed.pb({c,{a,b}});
		es.pb({c,{a,b}});
		//g[a].pb({b,c});
		//g[b].pb({a,c});
	}
	ll k=kruskal();
	lca_init();
	fore(i,0,m){
		if(st.count(ed[i].snd)){
			cout<<k<<"\n";
		}else{
			cout<<k+ed[i].fst-lca(ed[i].snd.fst,ed[i].snd.snd)/*<<" "<<lca(ed[i].snd.fst,ed[i].snd.snd)*/<<"\n";
		}
	}
	//cout<<W[0][2];
	
	return 0;
}