#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;

signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	vector <int> p(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}
	int c = 0;
	for(int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		c += b;
	}
	ans += 1 - (c & 1);
	vector <bool> used(n);
	int cnt1 = 0;
	for(int i = 0; i < n; i++)
	{
		int st = i;
		if(!used[i])
		{
			while(!used[st])
			{
				used[st] = 1;
				st = p[st];
			}
			cnt1++;
		}
	}
	if(cnt1 != 1)
	{
		ans += cnt1;
	}
	cout << ans;
	return 0;
}