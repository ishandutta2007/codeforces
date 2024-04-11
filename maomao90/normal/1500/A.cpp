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
#define MAXN 200005
#define MAX 5000005

int n;
int a[MAXN];
vi cnt[MAX];
vii occ[MAX];

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		cnt[a[i]].pb(i + 1);
	}
	REP (i, 0, MAX) {
		if (cnt[i].size() >= 4) {
			printf("YES\n");
			printf("%d %d %d %d\n", cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3]);
			return 0;
		}
	}
	REP (i, 0, n) {
		REP (j, i + 1, n) {
			int sum = a[i] + a[j];
			occ[sum].pb(i + 1, j + 1);
			REP (k, 0, occ[sum].size()) {
				ii temp1 = occ[sum][k], temp2 = MP(i + 1, j + 1);
				if (temp1.FI != temp2.SE && temp1.FI != temp2.FI && temp1.SE != temp2.FI && temp1.SE != temp2.SE) {
					printf("YES\n");
					printf("%d %d %d %d\n", temp1.FI, temp1.SE, temp2.FI, temp2.SE);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}