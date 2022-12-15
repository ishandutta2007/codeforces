#include <bits/stdc++.h>

using namespace std;

#define N 222222


int n, m, q;
int r[N], s[N], pre[N], pos[N], answer[N];
int p[N][22];

void init()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		cin >> r[i];

	for (int i = 1; i <= n; i++)
		pre[r[i % n + 1]] = r[i];

	for (int i = 1; i <= m; i++)
		cin >> s[i];

	for (int i = 1; i <= m; i++)
	{
		p[i][0] = pos[pre[s[i]]];
		pos[s[i]] = i;
	}
	for (int j = 1; j <= 18; j++)
		for (int i = 1; i <= m; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];

	for (int i = 1; i <= m; i++)
	{
		int x = i;
		for (int j = 0; j <= 18; j++)
			if ((n - 1) & (1 << j))
				x = p[x][j];
		answer[i] = max(answer[i - 1], x);
	}

}

void solve()
{
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		if (answer[r] >= l)
			printf("1");
		else
			printf("0");
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();

	return 0;
}