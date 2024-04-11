#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m;
long long ans, num = 1;
vector<int> a[1000010];
int main()
{
    //freopen("input.txt", "r", stdin);
	n = read();
	m = read();
	for(int i = 1; i <= n; i ++)
	{
		int x = read();
		for(int j = 1; j <= x; j ++)
		{
			int y = read();
			a[y].push_back(i);
		}
	}
    ans = 1;
	sort(a + 1, a + m + 1);
	for(int i = 2; i <= m; i ++)
	{
		if (a[i] == a[i - 1]) ans = ans * (++ num) % 1000000007;
		else num = 1;
	}
	cout << ans;
	return 0;
}