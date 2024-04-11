#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 505, P = 1e9 + 7;
int n, a[N][N], f[N][N][2];
/*
 f[i][j][1 / 0] [i, j]  /  

f[i][j][0] = sum{ f[i][k][1] * f[k][j][0] } 
f[i][j][1] = sum{ f[i][k][0] * f[k + 1][r][0] }

ans = f[1][n][0] + f[1][n][1] 
*/
int inline add(int x, int y) {
	return (LL)(x + y) % P;
}
int inline mul(int x, int y) {
	return (LL)x * y % P; 
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	
	for (int i = 1; i <= n; i++) {
		f[i][i][0] = 1; 
		if(a[i][i + 1]) f[i][i + 1][0] = f[i][i + 1][1] = 1;
	}
	
	for (int l = 3; l <= n; l++) {
		for (int i = 1, j; (j = i + l - 1) <= n; i++) {
			for (int k = i; k <= j; k++)
				if(a[i][k])
					f[i][j][0] = add(f[i][j][0], mul(f[i][k][1], f[k][j][0]));
			if(a[i][j]) for (int k = i; k < j; k++)
				f[i][j][1] = add(f[i][j][1], mul(f[i][k][0], f[k + 1][j][0]));
			f[i][j][0] = add(f[i][j][0], f[i][j][1]);
		}
	}
	printf("%d\n", f[1][n][0]);
	return 0;
}