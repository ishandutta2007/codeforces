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

vector<ll> g[N];
ll tot[N];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll u,v;
	dsu_init(n);
	fore(i,0,m){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		join(u,v);
	}
	fore(i,0,n){
		if(SZ(g[i])==2){
			tot[find_pa(i)]++;
		}
	}
	ll res=0;
	fore(i,0,n){
		if(find_pa(i)==i&&tot[i]==sz[i])res++;
	}
	cout<<res;
	return 0;
}