#include <cstdio>
#include <iostream>
using namespace std;
const int N = 505;
int n, m, ans = 0;
char g[N][N];
int Left[N][N], Right[N][N];
int Down[N][N], Up[N][N];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(g[i][j] == '.') continue;
			Left[i][j] = g[i][j - 1] == '*' ? Left[i][j - 1] + 1 : 1;
			Up[i][j] = g[i - 1][j] == '*' ? Up[i - 1][j] + 1 : 1; 
		}
	}
	for(int i = n; i; i--) {
		for(int j = m; j; j--) {
			if(g[i][j] == '.') continue;
			Down[i][j] = g[i + 1][j] == '*' ? Down[i + 1][j] + 1 : 1;
			Right[i][j] = g[i][j + 1] == '*' ? Right[i][j + 1] + 1 : 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(g[i][j] == '*' && ans > 0) {
				puts("NO"); return 0;
			}
			if(g[i][j] == '*') {
				if(min(min(Left[i][j], Up[i][j]), min(Right[i][j], Down[i][j])) > 1) {
					ans++;
					int x = i, y = j;
					while(Left[x][y]--) g[x][y--] = '.';
					x = i, y = j;
					while(Right[x][y]--) g[x][y++] = '.';
					x = i, y = j;
					while(Up[x][y]--) g[x--][y] = '.';
					x = i, y = j; 
					while(Down[x][y]--) g[x++][y] = '.';
				} 
			} 
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			if(g[i][j] == '*') {
				puts("NO"); return 0;
			}
	puts(ans == 1 ? "YES" : "NO");
	return 0;
}