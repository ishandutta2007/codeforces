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

int t;
int n;
int a[MAXN];
bool used[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			used[i] = 0;
		}
		int ans = n;
		vi v;
		REP (i, 1, n + 1) {
			if (used[a[i]]) {
				v.pb(i);
				ans--;
			}
			used[a[i]] = 1;
		}
		if (v.size() == 1) {
			int id = -1;
			REP (i, 1, n + 1) {
				if (!used[i]) {
					assert(id == -1);
				   	id = i;
				}
			}
			assert(id != -1);
			if (v[0] == id) {
				REP (i, 1, n + 1) {
					if (a[i] == a[v[0]]) {
						v[0] = i;
						break;
					}
				}
			}
			a[v[0]] = id;
		} else {
			int j = 1;
			for (int i : v) {
				for (; j <= n && used[j]; j++) {
				}
				assert(j <= n);
				a[i] = j;
				j++;
			}
			REP (i, 0, v.size()) {
				int x = v[i], y = v[(i + 1) % v.size()];
				if (a[x] == x) {
					swap(a[x], a[y]);
				}
			}
		}
		printf("%d\n", ans);
		REP (i, 1, n + 1) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}