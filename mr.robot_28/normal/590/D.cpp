#include<bits/stdc++.h>
using namespace std;

signed main() {	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, k, s;
	cin >> n >> k >> s;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	s = min(s, n * n);
	vector <vector <int> > dp1(k + 1, vector <int> (s + 1, 1e9));
	dp1[0][0] = 0;
	int ans = 1e9;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int c = k; c >= 0; c--)
		{
			for(int j = s; j >= 0; j--)
			{
				if(j + c <= s)
				{
					dp1[c][j + c] = min(dp1[c][j + c], dp1[c][j]);
				}
				if(c + 1 <= k)
				{
					dp1[c + 1][j] = min(dp1[c + 1][j], dp1[c][j] + a[i]);
				}
				if(c != 0)
				{
					dp1[c][j] = 1e9;
				}
			}
		}
	}
	for(int j = 0; j <= s; j++)
	{
		ans = min(ans, dp1[k][j]);
	}
	cout << ans;
    return 0;
}