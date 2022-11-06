#include <bits/stdc++.h>
using namespace std;

int n, m, p[200010], a[200010], b[200010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
set<pair<int, int> > st[4];
int main()
{
	n = read();
	for(int i = 1; i <= n; i ++) p[i] = read();
	for(int i = 1; i <= n; i ++) a[i] = read(), st[a[i]].insert(make_pair(p[i], i));
	for(int i = 1; i <= n; i ++) b[i] = read(), st[b[i]].insert(make_pair(p[i], i));
	int Q = read();
	while(Q --)
	{
		int x = read();
		if(st[x].empty()) cout << -1 << " ";
		else
		{
			int now = (*st[x].begin()).second;
			cout << p[now] << " ";
			st[a[now]].erase(make_pair(p[now], now));
			st[b[now]].erase(make_pair(p[now], now));

		}
	}

	return 0;
}