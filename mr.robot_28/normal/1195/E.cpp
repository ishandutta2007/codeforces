#include <bits/stdc++.h>
using namespace std;
#define int long long
struct STRUCT{
	int val, pos;
};
signed main()
{
	int n, m, a, b, x, y, z;
	cin >> n >> m >> a >> b;
	vector <vector <int> > g(n, vector <int> (m));
	cin >> g[0][0] >> x >> y >> z;
	for(int i = 0; i < n; i++)
	{
		if(i != 0)
		{
			g[i][0] = (g[i - 1][m - 1] * x + y) % z;
		}
		for(int j = 1; j < m; j++)
		{
			g[i][j] = (g[i][j - 1] * x + y) % z;
		}
	}
	deque <STRUCT> l;
	vector <vector <int> > Min(n, vector <int> (m, 1e9));
	for(int j = 0; j < m; j++)
	{
		l.clear();
		for(int i = 0;i < a; i++)
		{
			while(!l.empty() && g[i][j] < l.back().val) l.pop_back();
			l.push_back({g[i][j], i});
		}
		for(int i = a - 1; i < n; i++)
		{
			while(!l.empty() && g[i][j] < l.back().val) l.pop_back();
			l.push_back({g[i][j], i});
			while(!l.empty() && i - l.front().pos >= a) l.pop_front();
			Min[i][j] = l.front().val;
		}
	}
	int ans = 0;
	for(int i = a - 1; i < n; i++)
	{
		l.clear();
		for(int j = 0; j < b; j++)
		{
			while(!l.empty() && Min[i][j] < l.back().val)l.pop_back();
			l.push_back({Min[i][j], j});
		}
		for(int j = b - 1; j < m; j++)
		{
			while(!l.empty() && Min[i][j] < l.back().val) l.pop_back();
			l.push_back({Min[i][j], j});
			while(!l.empty() && j - l.front().pos >= b)l.pop_front();
			ans += l.front().val;
		}
	}
	cout << ans;
	return 0;
}