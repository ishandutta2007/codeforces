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
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1005

int n;
int a[MAXN][MAXN];
int c[MAXN];
vii edges;

vi v;
int ptr;
bool dis[MAXN];
void solve(vi v, int p) {
	if (v.size() == 1) {
		c[v[0]] = a[v[0]][v[0]];
		edges.pb(MP(v[0], p));
		return;
	}
	int mx = -1;
	for (int i : v) {
		for (int j : v) {
			mxto(mx, a[i][j]);
		}
	}
	int head = ptr++;
	c[head] = mx;
	if (p != -1) {
		edges.pb(MP(head, p));
	}

	vector<bool> used(n + 5, 0);
	for (int i : v) {
		if (used[i]) continue;
		for (int j : v) {
			dis[j] = 0;
		}
		for (int j : v) {
			if (a[i][j] == mx) {
				dis[j] = 1;
			}
		}
		vi tmp;
		for (int j : v) {
			if (!dis[j]) {
				tmp.pb(j);
				used[j] = 1;
			}
		}
		solve(tmp, head);
	}
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		REP (j, 0, n) {
			scanf("%d", &a[i][j]);
		}
	}
	REP (i, 0, n) {
		v.pb(i);
	}
	ptr = n;
	solve(v, -1);
	assert(edges.size() == ptr - 1);
	printf("%d\n", ptr);
	REP (i, 0, ptr) {
		printf("%d ", c[i]);
	}
	printf("\n");
	printf("%d\n", n + 1);
	for (auto [u, v] : edges) {
		printf("%d %d\n", u + 1, v + 1);
	}
	return 0;
}