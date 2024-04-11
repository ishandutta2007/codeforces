#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 200010, SIZE = 500010, L = 19;
int n, m, maxS = -1, f[SIZE][L];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int l, r; scanf("%d%d", &l, &r);
		f[l][0] = max(f[l][0], r);
		maxS = max(maxS, r);
	}
	for(int i = 1; i <= maxS; i++)
		f[i][0] = max(f[i][0], f[i - 1][0]);
	
	for(int j = 1; j < L; j++)
		for(int i = 0; i <= maxS; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	
	for(int i = 1; i <= m; i++){
		int x, y, ans = 0;  scanf("%d%d", &x, &y);
		for(int i = L - 1; ~i; i--)
			if(f[x][i] < y) x = f[x][i], ans |= 1 << i;
		if(f[x][0] >= y) printf("%d\n", ans + 1);
		else puts("-1");
	}
	return 0;
}