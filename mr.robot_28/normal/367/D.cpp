# include <bits/stdc++.h>
using namespace std;
int n, m, d;
vector <int> indx;
vector <int> ft;
vector <bool> used;
void undermask(int mask)
{
	if(used[mask])return;
	used[mask] = true;
	for(int i = 0; i < m; i++)
	{
		if((mask & (1 << i)) != 0)
		{
			undermask(mask ^ (1 << i));
		}
	}
}
signed main()
{
	cin >> n >> m >> d;
	indx.resize(n);
	ft.resize(m);
	used.resize((1 << m), false);
	for(int i= 0; i < m; i++)
	{
		int a;
		cin >> a;
		for(int j = 0; j < a; j++)
		{
			int g;
			cin >> g;
			indx[g - 1] = i;
		}
	}
	for(int i = 0; i < m; i++)
	{
		ft[i] = 0;
	}
	int r = 0;
	for(int i = 0; i <= n - d; i++)
	{
		while(r < i + d)
		{
			ft[indx[r]]++;
			r++;
		}
		int mask = 0;
		for(int j = 0; j < m; j++)
		{
			if(ft[j] == 0)
			{
				mask |= (1 << j);
			}
		}
		undermask(mask);
		ft[indx[i]]--;
	}
	int ans = m;
	for(int i = 0; i < (1 << m); i++)
	{
		if(!used[i])
		{
			ans = min(ans, __builtin_popcount(i));
		}
	}
	cout << ans;
	return 0;
}