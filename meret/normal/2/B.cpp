#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000;

int n;

int dp2[N + 1][N + 1];
int dp5[N + 1][N + 1];

int alg(int t[N + 1][N + 1], int dp[N + 1][N + 1]){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i > 1 && j > 1) dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + t[i][j];
			else if(i == 1) dp[i][j] = dp[i][j - 1] + t[i][j];
			else dp[i][j] = dp[i - 1][j] + t[i][j];
		}
	}
	return dp[n][n];
}

char s[2 * N - 1];
int ss;

void out(int t[N + 1][N + 1], int dp[N + 1][N + 1]){
	printf("%d\n", dp[n][n]);
	int y = n, x = n;
	while(y > 1 || x > 1){
		if(x != 1 && (y == 1 || dp[y][x - 1] + t[y][x] == dp[y][x])){
			s[ss++] = 'R';
			--x;
		}else{
			s[ss++] = 'D';
			--y;
		}
	}
	reverse(s, s + ss);
	puts(s);
}

int c2[N + 1][N + 1];
int c5[N + 1][N + 1];

int main() {
	scanf("%d", &n);
	int y0 = -1, x0 = -1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int a;
			scanf("%d", &a);
			if(a == 0){
				c2[i][j] = c5[i][j] = 1;
				y0 = i;
				x0 = j;
				continue;
			}
			while(!(a % 2)){
				++c2[i][j];
				a /= 2;
			}
			while(!(a % 5)){
				++c5[i][j];
				a /= 5;
			}
		}
	}
	alg(c2, dp2);
	alg(c5, dp5);
	if(y0 > 0 && min(dp2[n][n], dp5[n][n]) > 1){
		printf("1\n");
		for(int i = 1; i < x0; ++i) putchar('R');
		for(int i = 1; i < y0; ++i) putchar('D');
		for(int i = x0; i < n; ++i) putchar('R');
		for(int i = y0; i < n; ++i) putchar('D');
		return 0;
	}
	if(dp2[n][n] < dp5[n][n]){
		out(c2, dp2);
	}else{
		out(c5, dp5);
	}
};