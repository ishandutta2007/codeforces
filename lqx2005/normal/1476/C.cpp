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
int n;
int a[N], b[N], c[N];
ll dp[N];
void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]), c[i]--;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	for(int i = 0; i <= n; i++) dp[i] = 0;
	dp[n] = c[n];
	ll mx = 0;
	for(int i = n - 1; i >= 1; i--) {
		mx = max(mx, dp[i + 1] + 2 + abs(a[i + 1] - b[i + 1]));
		dp[i] = c[i];
		if(a[i + 1] != b[i + 1]) {
			dp[i] = max(dp[i], dp[i + 1] + c[i] - abs(a[i + 1] - b[i + 1]) + 2);
		}
	}
	printf("%lld\n", mx);
	return;
}
int main() {
	int t;
	scanf("%d", &t);
	for(; t--; ) work();
	return 0;
}