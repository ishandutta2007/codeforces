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

class tsort {
public:
	int V;
	vector<vector<int> > G;
	vector<int> deg,res;
	tsort(int node_size) : V(node_size), G(V), deg(V, 0){}
	void add_edge(int from,int to){
		G[from].push_back(to);
		deg[to]++;
	}
	bool solve() {
		queue<int> que;
		for(int i = 0; i < V; i++){
			if(deg[i] == 0){
				que.push(i);
			}
		}
		while(!que.empty()){
			int p = que.front();
			que.pop();
			res.push_back(p);
			for(int v : G[p]){
				if(--deg[v] == 0){
					que.push(v);
				}
			}
		}
		return (*max_element(deg.begin(),deg.end()) == 0);
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        tsort ts(n);
        rep(i,m){
            int a,b;
            cin >> a >> b;
            a--;b--;
            ts.add_edge(a,b);
        }
        ts.solve();
        auto& res = ts.res;
        auto& g = ts.G;
        vector<int> p(n);
        rep(i,n){
            int id = res[i];
            if(p[id]>=2)continue;
            for(auto x:g[id]){
                chmax(p[x],p[id]+1);
            }
        }
        vector<int> ans;
        rep(i,n){
            if(p[i]>=2)ans.push_back(i);
        }
        cout << ans.size() << "\n";
        for(auto x:ans){
            cout << x+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}