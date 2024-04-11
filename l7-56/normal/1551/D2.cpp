#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
bool ff[maxn][maxn][maxn * maxn >> 1];
bool vis[maxn][maxn][maxn * maxn >> 1];
int f(int n, int m, int k){
	if(vis[n][m][k]) return ff[n][m][k];
	vis[n][m][k] = 1;
	if(n == 0 || m == 0) return ff[n][m][k] = 1;
	ff[n][m][k] = 0;
	if(m % 2 == 0 && m <= k * 2) ff[n][m][k] |= f(n - 1, m, k - (m >> 1));
	if(n % 2 == 0 && n <= (n * m / 2 - k) * 2) ff[n][m][k] |= f(n, m - 1, k);
	return ff[n][m][k];
}// n*mk

int t,n,m,k;
char ans[maxn][maxn];

void mark(int n, int m, int k){
	if(n & 1){
		for(int i = 1; i < m; i += 2) ans[n][i] = ans[n][i + 1] = (i / 2 & 1) ? 'a' : 'b';
		mark(n - 1, m, k - m / 2);
		return;
	}
	if(m & 1){
		for(int i = 1; i < n; i += 2) ans[i][m] = ans[i + 1][m] = (i / 2 & 1) ? 'c' : 'd';
		mark(n, m - 1, k);
		return;
	}
	for(int i = 2; i <= n; i += 2)
		for(int j = 2; j <= m; j += 2){
			if(k){
				ans[i - 1][j - 1] = ans[i - 1][j] = (j / 2 & 1) ? 'e' : 'f';
				ans[i][j - 1] = ans[i][j] = (j / 2 & 1) ? 'f' : 'e';
				k -= 2;
			}
			else {
				ans[i - 1][j - 1] = ans[i][j - 1] = (i / 2 & 1) ? 'g' : 'h';
				ans[i - 1][j] = ans[i][j] = (i / 2 & 1) ? 'h' : 'g';
			}
		}
	
		
	return;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		if(f(n, m, k)) {
			printf("YES\n");
			mark(n, m, k);
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= m; ++j)
					putchar(ans[i][j]);
				putchar('\n');
			}
		}
		else printf("NO\n");
	}
	return 0;
}