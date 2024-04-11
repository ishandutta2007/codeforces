#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
typedef vector<vector<int>> Graph;
typedef pair<int, int>      Edge;   // (a < b: )

class BICC {
private:
    const int n;

    /***  ***/
    Graph G;
    vi depth;
    vi par;
    map<Edge, int> imosEdge;
    map<Edge, int> EdgeType;
    enum {UNUSED, USED_DFS, BRIDGE};
    vector<Edge> bridges;
public:
    /***  ***/
	vi cmp;                // cmp[i] =  i 
	int num_cc;            // 
	vi size_of_vertex;     // 
	Graph G_cc;            //  (!!!!!!)

    BICC(int _n) : n(_n), G(_n), depth(_n, -1), par(_n, -1), cmp(_n, -1), num_cc(0) {}
    Edge getEdge(int a, int b) {
        if (a > b) swap(a, b);
        return Edge(a, b);
    }
    void updateEdgeType(int a, int b, int type) {
        if (a < 0 || b < 0) return;			// dfs-1
        EdgeType[getEdge(a, b)] = type;
    }
    void addEdge(int a, int b) {
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        updateEdgeType(a, b, UNUSED);
    }
    void dfsTreeConstruct(int v, int pre) {
        if (depth[v] != -1) return;
        depth[v] = (pre == -1 ? 0 : depth[pre] + 1);
        par[v] = pre;
        updateEdgeType(pre, v, USED_DFS);
        for (auto&& nxt : G[v]) {
            if (nxt != pre) dfsTreeConstruct(nxt, v);
        }
    }
    void updateImos(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        // depth[a] > depth[b]: DFS a->b 
        if (par[a] != -1) {
            imosEdge[getEdge(a, par[a])]++;
        }
        if (par[b] != -1) {
            imosEdge[getEdge(b, par[b])]--;
        }
    }
    int imosFinal(int v, int pre) {
        int t = 0;
        for (auto&& nxt : G[v]) {
            if (nxt != pre && EdgeType[getEdge(nxt, v)] == USED_DFS) {
                t += imosFinal(nxt, v);
            }
        }
        if (pre != -1) imosEdge[getEdge(v, pre)] += t;
        return pre == -1 ? 0 : imosEdge[getEdge(v, pre)];
    }
    // 1
    int extractCC(int v, int color) {
    	if (cmp[v] != -1) return 0;
    	cmp[v] = color;
    	int t = 1;
    	for (auto&& nxt : G[v]) {
    		if (EdgeType[getEdge(v, nxt)] != BRIDGE) {
    			t += extractCC(nxt, color);
    		}
    	}
    	return t;
    }
    void bicc() {
        /***		***/
        dfsTreeConstruct(0, -1);
        for (auto&& p : EdgeType) {
            Edge e;
            int type;
            tie(e, type) = p;
            if (type == UNUSED) {
                updateImos(e.first, e.second);
            }
        }
        imosFinal(0, -1);
        for (auto&& p : EdgeType) {
            Edge e;
            int type;
            tie(e, type) = p;
            if (type == USED_DFS) {
                if (imosEdge[e] == 0) {
                    EdgeType[e] = BRIDGE;
                    bridges.emplace_back(e);
                }
            }
        }

    	/***		***/
		rep(i, n) {
			int size_cc = extractCC(i, num_cc);
			if (size_cc > 0) {
				size_of_vertex.emplace_back(size_cc);
				num_cc++;
			}
		}
	
		// cerr << "num_cc = " << num_cc << endl;
		// cerr << "cmp: "; printV(cmp);
		// cerr << "size_of_vertex: "; printV(size_of_vertex);
	
	 	vector<set<int>> G_cc_st(num_cc);	// set
		for (auto&& p : EdgeType) {
			Edge e;
			int type;
			tie(e, type) = p;
			if (type == BRIDGE) {
			    // cerr << e.first << " " << e.second << " " << imosEdge[e] << endl;
				G_cc_st[cmp[e.first]].insert(cmp[e.second]);
				G_cc_st[cmp[e.second]].insert(cmp[e.first]);
		    }
		}
	
		rep(i, num_cc) {
			G_cc.emplace_back(vector<int>(all(G_cc_st[i])));
		}
	
		// cerr << "---BICC---" << endl;
		// rep(i, num_cc) {
		// 	cerr << i << ": "; printV(G_cc[i]);
		// }
    }
};

class TreeDiameter
{
public:
    vector<vector<int> > G;
    vector<int> diameter;
    int V;
    TreeDiameter(int node_size){
        V = node_size;
        G.resize(V);
    }
    void add_edge(int u,int v){
        G[u].push_back(v),G[v].push_back(u);
    }
    void dfs(int u,int p,int d,int& far,int& mx){
        if(mx < d){
            far = u;
            mx = d;
        }
        for(int v : G[u]){
            if(v != p){
                dfs(v,u,d+1,far,mx);
            }
        }
    }
    bool redfs(int u,int p,const int t){
        if(u == t){
            return true;
        }
        for(int v : G[u]){
            if(v != p){
                diameter.push_back(v);
                if(redfs(v,u,t)){
                    return true;
                }else{
                    diameter.pop_back();
                }
            }
        }
        return false;
    }
    void solve(){
        int s,t,mx;
        mx = -1;
        dfs(0,-1,0,s,mx);
        mx = -1;
        dfs(s,-1,0,t,mx);
        diameter.push_back(s);
        redfs(s,-1,t);
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    BICC bicc(n);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        bicc.addEdge(a,b);
    }
    bicc.bicc();
    TreeDiameter tr(bicc.num_cc);
    for(int i=0;i<bicc.G_cc.size();i++){
        for(int j=0;j<bicc.G_cc[i].size();j++){
            if(i<bicc.G_cc[i][j]){
                tr.add_edge(i,bicc.G_cc[i][j]);
            }
        }
    }
    tr.solve();
    int ans = tr.diameter.size();
    cout << ans-1 << endl;
    return 0;
}