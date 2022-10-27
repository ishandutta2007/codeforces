#include <bits/stdc++.h>
 
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> p(n);
	vector <int> maxval(m);
	vector <int> s(n);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
		maxval[p[i]] = max(maxval[p[i]], s[i]);
	}
	int cnt = 0;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		x--;
		if(s[x] != maxval[p[x]])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}