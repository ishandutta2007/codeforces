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


long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

#define MOD 998244353
// matrix
struct Matrix {
    vector<vector<long long> > val;
    Matrix(int n, int m, long long x = 0) : val(n, vector<long long>(m, x)) {}
    void init(int n, int m, long long x = 0) {val.assign(n, vector<long long>(m, x));}
    size_t size() const {return val.size();}
    inline vector<long long>& operator [] (int i) {return val[i];}
};

int GaussJordan(Matrix &A, bool is_extended = false) {
    int m = A.size(), n = A[0].size();
    for (int row = 0; row < m; ++row)
        for (int col = 0; col < n; ++col)
            A[row][col] = (A[row][col] % MOD + MOD) % MOD;
    
    int rank = 0;
    for (int col = 0; col < n; ++col) {
        if (is_extended && col == n-1) break;
        int pivot = -1;
        for (int row = rank; row < m; ++row) {
            if (A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        auto inv = modinv(A[rank][col], MOD);
        for (int col2 = 0; col2 < n; ++col2)
            A[rank][col2] = A[rank][col2] * inv % MOD;
        for (int row = 0; row < m; ++row) {
            if (row != rank && A[row][col]) {
                auto fac = A[row][col];
                for (int col2 = 0; col2 < n; ++col2) {
                    A[row][col2] -= A[rank][col2] * fac % MOD;
                    if (A[row][col2] < 0) A[row][col2] += MOD;
                }
            }
        }
        ++rank;
    }
    return rank;
}

int linear_equation(Matrix A, vector<long long> b, vector<long long> &res) {
    int m = A.size(), n = A[0].size();
    Matrix M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;
    
    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
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
    auto& g = ts.G;
    auto& A = ts.res;
    vector<int> p(n);
    for(int i=n-1;i>=0;i--){
        int id = A[i];
        vector<bool> flag(500);
        for(auto x:g[id]){
            flag[p[x]] = 1;
        }
        rep(zz,500){
            if(!flag[zz]){
                p[id] = zz;
                break; 
            }
        }
    }
    // rep(i,n){
    //     cerr << p[i] << " ";
    // }
    // cerr << endl;
    int mx = 0;
    rep(i,n){
        chmax(mx,p[i]);
    }
    int k = 1;
    while(k <= mx){
        k *= 2;
    }
    vector<int> a(k);

    rep(i,n){
        a[p[i]]++;
    }
    Matrix M(k,k);
    rep(i,k){
        rep(j,k){
            M[i][i^j] = a[j];
        }
    }
    rep(i,k){
        M[i][i] += MOD-(n+1);
        M[i][i] %= MOD;
    }
    // rep(i,k){
    //     rep(j,k){
    //         cerr << M[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    vector<long long> ans;
    vector<long long> b(k);
    b[0] = MOD-1;
    linear_equation(M,b,ans);
    cout << (MOD+1 - ans[0])%MOD << endl;
    return 0;
}