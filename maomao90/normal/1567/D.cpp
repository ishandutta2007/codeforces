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
int s;
int n;

int getd(int s, int i) {
	while (i--) {
		s /= 10;
	}
	return s % 10;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &s);
		scanf("%d", &n);
		int pw = 1000000000;
		vi ans;
		RREP (i, 9, 0) {
			int mx = -1;
			for (int j = 0; ; j++) {
				int sm = j * pw + max(0, n - j);
				debug(" %d %d\n", sm, s);
				if (sm <= s) {
					mx = j;
				} else {
					break;
				}
			}
			assert(mx != -1);
			int use = min(mx, n);
			REP (i, 0, use - 1) {
				ans.pb(pw);
				debug(" +%d\n", pw);
			}
			if (use > 0) {
				debug(" +%d\n", (mx - use + 1) * pw);
				ans.pb((mx - use + 1) * pw);
			} else if (!ans.empty()) {
				ans[0] += mx * pw;
			}
			int sm = mx * pw;
			debug("%d: %d %d\n", i, mx, sm);
			s -= sm;
			n -= use;
			pw /= 10;
		}
		ans[0] += s;
		for (int i : ans) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}