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

vector<pair<ll,ll>> ed;
vector<pair<ll,ll>> edb;
vector<ll> g[200005];
ll vis[200005];

/*---------------- Union Find (DSU) ------------------*/
const ll N=3e5+10;
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

ll c[200005],tot=0;

void bfs() {
	queue<int>q;
	vis[0]=1;
	q.push(0);
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]){
			if(!vis[i]){
				vis[i]=1;
				q.push(i);
				if(c[t]==0)c[i]=1,tot++;
			}
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll u,v;
		fore(i,0,m){
			cin>>u>>v; u--; v--;
			ed.pb({u,v});
		}
		dsu_init(n);
		while(SZ(ed)){
			pair<ll,ll> b=ed.back();
			ed.pop_back();
			if(find_pa(b.fst)!=find_pa(b.snd)){
				join(b.fst,b.snd);
				edb.pb(b);
			}
		}
		fore(i,0,SZ(edb)){
			g[edb[i].fst].pb(edb[i].snd);
			g[edb[i].snd].pb(edb[i].fst);
		}
		bfs();
		if(tot<=n/2){
			cout<<tot<<"\n";
			fore(i,0,n){
				if(c[i])cout<<i+1<<" ";
			}
			cout<<"\n";
		}else{
			cout<<n-tot<<"\n";
			fore(i,0,n){
				if(!c[i])cout<<i+1<<" ";
			}
			cout<<"\n";
		}
		edb.clear();
		fore(i,0,n)g[i].clear();
		fore(i,0,n)vis[i]=0;
		fore(i,0,n)c[i]=0;
		tot=0;
	}
	
	return 0;
}