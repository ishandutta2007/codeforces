#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<int> g[5];

long long d[300055], e[300055];
long long dp[300055];

inline long long f(int have, int use_2) 
{
	long long res = e[use_2 * 2];
	res += d[have - use_2 * 2];
	return res;
}
inline long long gao(int have) 
{
    int lb = -1, ub = have / 2;

	while (ub - lb > 1) 
    {
		int mid = (ub + lb) >> 1;
		if (f(have, mid) < f(have, mid + 1)) lb = mid;
		else ub = mid;
	}

	return f(have, lb + 1);
}
int main() 
{
	scanf("%d %d", &n, &w);

	for (int i = 0; i < n; i++) 
    {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
	}

	for (int i = 1; i <= 3; i++) 
    {
		sort(g[i].begin(), g[i].end());
		reverse(g[i].begin(), g[i].end());
	}

	for (int i = 0; i < (int)g[1].size(); i++) 
    {
		d[i + 1] = 1ll * g[1][i];
		d[i + 1] += d[i];
	}

	for (int i = 0; i < (int)g[2].size(); i++) 
        {
		e[(i + 1) * 2] =1ll * g[2][i];
		if (i) e[(i + 1) * 2] += e[i * 2];
	}

	for (int i = 1; i <= w; i++) 
    {
		e[i] = max(e[i], e[i - 1]);
		d[i] = max(d[i], d[i - 1]);
	}

	long long res = 0ll;

	for (int i = 1; i <= w; i++) 
		dp[i] = max(dp[i - 1], gao(i));

	long long ac = 0ll;

	for (int i = 0; i <= w / 3; i++) 
    {
		res = max(res, ac + dp[w - i * 3]);
		if (i == g[3].size()) break;
		ac += g[3][i];
	}

	cout << res;

	return 0;
}