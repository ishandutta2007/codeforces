#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 15;

int n, m, c, E, vis[M], cc[M], e[M], f[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
    n = read();
    m = read();
    c = read();
    E = read();
    for (int i = 0; i < m; i ++) 
    {
        int a, b; 
        a = read();
        b = read();
        cc[i] = read();
        e[i] = read();
        vis[i] = a / b;
    }
    for (int i = 0; i + c <= n; i ++)
    	f[i + c] = max(f[i + c], f[i] + E);
    for(int i = 0; i < m; i ++)
    	for (int j = n; j >= 0; j --)
          	for (int l = 1; l <= vis[i] && j - l * cc[i] >= 0; l ++)
             	f[j] = max(f[j], f[j - l * cc[i]] + l * e[i]);
    cout << f[n] << endl;
    return 0;
}