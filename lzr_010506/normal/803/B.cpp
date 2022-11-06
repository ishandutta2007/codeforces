#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, f[200010];
int main()
{
	n = read(); 
	f[0] = f[n + 1] = 1e9;
	for(int i = 1; i <= n; i ++) 
	{
		int x = read();
		if(x) f[i] = 1e9; 
		else f[i] = 0;
	}
	for(int i = n; i >= 1; i --) f[i] = min(f[i], f[i + 1] + 1);
	for(int i = 1; i <= n; i ++) f[i] = min(f[i], f[i - 1] + 1);
	for(int i = 1; i <= n; i ++) cout << f[i] << " "; 
	return 0;
}