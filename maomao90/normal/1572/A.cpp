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
#define MAXN 200005

int t;
int n;
int k[MAXN];
int in[MAXN];
vi a[MAXN];
vi adj[MAXN];
set<int> st;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			adj[i].clear();
		}
		st.clear();
		REP (i, 1, n + 1) {
			scanf("%d", &k[i]);
			a[i].resize(k[i] + 5, 0);
			in[i] = k[i];
			if (in[i] == 0) st.insert(i);
			REP (j, 0, k[i]) {
				scanf("%d", &a[i][j]);
				adj[a[i][j]].pb(i);
			}
		}
		if (st.empty()) {
			printf("-1\n");
			continue;
		}
		int cnt = 0;
		int ans = 1;
		auto ptr = st.begin();
		while (1) {
			cnt++;
			int u = *ptr; st.erase(ptr);
			for (int v : adj[u]) {
				if (--in[v] == 0) {
					st.insert(v);
				}
			}
			if (st.empty()) {
				break;
			}
			ptr = st.lower_bound(u);
			if (ptr == st.end()) {
				ptr = st.begin();
				ans++;
			}
		}
		if (cnt != n) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}