#include <bits/stdc++.h>
#include <time.h>
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
const int mod = 1e9+7;
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

const int maxn = 5010;

int n, DL = 0;
int x[maxn], y[maxn];
bool odw[maxn];
int dist[maxn];

inline int odl(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

void dfs(int x, int k) {
	odw[x] = true;
	FOR(i, 1, n)
		if (x != i && odl(i, x) > k) {
			if (!odw[i]) {
				dist[i] = (dist[x] ^ 1);
				dfs(i, k);
			}
		}
}

int check(int k) {
	fill(odw, odw+maxn, false);
	fill(dist, dist+maxn, -1);
	int spoj = 0;
	FOR(i, 1, n)
		if (!odw[i]) {
			++spoj;
			dist[i] = 0;
			dfs(i, k);
		}
	
	FOR(i, 1, n)
		FOR(j, i+1, n)
			if (odl(i, j) > k && dist[i] == dist[j]) return -1;
	
	return spoj;
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> x[i] >> y[i];
	}
	
	int binx = 0, biny = 10000;
	while (binx < biny) {
		int sr = (binx + biny) / 2;
		if (check(sr) == -1) binx = ++sr;
		else biny = sr;
	}
	
	int pw = check(binx);
	assert(pw != -1);
	ll res = 1;
	FOR(i, 1, pw) res = (res * 2) % mod;
	cout << binx << endl << res;
}