#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1200005
#define BUF 150005

int n, q;
int a[MAXN];
set<int> adj[MAXN];

int p[MAXN], rnk[MAXN];
inline void init() {
	REP (i, 0, MAXN) {
		p[i] = i;
		rnk[i] = 1;
	}
}
int find(int i) {
	if (p[i] == i) return i;
	return p[i] = find(p[i]);
}
inline bool same(int a, int b) {
	return find(a) == find(b);
}
inline bool join(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return 0;
	if (rnk[pa] < rnk[pb]) swap(pa, pb);
	if (rnk[pa] == rnk[pb]) rnk[pa]++;
	p[pb] = pa;
	return 1;
}

int main() {
	scanf("%d%d", &n, &q);
	init();
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
		int u = a[i];
		for (int j = 2; j * j <= u; j++) {
			if (u % j == 0) {
				join(i, j + BUF);
				while (u % j == 0) {
					u /= j;
				}
			}
		}
		if (u != 1) {
			join(i, u + BUF);
		}
	}
	REP (i, 1, n + 1) {
		int u = a[i] + 1;
		vi v;
		v.pb(i);
		for (int j = 2; j * j <= u; j++) {
			if (u % j == 0) {
				v.pb(j + BUF);
				while (u % j == 0) {
					u /= j;
				}
			}
		}
		if (u != 1) {
			v.pb(u + BUF);
		}
		for (int a : v) {
			for (int b : v) {
				adj[find(a)].insert(find(b));
			}
		}
	}
	REP (i, 0, q) {
		int s, t; scanf("%d%d", &s, &t);
		if (same(s, t)) {
			printf("0\n");
		} else if (adj[find(s)].find(find(t)) != adj[find(s)].end()) {
			printf("1\n");
		} else {
			printf("2\n");
		}
	}
	return 0;
}