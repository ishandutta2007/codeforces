#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int mat[5000][5000];

int bdp[5000][900];
int counter = 0;

int dp[5000][900];
int opt[5000][900];


void calc(int b, int e, int optL, int optR, int k){
	int m = (b + e) >> 1;

	opt[m][k] = optL;

	for (int i = optL; i <= min(optR, m); ++i){
		int val = dp[i - 1][k - 1] + mat[m][m] - mat[i - 1][m];
		counter++;

		if (val < dp[m][k]){
			dp[m][k] = val;
			opt[m][k] = i;
		}
	}

	if (m > b) calc(b, m - 1, optL, opt[m][k], k);
	if (e > m) calc(m + 1, e, opt[m][k], optR, k);
}

void solve(int N, int K){
	memset(dp, oo, sizeof dp);

	for (int i = 1; i <= N; ++i)
		dp[i][1] = mat[i][i];

	for (int k = 2; k <= K; ++k)
		calc(1, N, 1, N, k);


	printf("%d\n", dp[N][K]);
}

char buf[4000 * 3];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	getchar();

	for (int i = 1; i <= n; ++i){
		gets(buf);
		for (int j = 1; j <= n; ++j){
			if (j > i) mat[i][j] = buf[(j - 1) * 2] - '0';
			mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
		}
	}

	solve(n, k);

	return 0;
}