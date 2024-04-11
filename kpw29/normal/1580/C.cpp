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

const int SQRT = 200;
int dp[SQRT][SQRT];

ll zlicz(int t) {
	ll ret = 0;
	rep(i, 1, SQRT) ret += dp[i][t % i];
	return ret;
}

void update(int prze, int a, int b, int val) {
	a %= prze; b %= prze;
	if (a > b) {
		update(prze, a, prze - 1, val);
		update(prze, 0, b, val);
		return;
	}
	rep(i, a, b+1) dp[prze][i] += val;
}

void solve(int tc) {
	int n, m;
	cin >> n >> m;
	vector <pii> tab(n);
	vi added(n, -1);
	rep(i, 0, n) cin >> tab[i].first >> tab[i].second;
	auto sum = [&](int i) {
		return tab[i].first + tab[i].second;
	};
	vector <ll> wynik(m, 0);
	rep(t, 0, m){
		if (t) wynik[t] += wynik[t-1];
		int type, k;
		cin >> type >> k;
		--k;
		int sm = sum(k);
		if (type == 1) {
			added[k] = t;
			if (sm >= SQRT) {
				for (int j = 0; j <= 1000000; ++j) {
					int minelo = added[k] + j * sm;
					if (minelo >= m) break;
					//debug("Adding: ", minelo + tab[k].first, minelo + sm);
					if (minelo + tab[k].first < m) wynik[max(t, minelo + tab[k].first)]++;
					if (minelo + sm < m) wynik[max(t, minelo + sm)]--;
				}
			}
			else {
				update(sm, added[k] + tab[k].first, added[k] + sm - 1, 1);
			}
		}
		else {
			if (sm >= SQRT) {
				for (int j = 0; j <= 1000000; ++j) {
					int minelo = added[k] + j * sm;
					if (minelo >= m) break;
					//debug("Removing: ", minelo + tab[k].first, minelo + sm);
					if (minelo + tab[k].first < m) wynik[max(t, minelo + tab[k].first)]--;
					if (minelo + sm < m) wynik[max(t, minelo + sm)]++;
				}
			}
			else {
				update(sm, added[k] + tab[k].first, added[k] + sm - 1, -1);
			}
			
			
			added[k] = -1;
		}
		
		
		cout << zlicz(t) + wynik[t] << "\n";
	}
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