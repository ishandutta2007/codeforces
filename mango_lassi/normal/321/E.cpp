#include <iostream>
#include <stdio.h>

const int N = 4000;
const int K = 800;
const int inf = 1e9;
int dp[N+1][K]; // dp[i][j] = cost to do interval [0, i[ with j segments
int pen[N][N];
int cost[N][N];

// calculates for all values in interval [is,ie] their dp[i+1][k] values, if the optimal places to split are in the interval [os,oe]
void calc(int k, int is, int ie, int os, int oe) {
	if (ie < is) return;
	int mid = (is + ie) / 2;
	dp[mid+1][k] = inf;
	int opt = -1;
	for (int i = os; i <= std::min(mid, oe); ++i) {
		if (dp[i][k-1] + cost[i][mid] < dp[mid+1][k]) {
			opt = i;
			dp[mid+1][k] = dp[i][k-1] + cost[i][mid];
		}
	}
	if (is != ie) {
		calc(k, is, mid-1, os, opt);
		calc(k, mid+1, ie, opt, oe);
	}
}

int main() {
	int n, k;
	std::cin >> n >> k;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			char c = ' ';
			while(c == '\n' || c == ' ') c = getchar();
			pen[x][y] = (c-'0');
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < a; ++b) {
			cost[a][b] = 0;
		}
	}
	for (int j = 0; j < k; ++j) dp[0][j] = 0;
	for (int b = 0; b < n; ++b) {
		for (int a = b; a >= 0; --a) {
			if (a == b) {
				cost[a][b] = 0;
			} else {
				cost[a][b] = cost[a][b-1] + cost[a+1][b] - cost[a+1][b-1] + pen[a][b];
			}
		}
		dp[b+1][0] = cost[0][b];
	}
	for (int j = 1; j < k; ++j) {
		calc(j,0,n-1,0,n-1);
	}
	std::cout << dp[n][k-1] << '\n';
}