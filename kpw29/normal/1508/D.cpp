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
const ll INF = (ll)1e18 + 3;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
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
mt19937_64 rng(0);
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


const int maxn = 200100;

int f[maxn], n;

inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
PII min_point;
int KEY;

inline ll det(PII &a, PII &b) {
	return (ll)a.e1 * b.e2 - (ll)a.e2 * b.e1;
}

inline ll area(PII &a, PII &b, PII &c) {
	return det(a, b) + det(b, c) + det(c, a);
}

void solveone() {
	cin >> n;
	vector <pair <PII, int> > v(n + 1);
	for (int i=1; i<=n; ++i) cin >> v[i].e1.e1 >> v[i].e1.e2 >> v[i].e2;
	
	vector <bool> odw(n+1, false);
	int CC = 0;
	FOR(i, 1, n) {
		if (v[i].e2 != i && !odw[i]) {
			++CC;
			int j = i;
			while (!odw[j]) {
				odw[j] = true;
				f[j] = i;
				j = v[j].e2;
			}
		}
	}
	
	vector <PII> swaps = {};
	vector <int> points(n);
	for (int i=0; i<n; ++i) points[i] = i + 1;
	min_point = {inf, inf};
	KEY = -1;
	for (int i=1; i<=n; ++i) {
		if (v[i].e2 != i) {
			if (v[i].e1 < min_point) {
				KEY = i;
				min_point = v[i].e1;
			}
		}
	}
	
	if (KEY == -1) {
		OUT(0);
	}
	
	sort(points.begin(), points.end(), [&](int a, int b){
		if (a == KEY) return true;
		if (b == KEY) return false;
		if (v[a].e2 == a && v[b].e2 == b) return a < b;
		if (v[a].e2 == a) return false;
		if (v[b].e2 == b) return true;
		
		// now geometrical comparison
		return area(min_point, v[a].e1, v[b].e1) > 0;
		});
	
	for (int it = 2; it < points.size(); ++it) {
		int i = points[it];
		if (v[i].e2 == i) break;
		int j = points[it - 1];
		if (find(i) != find(j)) {
			swaps.push_back({i, j});
			swap(v[i].e2, v[j].e2);
			f[find(i)] = find(j);
			--CC;
		}
	}
	
	//assert(CC == 1); // now there should be exactly one cycle
	int gdzie = KEY;
	
	while (v[gdzie].e2 != gdzie) {
		int co = v[gdzie].e2;
		swaps.push_back({gdzie, co});
		swap(v[gdzie].e2, v[co].e2);
	}
	
	//FOR(i, 1, n) assert(v[i].e2 == i);
	cout << (int)swaps.size() << "\n";
	for (auto u : swaps) cout << u.e1 << ' ' << u.e2 << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}