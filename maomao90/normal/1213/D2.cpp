#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
#define pb emplace_back
typedef vector<int> vi;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
#define MT make_tuple
typedef tuple<int, int, int> iii;

#define INF 1000000005
#define MAXN 200005

int n, k;
int a[MAXN];
vi cnt[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 0, n) scanf("%d", &a[i]);
	REP (i, 0, n) {
		int temp = 0;
		while (a[i]) {
			cnt[a[i]].push_back(temp++);
			a[i] /= 2;
		}
		cnt[a[i]].push_back(temp++);
	}
	int ans = INF;
	REP (i, 0, MAXN) {
		sort(cnt[i].begin(), cnt[i].end());
		if (cnt[i].size() >= k) {
			int cur = 0;
			REP (j, 0, k) {
				cur += cnt[i][j];
			}
			ans = min(ans, cur);
		}
	}
	printf("%d\n", ans);
	return 0;
}