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
#define MAXN 300005

int t;
int n;
int a[MAXN];
int useful[MAXN];
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		REP (i, 1, n - 1) {
			bool can = (a[i - 1] > a[i] && a[i + 1] > a[i]) || (a[i - 1] < a[i] && a[i + 1] < a[i]);
			if (can) {
				ans++;
				useful[i - 1]++;
				useful[i]++;
				useful[i + 1]++;
			}
		}
		int curMax = 0;
		REP (i, 0, n) {
			if (i + 1 < n) {
				int cur = 0;
				int temp = a[i];
				a[i] = a[i + 1];
				REP (j, max(i - 1, 1), min(n - 1, i + 2)) {
					bool can = (a[j - 1] > a[j] && a[j + 1] > a[j]) || (a[j - 1] < a[j] && a[j + 1] < a[j]);
					if (can) cur++;
				}
				curMax = max(useful[i] - cur, curMax);
				a[i] = temp;
			}
			if (i - 1 >= 0) {
				int cur = 0;
				int temp = a[i];
				a[i] = a[i - 1];
				REP (j, max(i - 1, 1), min(n - 1, i + 2)) {
					bool can = (a[j - 1] > a[j] && a[j + 1] > a[j]) || (a[j - 1] < a[j] && a[j + 1] < a[j]);
					if (can) cur++;
				}
				curMax = max(useful[i] - cur, curMax);
				a[i] = temp;
			}
			useful[i] = 0;
		}
		ans -= curMax;
		printf("%d\n", ans);
	}
	return 0;
}