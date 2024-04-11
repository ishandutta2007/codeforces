#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 10005

int t;
int n;
int arr[MAXN];
bool used[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) used[i] = 0;
		for (int i = 1; i + 1 <= n; i += 2) {
			printf("? %d %d %d %d\n", 1, i, i + 1, n - 1);
			fflush(stdout);
			int x; scanf("%d", &x);
			if (x == n - 1) {
				printf("? %d %d %d %d\n", 1, i + 1, i, n - 1);
				fflush(stdout);
				int tmp; scanf("%d", &tmp);
				mxto(x, tmp);
			}
			arr[i] = x;
			used[x] = 1;
			printf("? %d %d %d %d\n", 2, i, i + 1, 1);
			fflush(stdout);
			scanf("%d", &x);
			if (x == 2) {
				printf("? %d %d %d %d\n", 2, i + 1, i, 1);
				fflush(stdout);
				int tmp; scanf("%d", &tmp);
				mnto(x, tmp);
			}
			arr[i + 1] = x;
			used[x] = 1;
		}
		REP (i, 1, n + 1) {
			if (!used[i]) arr[n] = i;
		}
		int pend = 1;
		for (int i = 3; i + 1 <= n; i += 2) {
			int cur = i;
			if (arr[i] == 1 || arr[i + 1] == 1) swap(pend, cur);
			printf("? %d %d %d %d\n", 2, pend, cur, 1);
			fflush(stdout);
			int x; scanf("%d", &x);
			if (x == arr[cur + 1]) {
				swap(arr[cur], arr[cur + 1]);
			}
			if (x == arr[pend + 1]) {
				swap(arr[pend], arr[pend + 1]);
			}
			if (x == arr[pend]) swap(cur, pend);
		}
		int mx = max(arr[pend], arr[pend + 1]);
		printf("? %d %d %d %d\n", 1, pend, pend + 1, mx - 1);
		fflush(stdout);
		int x; scanf("%d", &x);
		if (x == mx && arr[pend + 1] != mx) {
			swap(arr[pend], arr[pend + 1]);
		} else if (x != mx && arr[pend + 1] == mx) {
			swap(arr[pend], arr[pend + 1]);
		}
		printf("!");
		REP (i, 1, n + 1) {
			printf(" %d", arr[i]);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}