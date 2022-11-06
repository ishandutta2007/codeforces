#include <bits/stdc++.h>
using namespace std;
int n, ans;
int f[10010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
        f[i] = i;
	for(int i = 1; i <= n; i ++)
	{
		int x = read();
		int a = find(i);
		int b = find(x);
		if(a == b) continue;
		f[a] = b;
	}

	for(int i = 1; i <= n; i ++)
		if(f[i] == i) ans ++;
	cout << ans;
	return 0;
}