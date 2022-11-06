#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pii pair<ll,ll>
#define piii pair<ll,pair<ll,ll> >
using namespace std;
typedef long long ll;//cambiar todos los int por ll
ll n;
/*---------------- Union Find (DSU) ------------------*/
/* Sets up array parent where parent[i] is a member of its
	disjoint set. See DSU file for an example*/
const ll N=3e5+15;
ll pa[N],sz[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(ll a, ll b) {
	ll x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(){fore(i,0,n)pa[i]=i,sz[i]=1;}

/*--------------------- MST KRUSKAL --------------------*/
#define F first
#define S second
//const ll N=2e5+3;
//ll pa[N],sz[N];
vector<pii>mst;
priority_queue<piii,vector<piii>,greater<piii>> edges;
// RETOQUE PENDIENTE CONFIRMAR
ll kruskal (ll v) {
	ll sum=0;
	fore(i,0,v) pa[i]=i,sz[i]=1;
	while (!edges.empty()) {
		piii t=edges.top();edges.pop();
		ll comp_x=find_pa(t.S.F);
		ll comp_y=find_pa(t.S.S);
		if (comp_x != comp_y) {
			mst.push_back(t.S);
			join(comp_x,comp_y);
			sum += t.F;
		}
	}
	return sum;
}

int main(){FIN;
	ll m; cin>>n>>m;
	pair<ll,ll> ar[n];
	fore(i,0,n){
		cin>>ar[i].fst;
		ar[i].snd=i;
	}
//	dsu_init();
//	vector<piii> v;
	ll a,b,c;
	fore(i,0,m){
		cin>>a>>b>>c; a--; b--;
		edges.push({c,{a,b}});
	}
	sort(ar,ar+n);
	fore(i,1,n){
		edges.push({ar[0].fst+ar[i].fst,{ar[0].snd,ar[i].snd}});
	}
	cout<<kruskal(n);
	
	
	return 0;
}