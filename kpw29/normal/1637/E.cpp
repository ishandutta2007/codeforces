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
void solve(int tc) {
	int n, m;
	cin >> n >> m;
	map<int, int> cnt;
	
	set <pii> bad;
	vi arr(n);
	rep(i, 0, n) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		bad.insert({a, b});
		bad.insert({b, a});
	}
	
	vi iscnt(n+1, 0);
	trav(u, cnt) {
		iscnt[u.e2] = 1;
	}
	
	vi vector_given_cnt(n+1, -1);
	vi cnts;
	vector<vi> numbers;
	
	FOR(i, 1, n) {
		if (iscnt[i]) {
			vector_given_cnt[i] = sz(cnts);
			numbers.pb({});
			cnts.pb(i);
		}
	}
	
	trav(u, cnt) {
		auto [value, ile] = u;
		assert(iscnt[ile] == 1);
		int kt = vector_given_cnt[ile];
		numbers[kt].pb(value);
	}
	
	rep(i, 0, sz(numbers)) {
		sort(all(numbers[i]), greater<int>());
	}
	
	debug(vector_given_cnt);
	rep(i, 0, sz(cnts)) {
		debug(cnts[i]);
		debug(numbers[i]);
	}
	
	auto get_max = [&](int i, int j) -> ll {
		//always iterating over smaller
		if (sz(numbers[i]) > sz(numbers[j])) swap(i, j);
		ll largest = 0;
		trav(numi, numbers[i]) {
			trav(numj, numbers[j]) {
				if (numi == numj) continue;
				if (bad.find({numi, numj}) == bad.end()) {
					largest = max(largest, (ll)numi + numj);
					break;
				}
			}
		}
		
		return largest;
	};
	
	ll best = 0;
	for (int i=0; i<sz(cnts); ++i) {
		for (int j=i; j<sz(cnts); ++j) {
			best = max(best, (cnts[i] + cnts[j]) * get_max(i, j));
		}
	}
	cout << best << "\n";
}

int main() {
	boost;
	int tests = 1;
	cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}