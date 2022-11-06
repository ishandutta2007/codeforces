#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define inf 1e9+69
using namespace std;

int n, r[20], b[20], c[20], red, blue, rs = 1e9 + 69;
map<pair<int, int>, int> dp[(1 << 16)];
char ch;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) 
	{
		cin >> ch >> r[i] >> b[i];
		if(ch == 'R') c[i] = 1;
	}

	dp[0][mp(0, 0)] = 0;
	for(int mask = 0; mask < (1 << n); mask ++) 
	{
		for(int j = red = blue = 0; j < n; j ++)
			if(mask & (1 << j)) ++(c[j] ? red : blue);

		for(int j = 0; j < n; j ++) 
		{
			if(mask & (1 << j)) continue;
			for(auto it : dp[mask]) 
			{
				int Now = 0, next = (mask | (1 << j));
				if(it.x.x < max(r[j] - red, 0)) Now = max(Now, r[j] - red - it.x.x);
				if(it.x.y < max(b[j] - blue, 0)) Now = max(Now, b[j] - blue - it.x.y);
				pair<int, int> x = mp(it.x.x + Now - max(r[j] - red, 0), it.x.y + Now - max(b[j] - blue, 0));
				if(!dp[next].count(x)) dp[next][x] = inf;
				dp[next][x] = min(dp[next][x], it.y + Now + 1);
			}
		}
	}

	for(auto it : dp[(1 << n) - 1]) rs = min(rs, it.y);

	cout << rs << '\n';

	return 0;
}