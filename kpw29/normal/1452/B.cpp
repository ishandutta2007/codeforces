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
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 100100;
int n, m;

ll res[maxn];
ll sum;
ll arr[maxn], help[maxn], pref[maxn];
ll sm;


bool check(ll k) {
	ll each_one = k / (n - 1);
	FOR(i, 1, n) {
		if (arr[i] > each_one) return false;
	}
	
	ll avail_add = k - sum;
	if (avail_add < 0) return false;
	
	debug(k);
	for (int i=1; i<=n; ++i) {
		if (i == n || (ll)arr[i + 1] * i - pref[i] > avail_add) {
			ll total = (pref[i] + k);
			ll total_each = total / i;
			FOR(j, 1, i) help[j] = total_each;
			total -= total_each * i;
			int j = i;
			while (total) {
				help[j]++;
				--j;
				--total;
			}
			break;
		}
	}
	
	//redist done
	ll worst = help[1];
	ll score = 0;
	FOR(i, 2, n) score += each_one - help[i];
	
	return (score <= worst);
}

void solveone() {
	cin >> n;
	sum = 0;
	FOR(i, 1, n) cin >> arr[i], sum += arr[i];
	sort(arr+1, arr+n+1);
	arr[n + 1] = inf;
	pref[0] = 0;
	FOR(i, 1, n + 1) pref[i] = pref[i-1] + arr[i];

	ll x = 0, y = (ll)1e13;
	while (x < y) {
		ll sr = (x + y) / 2;
		if (!check((ll)(n - 1) * sr)) x = ++sr;
		else y = sr;
	}
	
	cout << (ll)(n - 1) * x - sum << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}