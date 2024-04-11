#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
int n, a[N], b[N], tot = 0;
int dp[N], mx[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] != a[i - 1]) {
			b[++tot] = a[i];
		}
	}
	for(int i = 1; i <= tot; i++) a[i] = b[i];
	n = tot;
	int pmx = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = mx[a[i]] + 1;
		dp[i] = max(dp[i], pmx);
		pmx = max(pmx, dp[i]);
		mx[a[i - 1]] = max(dp[i], mx[a[i - 1]]);
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res = max(res, dp[i]);	
	printf("%d\n", tot - res + 1);
	return 0;
}