// https://codeforces.com/problemset/problem/543/D

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

const ll MOD=1000000007;

// Esta es la parte especifica de este problema
struct Data {ll c;};
Data combine(const Data &a, const Data &b){
	Data ret;
	ret.c=a.c*b.c%MOD;
	return ret;
}
Data extend(const Data &a){
	Data ret;
	ret.c=(a.c+1)%MOD;
	return ret;
}
Data leaf(){
	Data ret;
	ret.c=1;
	return ret;
}
struct Edge{ll child;};
// Esto seria la tecnica de cambio de raiz general, independiente del problema
const int MAXN = 200005;
vector<Edge> g[MAXN];
Data res[MAXN]; // La respuesta tomando ese subarbol como raiz
Data subtree[MAXN]; // El clasico subarbol con raiz en el nodo
Data extendedSubtree[MAXN]; // El clasico + la arista al padre
Data parentSubtree[MAXN]; // El "complemento" en aristas del extended
Data extendedParentSubtree[MAXN]; // El "complemento" en aristas del subtree
void dfsSubtree(int node, int parent){
	subtree[node] = leaf();
	for (Edge e : g[node])
	if (e.child != parent){
		dfsSubtree(e.child, node);
		extendedSubtree[e.child] = extend(subtree[e.child]);
		subtree[node] = combine(extendedSubtree[e.child], subtree[node]);
	}
}
void dfsParentSubtree(int node, int parent){
	const int D = SZ(g[node]);
	vector<Data> prefixes(D+1),suffixes(D+1);
	#define EDGE g[node][i]
	#define ELEM (EDGE.child == parent ? extendedParentSubtree[node] : extendedSubtree[EDGE.child])
	prefixes[0] = leaf();
	fore(i, 0, D) prefixes[i+1] = combine(ELEM, prefixes[i]);
	suffixes[D] = leaf();
	for(int i=D-1;i>=0;i--)suffixes[i] = combine(ELEM, suffixes[i+1]);
	// En este punto, prefixes[D] == suffixes[0] == el valor con este nodo como raiz
	res[node] = prefixes[D];// Me guardo la respuesta si ese nodo es la raiz
	fore(i, 0, D)
	if (EDGE.child != parent){
		parentSubtree[EDGE.child] = combine(prefixes[i], suffixes[i+1]);
		extendedParentSubtree[EDGE.child] = extend(parentSubtree[EDGE.child]);
		dfsParentSubtree(EDGE.child, node);
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb({i});
		g[i].pb({p});
	}
	dfsSubtree(0,-1);
	dfsParentSubtree(0,-1);
	fore(i,0,n)cout<<res[i].c<<" ";
	cout<<"\n";
	return 0;
}