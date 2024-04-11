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
#define MAXN 200005

int n, m;
int cnt[MAXN];
int q;
int ans;

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		if (cnt[u]++ == 0) {
			ans++;
		}
	}
	scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int u, v; scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			if (cnt[u]++ == 0) {
				ans++;
			}
		} else if (t == 2) {
			int u, v; scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			if (--cnt[u] == 0) {
				ans--;
			}
		} else {
			printf("%d\n", n - ans);
		}
	}
	return 0;
}