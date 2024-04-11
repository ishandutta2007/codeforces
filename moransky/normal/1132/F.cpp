#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath> 
using namespace std;
const int N = 510;
int n, f[N][N];
char s[N];
int main(){
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i++) f[i][i] = 1;
	for(int l = 2; l <= n; l++){
		for(int i = 1, j; (j = i + l - 1) <= n; i++){
			f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
			for(int k = i; k <= j - 1; k++){
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j - 1] + (s[k] != s[j]));
			}
			for(int k = i + 1; k <= j; k++){
				f[i][j] = min(f[i][j], f[i + 1][k - 1] + f[k][j] + (s[k] != s[i]));
			}
		}
	} 
	printf("%d\n", f[1][n]);
	return 0;
}