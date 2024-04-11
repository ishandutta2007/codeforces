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
const int inf = 1e9+8;
//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n;
	cin >> n;
	vector <ll> v;
	rep(i, 0, n) {
		ll x;
		cin >> x;
		if (x != 0) v.push_back(x);
	}
	
	vector <int> bits(61, 0);
	trav(elem, v) {
		for (int bit=0; bit<=60; ++bit) {
			if ((1LL << bit) & elem) bits[bit]++;
			if (bits[bit] >= 3) TCOUT(3);
		}
	}
	
	assert(sz(v) <= 122);
	int res = inf;
	for (int i=0; i<sz(v); ++i) {
		queue<int> q;
		vi dist(sz(v), inf);
		vi par(sz(v), inf);
		q.push(i);
		dist[i] = 0; par[i] = i;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int j = 0 ; j < sz(v); ++j) {
				if (dist[j] == inf && ((v[x] & v[j]) > 0)) {
					par[j] = x;
					dist[j] = dist[x] + 1;
					q.push(j);
				}
			}
		}
		debug(i, par);
		debug(i, dist);
		for (int j=0; j < sz(v); ++j) {
			if (par[j] == i) continue;
			if ((v[i] & v[j]) > 0) {
				res = min(res, 1 + dist[j]);
			}
		}
		for (int j=0; j<sz(v); ++j) {
			for (int k=0; k<sz(v); ++k) {
				if (i == j || k == j || i == k) continue;
				if (par[j] == k || par[k] == j) continue;
				if ((v[k] & v[j]) > 0) res = min(res, dist[j] + dist[k] + 1);
			}
		}
	}
	
	if (res == inf) TCOUT(-1);
	cout << res << endl;
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}