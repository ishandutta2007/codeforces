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
typedef pair <PLL, PLL > PP;
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

const int maxn = 250100;
int arr[maxn];
int pocz[maxn], kon[maxn], dozw[maxn], n, m;
ll cons[maxn];
int perm[maxn];

bool check(int kt, ll v) {
	int a = pocz[kt], b = kon[kt];
	int res = 0;
	ll fuel = v;
	for (int i=a; i<b; ++i) {
		ll will_take = cons[kt] * (arr[i + 1] - arr[i]);
		if (will_take > v) return false;
		
		if (will_take > fuel) {
			++res;
			fuel = v - will_take;
		}
		else fuel -= will_take;
	}

	return res <= dozw[kt];
}

int main() {
	srand(time(0));
	boost;
	cin >> n >> m;
	FOR(i, 1, n) cin >> arr[i];
	FOR(i, 1, m) {
		cin >> pocz[i] >> kon[i] >> cons[i] >> dozw[i];
		perm[i] = i;
	}
	
	ll V = 1;
	ll MX = (long long)1e18;
	MX += 3;
	random_shuffle(perm+1, perm+m+1);
	for (int i=1; i<=m; ++i) {
		if (!check(perm[i], V)) {
			ll x = V + 1, y = MX;
			while (x < y) {
				ll sr = (x + y) / 2LL;
				if (!check(perm[i], sr)) x = ++sr;
				else y = sr;
			}
			
			V = x;
		}
	}
	
	cout << V;
}