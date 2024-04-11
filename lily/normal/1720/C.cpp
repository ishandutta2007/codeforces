#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 505;
int n, m;
int dp[N];
char s[N][N];

void work() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			ans += s[i][j] == '1';
	int w = 4;
	for (int xl = 0; xl <= n - 2; xl++) {
		for (int yl = 0; yl <= m - 2; yl++) {
			int c = 0;
			for (int i = 1; i <= 2; i++) {
				for (int j = 1; j <= 2; j++) {
					c += s[xl + i][yl + j] == '1';
				}
			}
			w = min(w, c);
		}
	}
	
	printf("%d\n", ans - max(0, w - 2));
}


int main() {
	int T;
	read(T);
	while (T--) work();
}