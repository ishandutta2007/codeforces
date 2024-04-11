#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
#define int long long
vector<bool> flag;
int k;
class centroid {
public:
	int V;
	vector<vector<int> > G;
	vector<int> sz;
	void dfs(int u,int p, vector<int>& ct){
		bool ok = true;
		sz[u] = flag[u];
		for(int v : G[u]){
			if(v != p){
				dfs(v, u, ct);
				sz[u] += sz[v];
				if(2*sz[v] > V) ok = false;
			}
		}
		if(ok && k <= 2*sz[u]) ct.push_back(u);
	}

public:
	centroid(int node_size) : V(node_size), G(V), sz(V, 0){}
	void add_edge(int u,int v){
		G[u].push_back(v), G[v].push_back(u);
	}
	vector<int> solve(){
		vector<int> ct;
		dfs(0, -1, ct);
		return ct;
	}
};
vector<vector<int> > g;
pair<int,int> dfs(int id,int pre){
    pair<int,int> p = MP(0,0);
    for(auto x:g[id]){
        if(x==pre)continue;
        auto y = dfs(x,id);
        p.first += y.first+y.second;
        p.second += y.second;
    }
    if(flag[id])p.second++;
    return p;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    k *= 2;
    centroid c(n);
    flag.resize(n);
    rep(i,k){
        int a;
        cin >> a;
        flag[a-1] = 1;
    }
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        c.add_edge(a-1,b-1);
    }
    vector<int> res = c.solve();
    int id = res[0];
    g = c.G;
    auto x = dfs(id,-1);
    cout << x.first << endl;
    return 0;
}