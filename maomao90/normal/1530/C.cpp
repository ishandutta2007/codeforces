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
int a[MAXN], b[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		REP (i, 0, n) {
			scanf("%d", &b[i]);
		}
		sort(a, a + n, greater<int>());
		sort(b, b + n, greater<int>());
		int suma = 0, sumb = 0;
		priority_queue<int, vi, greater<int>> da, db;
		priority_queue<int> ra, rb;
		REP (i, 0, n - n / 4) {
			da.push(a[i]);
			suma += a[i];
			db.push(b[i]);
			sumb += b[i];
		}
		REP (i, n - n / 4, n) {
			ra.push(a[i]);
			rb.push(b[i]);
		}
		int ans = 0;
		while (suma < sumb) {
			ans++;
			int nn = n + 1;
			ra.push(100);
			rb.push(0);
			REP (_, 0, 2) {
				int tmp = ra.top(); ra.pop();
				da.push(tmp);
				suma += tmp;
				tmp = da.top(); da.pop();
				ra.push(tmp);
				suma -= tmp;
			}
			REP (_, 0, 2) {
				int tmp = rb.top(); rb.pop();
				db.push(tmp);
				sumb += tmp;
				tmp = db.top(); db.pop();
				rb.push(tmp);
				sumb -= tmp;
			}
			if (n - n / 4 != nn - nn / 4) {
				int tmp = ra.top(); ra.pop();
				da.push(tmp);
				suma += tmp;
				tmp = rb.top(); rb.pop();
				db.push(tmp);
				sumb += tmp;
			}
			n = nn;
		}
		printf("%d\n", ans);
	}
	return 0;
}