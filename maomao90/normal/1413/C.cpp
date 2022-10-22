#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)
#define ALL(arr) arr.begin(), arr.end()
#define mnto(x, y) x = min(x, y)
#define pb emplace_back
#define FI first
#define SE second
typedef pair<int, int> ii;

#define MAXN 100005
#define INF 1000000005

int a[10];
int n;
int b[MAXN], occ[MAXN];
vector<ii> pos;

int main() {
	REP (i, 0, 6) scanf("%d", &a[i]);
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &b[i]);
		REP (j, 0, 6) {
			pos.pb(b[i] - a[j], i);
		}
	}
	sort(ALL(pos));
	int r = 0, cnt = 0;
	int ans = INF;
	REP (l, 0, pos.size()) {
		while (r < pos.size() && cnt < n) {
			if (occ[pos[r++].SE]++ == 0) {
				cnt++;
			}
		}
		if (n == cnt) {
			mnto(ans, pos[r - 1].FI - pos[l].FI);
		}
		if (--occ[pos[l].SE] == 0) cnt--;
	}
	printf("%d\n", ans);
	return 0;
}