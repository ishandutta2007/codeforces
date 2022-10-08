#include <cstdio>

int dp[(1 << 24) + 5];
int p1[(1 << 24) + 5];
int p2[(1 << 24) + 5];

int n;

int dist[25][25];

int px[25], py[25];

int sx, sy;

int sq(int x) {
	return x * x;
}

int s[100005], ss;

int main() {
	scanf("%d %d", &sx, &sy);
	scanf("%d", &n);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &px[i], &py[i]);
	}	
	for (int i = 0; i < n; ++i) {
		dist[n][i] = dist[i][n] = sq(px[i] - sx) + sq(py[i] - sy);
		for (int j = 0; j < n; ++j) {
			dist[i][j] = sq(px[i] - px[j]) + sq(py[i] - py[j]);
		}
	}
	for (int i = 1; i < (1 << n); ++i) {
		dp[i] = 1000000000;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				int cc = dp[i ^ (1 << j)] + 2 * dist[n][j];
				if (cc < dp[i]) {
					dp[i] = cc;
					p1[i] = j;
					p2[i] = -1;
				}
				for (int k = 0; k < n; ++k) {
					if (j != k && ((i >> k) & 1)) {
						int cc = dp[i ^ (1 << j) ^ (1 << k)] + dist[n][j] + dist[j][k] + dist[k][n];
						if (cc < dp[i]) {
							dp[i] = cc;
							p1[i] = j;
							p2[i] = k;
						}
					}
				}
				break;
			}
		}
	}
	int c = (1 << n) - 1;
	printf("%d\n", dp[c]);
	s[ss++] = n;
	while (c != 0) {
		int nx = c;
		if (p2[c] >= 0) {
			s[ss++] = p2[c];
			nx ^= (1 << p2[c]);
		}
		s[ss++] = p1[c];
		nx ^= (1 << p1[c]);
		s[ss++] = n;
		c = nx;
	}
	for (int i = ss - 1; i > 0; --i)
		printf("%d ", (s[i] + 1) % (n + 1));
	printf("%d\n", (s[0] + 1) % (n + 1));
}