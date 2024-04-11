#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
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
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
int a[MAXN], cpy[MAXN], pre[MAXN], pst[MAXN];
bool precan[MAXN], pstcan[MAXN];

void restore() {
	REP (i, 0, n + 2) cpy[i] = a[i];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) scanf("%d", &a[i]);
		a[0] = a[n + 1] = 0;
		restore();
		REP (i, 0, n + 2) precan[i] = 1;
		REP (i, 0, n + 1) {
			precan[i + 1] &= precan[i];
			int minus = cpy[i];
			cpy[i] = 0;
			cpy[i + 1] -= minus;
			pre[i] = minus;
			if (cpy[i + 1] < 0) {
				precan[i + 1] = 0;
			}
		}
		if (precan[n + 1]) {
			printf("YES\n");
			continue;
		}
		restore();
		RREP (i, n + 2, 0) pstcan[i] = 1;
		RREP (i, n + 2, 1) {
			pstcan[i - 1] = pstcan[i];
			int minus = cpy[i];
			cpy[i] = 0;
			cpy[i - 1] -= minus;
			if (cpy[i - 1] < 0) pstcan[i - 1] = 0;
			pst[i] = minus;
		}
		bool can = 0;
		REP (i, 1, n) {
			bool curcan = 1;
			if (!precan[i - 1] || !pstcan[i + 2]) continue;
			swap(a[i], a[i + 1]);
			int temp1 = a[i] - pre[i - 1];
			if (temp1 < 0) curcan = 0;
			int temp2 = a[i + 1] - temp1;
			if (temp2 < 0) curcan = 0;
			if (pst[i + 2] != temp2) curcan = 0;
			swap(a[i], a[i + 1]);
			if (curcan) {
				can = 1;
				break;
			}
		}
		if (can) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}