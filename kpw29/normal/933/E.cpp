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
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
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
const int maxn = 300100;
const ll INF = 1e18+3;
int n;
ll arr[maxn];

ll cost(int a, int b) {
	if (a == b) return arr[a];
	assert(a + 1 == b);
	return arr[a] + max(0LL, arr[b] - arr[a]);
}

ll dp[maxn];
int best[maxn];

void solve(int tc) {
	cin >> n;
	FOR(i, 1, n) cin >> arr[i];
	if (n == 1) OUT("0");
	
	dp[0] = 0;
	FOR(i, 1, n) {
		dp[i] = INF;
		ll attempt = cost(i, i) + min((i > 1 ? dp[i - 2] : INF), dp[i-1]);
		if (attempt < dp[i]) {
			dp[i] = attempt;
			best[i] = i;
		}
		attempt = cost(i-1, i) + min((i > 1 ? dp[i - 2] : INF), (i > 2 ? dp[i - 3] : INF));
		if (attempt < dp[i]) {
			dp[i] = attempt;
			best[i] = i-1;
		}
	}
	
	ll score = min(dp[n], dp[n-1]);
	ll pos = n;
	if (dp[n-1] < dp[n]) pos = n-1;
	vector <pii> vec;
	
	while (pos > 0) {
		vec.pb({best[pos], pos});
		int i = best[pos];
		if (i == 1 || dp[i-1] < dp[i-2]) pos = i-1;
		else pos = i-2;
	}

	vi ans;
	// found score and vectors, now we should restore the answer
	auto descend = [&](int i) {
		assert(1 <= i && i < n);
		ll mn = min(arr[i], arr[i+1]);
		if (mn == 0) return;
		ans.pb(i);
		arr[i] -= mn;
		arr[i+1] -= mn;
	};
	
	reverse(all(vec));
	//debug(vec);
	trav(node, vec) {
		if (node.e1 == node.e2) {
			int i = node.e1;
			if (i > 1 && arr[i-1] >= arr[i]) descend(i - 1);
			else descend(i);
			if (i > 1 && arr[i-1] >= arr[i]) descend(i - 1);
			else descend(i);
		}
		else {
			int i = node.e1;
			if (arr[i] == arr[i+1]) descend(i);
			else {
				descend(i);
				if (i > 1) descend(i-1);
				if (i + 1 < n) descend(i+1);
			}
		}
	};
	
	rep(i, 1, n) assert(!(arr[i] > 0 && arr[i+1] > 0));
	cout << sz(ans) << endl;
	trav(u, ans) cout << u << "\n";
	//cout << "OK\n";
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