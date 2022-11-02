// TCR
// Finds bridges and 2-edge connected components of graph
// Component of vertex x is c[x]
// Edge is bridge iff its endpoints are in different components
// Graph in form {adjacent vertex, edge id}
// Uses 1-indexing
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct Bridges {
	vector<int> c, h;
	void dfs(vector<pair<int, int> >* g, int x, int pe, int d, vector<int>& ns) {
		if (h[x]) return;
		h[x]=d;
		ns.push_back(x);
		for (auto nx:g[x]) {
			if (nx.S!=pe) {
				dfs(g, nx.F, nx.S, d+1, ns);
				h[x]=min(h[x], h[nx.F]);
			}
		}
		if (h[x]==d) {
			while (ns.size()>0) {
				int t=ns.back();
				c[t]=x;
				ns.pop_back();
				if (t==x) break;
			}
		}
	}
	Bridges(vector<pair<int, int> >* g, int n) : c(n+1), h(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) {
			dfs(g, i, -1, 1, ns);
		}
	}
};

vector<pair<int, int> > g[303030];
vector<int> gg[303030];
set<pair<int, int> > f;

void go(int x, int p, int d, int is){
    if (!is){
        if (f.count({x, x})) is=1;
    }
    if (x==d&&is){
        cout<<"YES\n";
        exit(0);
    }
    for (int nx:gg[x]){
        if (nx!=p){
            if (is){
                go(nx, x, d, 1);
            }
            else{
                if (f.count({x, nx})){
                    go(nx, x, d, 1);
                }
                else{
                    go(nx, x, d, 0);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int, int> > af;
    vector<pair<int, int> > es;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
        es.push_back({a, b});
        if (c==1){
            af.push_back({a, b});
        }
    }
    Bridges br(g, n);
    int a,b;
    cin>>a>>b;
    for (auto t:af){
        f.insert({br.c[t.F], br.c[t.S]});
        f.insert({br.c[t.S], br.c[t.F]});
    }
    for (auto e:es){
        if (br.c[e.F]!=br.c[e.S]){
            gg[br.c[e.F]].push_back(br.c[e.S]);
            gg[br.c[e.S]].push_back(br.c[e.F]);
        }
    }
    go(br.c[a], 0, br.c[b], 0);
    cout<<"NO\n";
}