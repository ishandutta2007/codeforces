#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
int a[100010];
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
	k = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for(int i = 2; i <= n; i ++)
	{
		int cha = a[i] - a[1];
		if(cha % k != 0) {cout << -1; return 0;}
		ans += cha / k;
	}
	cout << ans;
	return 0;
}