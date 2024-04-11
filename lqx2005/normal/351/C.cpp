#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define PI pair<int, int>
#define pb push_back
using namespace std;
typedef long long i64;
typedef double db;
const int N = 30, M = N * 2;
int n, m;
int a[N], b[N];
i64 dp[N][N][N * 2];
void chkmin(i64 &x, i64 y) {if(x > y) x = y; }
struct Mat {
	i64 a[M][M];
	Mat() {memset(a, 0x3f, sizeof(a)); }
	friend Mat operator * (const Mat a, const Mat b) {
		Mat c;
		for(int i = 0; i < n * 2; i++) {
			for(int j = 0; j < n * 2; j++) {
				for(int k = 0; k < n * 2; k++) {
					chkmin(c.a[i][j], a.a[i][k] + b.a[k][j]);
				}
			}
		}
		return c;
	}
}trans, start;

Mat power(Mat a, int b, Mat c) {
	for(; b; b >>= 1, a = a * a)
		if(b & 1)
			c = c * a;
	return c;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][n] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = -i; k <= i; k++) {
				chkmin(dp[i + 1][max(j, - (k + 1))][k + 1 + n], dp[i][j][k + n] + a[i]);
				chkmin(dp[i + 1][max(j, - (k - 1))][k - 1 + n], dp[i][j][k + n] + b[i]); 
			}
		}
	}
	for(int i = 0; i < n * 2; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = -i; k < n * 2 - i; k++) {
				chkmin(trans.a[i][i + k], dp[n][j][k + n]);
			}
		}
	}
//	for(int i = 0; i < n * 2; i++) {
//		for(int j = 0; j < n * 2; j++) {
//			printf("%d ", trans.a[i][j]);
//		}
//		printf("\n");
//	}
	start.a[0][0] = 0;
	start = power(trans, m, start);
	printf("%lld\n", start.a[0][0]);
	return 0;
}