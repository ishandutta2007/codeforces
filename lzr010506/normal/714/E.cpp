#include <bits/stdc++.h>
#define N 3010
#define ll long long
using namespace std;
ll f[N], g[N];
int n, a[N],s[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline ll min(ll a, ll b)
{
	if(a < b) return a;
	return b;
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 1; i <= n; i ++) 
		a[i] -= i, s[i] = a[i];
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		g[1] = f[1] + abs(s[1] - a[i]);
		for(int j = 2; j <= n; j ++)
			g[j] = min(g[j - 1], f[j] + abs(a[i] - s[j]));
		swap(g, f);
	}
	long long ans = 0x7f7f7f7f7f7f7f7fLL;
	for(int i = 1; i <= n; i ++)
		ans = min(ans, f[i]);
	cout<<ans<<endl;
	return 0;
}