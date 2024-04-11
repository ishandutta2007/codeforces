#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 85
const int INF = 0x3f3f3f3f;
int n, K;
int a[N][N];
bool b[N];
int dp[N][11], ans = INF;

void work() {
	for (int i = 1; i <= n / 2; i++) b[i] = 1;
	for (int i = n / 2 + 1; i <= n; i++) b[i] = 0;
	random_shuffle(b + 1, b + n + 1);
	for (int i = 0; i <= K; i++)
		for (int j = 0; j <= n; j++) {
			dp[j][i] = INF;
		}
	dp[1][0] = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= n; j++) if (dp[j][i] < INF){
			for (int k = 1; k <= n; k++) if (b[j] ^ b[k]) {
				dp[k][i + 1] = min(dp[k][i + 1], dp[j][i] + a[j][k]); 
			}
		}
	}
	ans = min(ans, dp[1][K]);
}

int main() {
	read(n); read(K);
	srand(19260817 + n + K);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			read(a[i][j]);
		}
	}
	int T = 3000;
	while (T--) work();
	cout << ans << endl;
}