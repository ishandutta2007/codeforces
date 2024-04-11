#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;
const int N = 5000 + 10;
const int oo = 0x3f3f3f3f;
int n, x[N];
pair<int, int> task[N];
int dp1[N][N], dp2[N][N];
void chkmax(int &x, int y) {
	if(x < y) x = y;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &task[i].x, &task[i].y);
		x[i] = task[i].y;
	}
	int tot = n + 1;
	x[tot] = 0;
	task[0].x = 0, task[0].y = 0;
	sort(x + 1, x +  tot + 1);
	tot = unique(x + 1, x + tot + 1) - (x + 1);
	for(int i = 0; i <= n; i++) task[i].y = lower_bound(x + 1, x + tot + 1, task[i].y) - x;
	sort(task + 0, task + n + 1);
	memset(dp1, 0xc0, sizeof(dp1));
	memset(dp2, 0xc0, sizeof(dp2));
	dp1[0][task[0].y] = dp2[0][task[0].y] = 0;
	for(int i = 0; i < n; i++) {
		// for(int j = 1; j <= tot; j++) cout << dp1[i][j] <<" ";
		// cout << endl;
		// for(int j = 1; j <= tot; j++) cout << dp2[i][j] <<" ";
		// cout << endl;
		int d = task[i + 1].x - task[i].x, p = task[i].y, q = task[i + 1].y;
		int zero = -oo;
		for(int j = 1; j <= tot; j++) chkmax(zero, dp1[i][j]);
		for(int j = 1; j <= tot; j++) if(dp2[i][j] >= 0) dp2[i][j] += d;
		for(int j = 2; j <= tot; j++) if(dp2[i][j - 1] - (x[j] - x[j - 1]) >= 0) chkmax(dp2[i][j], dp2[i][j - 1] - (x[j] - x[j - 1]));
		for(int j = tot - 1; j >= 1; j--) if(dp2[i][j + 1] - (x[j + 1] - x[j]) >= 0) chkmax(dp2[i][j], dp2[i][j + 1] - (x[j + 1] - x[j]));
		for(int j = 1; j <= tot; j++) {
			if(dp1[i][j] < 0) continue;
			if(abs(x[q] - x[p]) <= d) chkmax(dp1[i + 1][j], 0);
			if(j == q) chkmax(dp2[i + 1][p], d);
			if(zero >= 0 && (ll)abs(x[j] - x[p]) + abs(x[j] - x[q]) <= d) chkmax(dp1[i + 1][j], 0);
			if(zero >= 0 && abs(x[q] - x[p]) <= d) chkmax(dp2[i + 1][q], d - abs(x[q] - x[p]));
		}
		for(int j = 1; j <= tot; j++) {
			if(dp2[i][j] < 0) continue;
			if(abs(x[j] - x[q]) <= dp2[i][j]) chkmax(dp1[i + 1][p], 0);
			if(abs(x[j] - x[q]) <= min(dp2[i][j], d)) chkmax(dp1[i + 1][j], 0);
			if(p == q) chkmax(dp2[i + 1][j], dp2[i][j]);
			if(j == q) chkmax(dp2[i + 1][j], min(dp2[i][j], d));
		}
	}
	int ans = -oo;
	for(int i = 1; i <= tot; i++) {
		chkmax(ans, max(dp1[n][i], dp2[n][i]));
	}
	if(ans >= 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}