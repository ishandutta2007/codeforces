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
#define int long long
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

const int maxn = 500100;
int n, m, k;

PII points[maxn];
int MAX[4], MIN[4];

void solveone() {
	FOR(i, 0, 3) {
		MAX[i] = INT_MIN;
		MIN[i] = INT_MAX;
	}
	
	cin >> n;
	FOR(i, 1, n) {
		int x, kt;
		cin >> x;
		char tp;
		cin >> tp;
		if (tp == 'P') kt = 3;
		if (tp == 'B') kt = 1;
		if (tp == 'R') kt = 2;
		
		points[i] = {x, kt};
		
		MAX[kt] = max(MAX[kt], x);
		MIN[kt] = min(MIN[kt], x);
	}
	
	if (MAX[3] == INT_MIN) {
		ll res = 0;
		FOR(i, 1, 2) 
			if (MAX[i] != INT_MIN) res += MAX[i] - MIN[i];
		OUT(res);
	}
	
	ll res = 0;
	FOR(i, 1, 2) {
		if (MIN[i] < MIN[3]) res += MIN[3] - MIN[i];
	}
	
	FOR(i, 1, 2) {
		if (MAX[i] > MAX[3]) res += MAX[i] - MAX[3];
	}

	int border = MIN[3];
	vector <int> back = {0, INT_MIN, INT_MIN, border};
	vector <int> dist = {0, INT_MIN, INT_MIN};
	
	FOR(i, 1, n) {
		if (points[i].e1 <= border) continue;
		int x = points[i].e1;
		int type = points[i].e2;
		if (type == 3) {
			FOR(j, 1, 2) {
				if (back[j] != INT_MIN) dist[j] = max(dist[j], x - back[j]);
			}
			
			int simple_opt = 2 * (x - border);
			int soph_opt = (x - border);
			FOR(j, 1, 2)
				if (back[j] != INT_MIN) soph_opt += (x - border) - dist[j];
			
			res += min(simple_opt, soph_opt);
			border = x;
			dist = {0, INT_MIN, INT_MIN};
			back = {0, INT_MIN, INT_MIN, border};	
		}
		else {
			if (back[type] == INT_MIN) dist[type] = max(dist[type], x - back[3]);
			else dist[type] = max(dist[type], x - back[type]);
			back[type] = x;
		}
	}
	
	cout << res << "\n";
}

int32_t main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}