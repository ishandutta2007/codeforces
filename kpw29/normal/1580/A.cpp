#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
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
const int maxn = 1000100;

//Did you REAALLY consider sample tests?

template<class T>
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v, int n, int m) {
		int R = n, C = m;
		p.assign(R+1, vector<T>(C+1, 0));
		rep(i,1,n+1)
		rep(j,1,m+1) p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + v[i][j];
	}
	T sum(int a, int b, int c, int d) {
		return p[c][d] - p[c][b-1] - p[a-1][d] + p[a-1][b-1];
	}
};

void solve(int tc) {
	int n, m;
	cin >> n >> m;
	vector <vi> v(n+1);
	vector <vi> odwr(n+1);
	rep(j, 0, m+1) v[0].pb(0), odwr[0].pb(0);
	
	rep(i, 1, n+1) {
		string s;
		cin >> s;
		v[i].pb(0);
		odwr[i].pb(0);
		rep(j,0,m) {
			int znak = s[j]-'0';
			v[i].pb(znak);
			odwr[i].pb(1-znak);
		}
	}
	
	SubMatrix ones(v, n, m);
	SubMatrix zeros(odwr, n, m);
	
	auto licz = [&](int a, int b) {
		int res = 1e9;
		int best = -1e9;
		
		rep(i, 1, n+1) {
			if (i >= 5) {
				int total = ones.sum(1, a+1, i-4, b-1);
				int pleft = zeros.sum(1, a, i-4, a);
				int pright = zeros.sum(1, b, i-4, b);
				int pup = zeros.sum(i-4, a+1, i-4, b-1);
				best = max(best, total + pleft + pright - pup);
			}
			
			int total = ones.sum(1, a+1, i-1, b-1);
			int pleft = zeros.sum(1, a, i-1, a);
			int pright = zeros.sum(1, b, i-1, b);
			int pdown = zeros.sum(i, a+1, i, b-1);
			
			int tutaj = total + pleft + pright + pdown;
			res = min(res, tutaj - best);
		}
		
		return res;
	};
	
	int res = 1e9;
	for (int i=1; i<=m; ++i) {
		for (int j=i+3; j<=m; ++j) {
			res = min(res, licz(i, j));
		}
	}
	
	cout << res << "\n";
}

int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}