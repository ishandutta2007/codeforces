#include<bits/stdc++.h>
using namespace std;

signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	unordered_map <int , bool> used;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		used[a[i]] = 1;
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		int ans = 1e9;
		for(int i = 0; i < n; i++)
		{
			for(int d = 0; d <= k; d++)
			{
				if(x < a[i] * d)
				{
					break;
				}
				if(a[i] * d == x)
				{
					ans = min(ans, d);
					break;
				}
				for(int t = 1; t + d <= k; t++)
				{
					if((x - a[i] * d) % t == 0 && used[(x - a[i] * d) / t])
					{
						ans = min(ans, t + d);
					}
				}
			}
		}
		if(ans == 1e9)
		{
			ans = -1;
		}
		cout << ans << "\n";
	}
    return 0;
}