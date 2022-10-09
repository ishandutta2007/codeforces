#include <bits/stdc++.h>
using namespace std;
 
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const int mod = 998244353;
/*namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
    (*pManip)(cout);
    return *this;
  }
};
}
 
using namespace Color;
ColorDebugger gout(FG_GREEN);
ColorDebugger rout(FG_RED);*/
 
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 1000100;
 
struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    vector<int> trace(int x) {
        vector<int> vx;
        while(true) {
            while(bl[x] != x) x = bl[x];
            if(!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for(int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for(int z : b[c]) {
            bl[z] = c;
            for(int i = 0; i < c; i++) {
                if(g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while(vx.size() >= 2) {
            int z = vx.back(); vx.pop_back();
            if(z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin() : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) - b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while(i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    int solve() {
        for(int ans = 0; ; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for(int i = 0; i < m; i++) bl[i] = i;
            for(int i = 0; i < n; i++) {
                if(mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while(!Q.empty() && !aug) {
                int x = Q.front(); Q.pop();
                if(bl[x] != x) continue;
                for(int y = 0; y < c; y++) {
                    if(bl[y] == y && g[x][y] != -1) {
                        if(d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        }else if(d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if(vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            }else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for(int i = 0; i < (int) A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if(i + 2 < (int) A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(!aug) return ans;
        }
    }
};
 
int zle[1010][1010];
 
int N, n;
vector <vi> graf;
vector <bool> odw;
vector <int> state;
// 0 - nothing
// 1 - definitely taken
// -1 -- definitely not taken
 
vector <int> bad;
 
void solve() {
	cin >> n;
	N = 2 * n;
	state.clear(); state.resize(N, 0);
	bad.clear(); bad.resize(N, 0);
	odw.clear(); odw.resize(N, 0);
	graf.clear();
	graf.resize(N, vector<int>());
	vector <vector <int> > v(N, vector <int>(n, 0));
	rep(i, 0, N) rep(j, 0, n) cin >> v[i][j];
	
	rep(i, 0, N) rep(j, 0, N) zle[i][j] = 0;
	rep(i, 0, N) rep(j, i+1, N) {
		rep(k, 0, n) if (v[i][k] == v[j][k]) zle[i][j] = zle[j][i] = 1;
	}
	
	blossom B(N);
	
	rep(i, 0, N) {
		rep(j, i+1, N) if (zle[i][j] == 1) {
			graf[i].pb(j);
			graf[j].pb(i);
			B.add_edge(i, j);
		}
	}
	
	int res = B.solve();
	assert(res == n);
	// ok, we now have the maximum matching, let's generate number of solutions
	
	queue <int> plus;
	rep(i, 0, N) {
		state.clear();
		state.resize(N, 0);
		state[i] = 1;
		state[B.mate[i]] = -1;
		plus.push(i);
		
		while (!plus.empty()) {
			int x = plus.front();
			plus.pop();
			trav(j, graf[x]) {
				if (state[j] == 1) bad[i] = true;
				else if (state[j] == -1);
				else if (state[j] == 0) {
					state[j] = -1;
					state[B.mate[j]] = 1;
					plus.push(B.mate[j]);
				}
			}
		}
	}
	
	state.clear();
	state.resize(N, 0);
		
	// plus is empty
	rep(i, 0, N) {
		if (bad[i]) {
			int pr = B.mate[i];
			assert(!bad[pr]);
			plus.push(pr);
			state[i] = -1;
			state[pr] = 1;
		}
	}
	
	while (!plus.empty()) {
		int x = plus.front();
		plus.pop();
		trav(j, graf[x]) {
			assert(state[j] != 1);
			if (state[j] == 0) {
				state[j] = -1;
				state[B.mate[j]] = 1;
				plus.push(B.mate[j]);
			}
		}
	}
	
	
	ll tot = 1;
	rep(i, 0, N) {
		if (state[i] == 0) {
			tot = tot * 2LL % mod;
			plus.push(i);
			state[i] = 1;
			state[B.mate[i]] = -1;
			
			
			while (!plus.empty()) {
				int x = plus.front();
				plus.pop();
				trav(j, graf[x]) {
					assert(state[j] != 1);
					if (state[j] == 0) {
						state[j] = -1;
						state[B.mate[j]] = 1;
						plus.push(B.mate[j]);
					}
				}
			}
		}
	}
	
	cout << tot << endl;
	rep(i, 0, N) {
		if (state[i] == 1) cout <<1 + i << ' ';
	}
	
	cout << endl;
}
 
int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	while (tests--) {
		solve();
	}
}