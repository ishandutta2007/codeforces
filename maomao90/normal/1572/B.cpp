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
int a[MAXN];
vi ans;

void solve(int l, int r) {
	for (int i = l; i <= r - 2; i += 2) {
		ans.pb(i);
	}
	for (int i = r - 4; i >= l; i -= 2) {
		ans.pb(i);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int x = 0;
		ans.clear();
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			x ^= a[i];
		}
		if (x != 0) {
			printf("NO\n");
			continue;
		}
		if (n % 2 == 1) {
			solve(1, n);
		} else {
			x = 0;
			bool pos = 0;
			REP (i, 1, n + 1) {
				x ^= a[i];
				if (x == 0 && i % 2 == 1) {
					pos = 1;
					solve(1, i);
					solve(i + 1, n);
					break;
				}
			}
			if (!pos) {
				printf("NO\n");
				continue;
			}
		}
		printf("YES\n");
		printf("%d\n", (int) ans.size());
		for (int i : ans) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}