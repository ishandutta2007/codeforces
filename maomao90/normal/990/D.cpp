#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)
#define ALL(arr) arr.begin(), arr.end()
#define mnto(x, y) x = min(x, y)
#define pb emplace_back
#define FI first
#define SE second
typedef pair<int, int> ii;

#define MAXN 1005
#define INF 1000000005

int n, a, b;
bool matrix[MAXN][MAXN];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	if (a != 1 && b != 1) {
		printf("NO\n");
		return 0;
	}
	if (n >= 2 && n < 4 && a == 1 && b == 1) {
		printf("NO\n");
		return 0;
	}
	bool inv = false;
	if (a == 1) {
		swap(a, b);
		inv = true;
	}
	REP (i, 1, n - a + 1) {
		matrix[i - 1][i] = 1;
		matrix[i][i - 1] = 1;
	}
	if (inv) {
		REP (i, 0, n) {
			REP (j, 0, n) {
				if (i == j) continue;
				matrix[i][j] ^= 1;
			}
		}
	}
	printf("YES\n");
	REP (i, 0, n) {
		REP (j, 0, n) {
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}