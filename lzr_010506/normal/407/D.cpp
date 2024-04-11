#include <bits/stdc++.h>
using namespace std;
const int N = 400;
int a[N][N], f[N][N];
int hsh[N][160001];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
    int n, m;
    n = read();
    m = read();
    for(int i = 0; i < n; i ++)
    	for(int j = 0; j < m; j ++)
    		a[i][j] = read();
    int ans = 0;
    memset(hsh, -1, sizeof(hsh));
    for(int i = 0; i < n; i ++)
    {
    	for(int len = 0; len < m; len ++)
    		for(int l = 0; l < m - len; l ++)
	        {
	            int r = l + len;
	            if (len) f[l][r] = max(f[l][r], max(f[l][r - 1], f[l + 1][r]));
	            f[l][r] = max(f[l][r], max(hsh[l][ a[i][r] ], hsh[r][ a[i][l] ]) + 1);
	            if (len && a[i][l] == a[i][r]) f[l][r] = i + 1;
	            ans = max(ans, (r - l + 1) * (i - f[l][r] + 1));
	        }
	    for(int j = 0; j < m; j ++)
			hsh[j][ a[i][j] ] = i;
    }
    cout << ans << endl;
    return 0;
}