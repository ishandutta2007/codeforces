#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, p[110];
int dp[110][110][2];
void upd(int &a, int b) { if(a > b) a = b; }

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", p + i);
	rep(i, 110) rep(j, 110) dp[i][j][0] = dp[i][j][1] = 1e9;
	if(p[1] == 0) {
		dp[1][1][0] = 0;
		dp[1][0][1] = 0;
	}
	else if(p[1] % 2) dp[1][0][1] = 0;
	else dp[1][1][0] = 0;
	for(int i=1;i<n;i++) for(int j=0;j<=i;j++) rep(v, 2) {
		if(dp[i][j][v] > 1e8) continue;
		int val = p[i+1];
		if(val == 0) {
			upd(dp[i+1][j+1][0], dp[i][j][v] + (v != 0));
			upd(dp[i+1][j][1], dp[i][j][v] + (v != 1));
		}
		else if(val % 2) upd(dp[i+1][j][1], dp[i][j][v] + (v != 1));
		else upd(dp[i+1][j+1][0], dp[i][j][v] + (v != 0));
	}
	printf("%d\n", min(dp[n][n/2][0], dp[n][n/2][1]));
	return 0;
}