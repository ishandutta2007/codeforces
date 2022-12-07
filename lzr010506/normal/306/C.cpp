#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4005;
const int P = 1e9 + 9;
int c[N][N], fact[N], n, w, b;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
 	fact[0] = 1;
 	for(int i = 1; i < N; i ++) fact[i] = 1LL * fact[i - 1] * i % P;
 	for(int i = 0; i < N; i ++)
    	for(int j = c[i][0] = 1; j <= i; j ++)
    	{
      		c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
     		 if (c[i][j] >= P) c[i][j] -= P;
    	}
    n = read();
    w = read();
    b = read();
	int ans = 0;
	for(int i = 2; i <= n; i ++)
		for(int j = i; j < n; j ++)
		{
			int len = j - i + 1;
			if(n - len - 1 >= 0) ans = (ans + (1LL * fact[b] * c[b - 1][len - 1] % P) * (1LL * fact[w] * c[w - 1][n - len - 1] % P)) % P;
		}
	printf("%d", ans);
	return 0;
}