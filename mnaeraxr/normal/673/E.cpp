#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

double A[maxn], B[maxn], C[maxn];

double calc(int b, int e){
	b--;
	return - 1.0 * B[b] * (A[e] - A[b]) + C[e] - C[b];
}

int opt[maxn];
double dp[2][maxn];

void compute(int b, int e, int optB, int optE){
	int m = (b + e) / 2;

	dp[1][m] = calc(m, m) + dp[0][m - 1];
	opt[m] = m;

	for (int i = optB; i <= min(optE, m - 1); ++i){
		double val = calc(i, m) + dp[0][i - 1];
		if (val < dp[1][m]){
			dp[1][m] = val;
			opt[m] = i;
		}
	}

	if (b < m) compute(b, m - 1, optB, opt[m]);
	if (m < e) compute(m + 1, e, opt[m], optE);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i){
		double v; cin >> v;
		A[i] = A[i - 1] + 1.0 / v;
		B[i] = B[i - 1] + v;
		C[i] = C[i - 1] + B[i] / v;
	}

	for (int i = 1; i <= n; ++i)
		dp[0][i] = calc(1, i);

	for (int i = 2; i <= min(k, n); ++i){
		compute(i, n, i, n);
		for (int j = i; j <= n; ++j)
			dp[0][j] = dp[1][j];
	}

	cout.precision(17);
	cout << fixed << dp[0][n] << endl;

	return 0;
}
/*
6 2
1 2 4 8 16 32
 */