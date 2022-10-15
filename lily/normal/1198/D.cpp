#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


int n;
char S[55];
int b[55][55];
int dp[51][51][51][51];

int sum(int u, int v, int w, int x) {
	return b[w][x] - b[u - 1][x] - b[w][v - 1] + b[u - 1][v - 1];
}

int s(int u, int v, int w, int x) {
	if (dp[u][v][w][x]) return dp[u][v][w][x] - 1;
	if (sum(u, v, w, x) == 0) return (dp[u][v][w][x] = 1) - 1;
	int ret = max(w - u + 1, x - v + 1);
	for (int i = u; i < w; i++) ret = min(ret, s(u, v, i, x) + s(i + 1, v, w, x));
	for (int i = v; i < x; i++) ret = min(ret, s(u, v, w, i) + s(u, i + 1, w, x));
	return (dp[u][v][w][x] = ret + 1), ret;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", S + 1);
		for (int j = 1; j <= n; j++) {
			b[i][j] = S[j] == '#';
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
		}
	}
	cout << s(1, 1, n, n) << endl;
}