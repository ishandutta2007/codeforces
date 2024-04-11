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
#define MAXN 2025

int t;
int n;
int a[MAXN];
vi ans;

ii getx(int x) {
	int fi, se;
	REP (i, 1, n + 1) {
		if (a[i] == x) {
			fi = i;
		}
		if (a[i] == x + 1) {
			se = i;
		}
	}
	return MP(fi, se);
}

void rev(int x) {
	REP (i, 1, x / 2 + 1) {
		swap(a[i], a[x - i + 1]);
	}
	ans.pb(x);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool pos = 1;
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			if (a[i] % 2 != i % 2) {
				pos = 0;
			}
		}
		if (!pos) {
			printf("-1\n");
			continue;
		}
		ans.clear();
		for (int x = n - 1; x > 1; x -= 2) {
			int fi, se;
			tie(fi, se) = getx(x);
			rev(se);
			tie(fi, se) = getx(x);
			assert(se == 1);
			rev(fi - 1);
			tie(fi, se) = getx(x);
			rev(fi + 1);
			tie(fi, se) = getx(x);
			rev(se);
			tie(fi, se) = getx(x);
			rev(x + 1);
			tie(fi, se) = getx(x);
			assert(fi == x && se == x + 1);
		}
		printf("%d\n", (int) ans.size());
		for (int i : ans) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}