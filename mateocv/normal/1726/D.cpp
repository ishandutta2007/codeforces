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

const int MAXN=200005;
int pa[MAXN],sz[MAXN];
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

vector<ll> g[MAXN];

ll vis[MAXN],p[MAXN],de[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(vis[i])continue;
		p[i]=x;
		de[i]=de[x]+1;
		dfs(i);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<pair<ll,ll>> ed(m);
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--; y--;
			if(x>y)swap(x,y);
			ed[i]={x,y};
		}
		dsu_init(n);
		fore(i,0,n)g[i].clear();
		vector<ll> sob;
		fore(i,0,m){
			auto x=ed[i].fst,y=ed[i].snd;
			if(find_pa(x)!=find_pa(y)){
				join(x,y);
				g[x].pb(y);
				g[y].pb(x);
			}else{
				sob.pb(i);
			}
		}
		set<ll> sd;
		for(auto i:sob)sd.insert(ed[i].fst),sd.insert(ed[i].snd);
		if(SZ(sob)<3||SZ(sd)!=3){
			vector<ll> res(m,1);
			for(auto i:sob)res[i]=0;
			for(auto i:res)cout<<i;
			cout<<"\n";
		}else{
			fore(i,0,n)vis[i]=0,p[i]=-1,de[i]=0;
			dfs(0);
			ll x=ed[sob[0]].fst,y=ed[sob[0]].snd;
			if(de[x]<de[y])swap(x,y);
			ll pos=-1;
			pair<ll,ll> par={x,p[x]};
			if(par.fst>par.snd)swap(par.fst,par.snd);
			fore(i,0,m){
				if(par==ed[i])pos=i;
			}
			assert(pos!=-1);
			vector<ll> res(m,1);
			fore(i,1,SZ(sob))res[sob[i]]=0;
			res[pos]=0;
			for(auto i:res)cout<<i;
			cout<<"\n";
		}
	}
	
	return 0;
}