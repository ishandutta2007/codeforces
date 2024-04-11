#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
int n, d, Md, f2[1010][1010][11], ny[1010], f[1010];
int Quick(int a, int b) 
{
	int Now = a, ret = 1; 
	for (; b; b >>= 1, Now = 1LL * Now * Now % Md) if (b & 1) ret = 1LL * ret * Now % Md; 
	return ret;
}
int main() 
{
	cin >> n >> d >> Md;
	if (n <= 2) 
	{
		printf("1");
		return 0; 
	}
	for (int i = 1; i <= 1000; i ++) 
		ny[i] = Quick(i, Md - 2);  
	f[1] = 1; 
	f2[0][0][0] = 1; 
	FOR(W, 0, d) f2[1][W][W] = 1; 
	for (int i = 2; i * 2 <= n; i ++) 
	{ 
		f[i] = f2[i - 1][i - 1][d - 1]; 
		FOR(k, 0, d)
			FOR(j, 0, n)
				if (f2[i - 1][j][k]) 
				{
					int Now = f2[i - 1][j][k]; 
					for (int l = 0; j + l * i <= n && l + k <= d && Now; l ++) 
					{
						f2[i][j + l * i][l + k] += Now;
						if (f2[i][j + l * i][l + k] >= Md) f2[i][j + l * i][l + k] -= Md; 
						Now = 1LL * Now * (f[i] + l) % Md * ny[l + 1] % Md;
					}
				}
	}	
	if (n & 1) printf("%d\n", f2[n >> 1][n - 1][d]); 
	else 
	{
		int ans = f2[(n >> 1) - 1][n - 1][d], Now = f[n >> 1]; 
		Now = 1LL * (Now + 1) * Now % Md * ny[2] % Md; 
		ans = (ans + Now) % Md; 
		printf("%d\n", ans); 
	} 
	return 0;
}