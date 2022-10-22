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
int n, a, b;
int ans[MAXN];
bool used[MAXN * 3];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		if (abs(a - b) > 1) {
			printf("-1\n");
			continue;
		}
		if (n == 2) {
			if (a == 0 && b == 0) {
				printf("1 2\n");
			} else {
				printf("-1\n");
			}
			continue;
		}
		bool swp = 0;
		if (a < b) {
			swap(a, b);
			swp = 1;
		}
		if (a == 0) {
			REP (i, 0, n) {
				printf("%d ", i + 1);
			}
			printf("\n");
			continue;
		}
		REP (i, -n - 5, n + 5) {
			used[i + MAXN] = 0;
		}
		used[MAXN] = 1;
		used[MAXN + 1] = 1;
		used[MAXN + 2] = 1;
		ans[0] = 0;
		ans[1] = 2;
		ans[2] = 1;
		a--;
		int dir = -1;
		REP (i, 3, n) {
			if (a == 0 && b == 0) {
				for (int j = ans[i - 1] + dir; ; j += dir) {
					if (!used[j + MAXN]) {
						ans[i] = j;
						used[j + MAXN] = 1;
						break;
					}
				}
			} else if (i % 2 == 1) {
				used[i + 1 + MAXN] = 1;
				ans[i] = i + 1;
				b--;
				if (a == 0 && b == 0) {
					used[i + 1 + MAXN] = 0;
					used[i + MAXN] = 1;
					ans[i] = i;
					dir = 1;
				}
			} else {
				used[i - 1 + MAXN] = 1;
				ans[i] = i - 1;
				a--;
				if (a == 0 && b == 0) {
					dir = -1;
				}
			}
		}
		if (a != 0 || b != 0) {
			printf("-1\n");
			continue;
		}
		int mn = INF;
		REP (i, 0, n) {
			mnto(mn, ans[i]);
		}
		REP (i, 0, n) {
			ans[i] -= mn;
		}
		if (swp) {
			REP (i, 0, n) {
				ans[i] = n - ans[i] - 1;
			}
		}
		REP (i, 0, n) {
			printf("%d ", ans[i] + 1);
		}
		printf("\n");
	}
	return 0;
}