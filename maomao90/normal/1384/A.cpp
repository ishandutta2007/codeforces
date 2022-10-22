#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)
#define RREP(i, j, k) for (int i = j; i >= k; i--)
typedef long long ll;
#define pb emplace_back
typedef vector<int> vi;
#define FI first
#define SE second
#define MP make_pair
typedef pair<int, int> ii;
#define mxto(x, y) x = min(x, y)
#define mxto(x, y) x = max(x, y)

#define MAXN 105
#define MAXA 75

int t;
int n;
int a[MAXN];
string ans[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) scanf("%d", &a[i]);
		REP (i, 0, MAXA) ans[0] += 'a';
		REP (i, 1, n + 1) {
			REP (j, 0, MAXA) {
				if (j < a[i]) {
					ans[i] += ans[i - 1][j];
				} else {
					ans[i] += ans[i - 1][j] == 'a' ? 'b' : 'a';
				}
			}
		}
		REP (i, 0, n + 1) {
			printf("%s\n", ans[i].c_str());
			ans[i] = "";
		}
	}
	return 0;
}