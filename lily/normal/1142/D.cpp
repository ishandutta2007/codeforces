#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define N 100105

int n, l[N];
LL dp[N][11], ans = 0;
int c[N];
char s[N];

int main() {
	scanf("%s", s + 1);
	n = (int)strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		int k = s[i] - '0';
		if (k) dp[i][k] = 1;

		for (int j = 0; j < 11; j++) if (dp[i - 1][j]) {
			int nx = j * (j - 1) / 2 + 9; 
			if (k < j % 11) dp[i][(nx + k + 1) % 11] += dp[i - 1][j];
		}
		for (int j = 0; j < 11; j++) ans += dp[i][j];
	}
	cout << ans << endl;
	return 0;
}