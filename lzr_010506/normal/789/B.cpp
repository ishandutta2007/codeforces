#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll b1, q, l, m;
ll a[100010], b[100010];
map<int, int> mp;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	b1 = read();
	q = read();
	l = read();
	m = read();
	for(int i = 1; i <= m; i ++)
		a[i] = read(), mp[a[i]] = 1;
	b[1] = b1;
	int n = 1;
	int x = 0;
	while(max(-b[n], b[n]) <= l && n <= 100000)
	{
		if(mp[b[n]]) x ++;
		n ++;
		b[n] = b[n - 1] * q;
	}
	int ans = n - 1 - x;
	if(n >= 100000 && ans >= 2) cout << "inf";
	else cout << ans;
	return 0;
}