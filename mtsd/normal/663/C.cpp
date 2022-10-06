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
class TwoSAT {
private:
	const int V;
	vector<vector<int> > G, rG;
	vector<int> ps, cmp;
	void add_edge(int from, int to){
		G[from].push_back(to), rG[to].push_back(from);
	}
	void dfs(int u){
        cmp[u] = 0;
        for(int v : G[u]){
			if(cmp[v] == -1) dfs(v);
		}
		ps.push_back(u);
	}
	void rdfs(int u, int k){
		cmp[u] = k;
		for(int v : rG[u]){
			if(cmp[v] == -1) rdfs(v, k);
		}
	}
	int scc(){
		for(int i = 0; i < 2 * V; ++i){
			if(cmp[i] == -1) dfs(i);
		}
		fill(cmp.begin(), cmp.end(), -1);
		int k = 0;
		for(int i = 2 * V - 1; i >= 0; --i){
			if(cmp[ps[i]] == -1) rdfs(ps[i], k++);
		}
		return k;
	}
 
public:
	vector<int> ans;
	TwoSAT(const int literal_count)
	 	: V(literal_count), G(2 * V), rG(2 * V), cmp(2 * V, -1), ans(V){}
	void add_closure(int x, int y){
		add_edge((x + V) % (2 * V), y), add_edge((y + V) % (2 * V), x);
	}
	// 
	//  1, 0  ans ()
	bool satisfy(){
		scc();
		for(int i = 0; i < V; i++){
			if(cmp[i] == cmp[V + i]) return false;
			ans[i] = (cmp[i] > cmp[V + i]);
		}
		return true;
	}
};

class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<pair<int,int>,int> > p;
    rep(i,m){
        int a,b,cc;
        char c;
        cin >> a >> b >> c;
        a--;b--;
        uf.unite(a,b);
        if(c=='R'){
            cc = 0;
        }else{
            cc = 1;
        }
        p.push_back(MP(MP(a,b),cc));
    }
    vector<int> cnt(n);
    rep(i,n){
        cnt[uf.find(i)]++;
    }
    
    vector<int> res;
    bool f = 0;
    rep(i,2){
        TwoSAT sat(n);
        for(auto x:p){
            int a = x.first.first;
            int b = x.first.second;
            if(x.second==i){
                sat.add_closure(a,b);
                sat.add_closure(a+n,b+n);
            }else{
                sat.add_closure(a,b+n);
                sat.add_closure(a+n,b);
            }
        }
        if(sat.satisfy()){
            set<int> ttmp;
            vector<int> sss(n);
            vector<int> tmp;
            rep(j,n){
                if(sat.ans[j]){
                    ttmp.insert(j);
                    sss[uf.find(j)]++;
                }
            }
            rep(j,n){
                if(sss[uf.find(j)]  >= (cnt[uf.find(j)]+1)/2){
                    if(ttmp.count(j)){
                        
                    }else{
                        tmp.push_back(j);
                    }
                }else{
                    if(ttmp.count(j)){
                        tmp.push_back(j);
                    }else{
                        
                    }
                }
            }
            if(f){
                if(res.size() > tmp.size()){
                    res = tmp;
                }
            }else{
                f = 1;
                res = tmp;
            }
        }
    }
    if(!f){
        cout << -1 << "\n";
    }else{
        cout << res.size() << "\n";
        for(auto x:res){
            cout << x+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}