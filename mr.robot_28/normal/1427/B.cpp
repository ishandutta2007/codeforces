#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	string s;
    	cin >> s;
    	int ans = 0;
    	vector <int> mass;
    	int sum1 = 0, sum2 = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == 'L')
    		{
    			int j = i;
    			while(j < n && s[j] == 'L')
    			{
    				j++;
				}
				if(j != n && i != 0)
				{
					mass.push_back(j - i);
				}
				else if(i == 0)
				{
					sum1 = j - i;
				}
				else
				{
					sum2 = j - i;
				}
				i = j - 1;
			}
			else
			{
				ans++;
				int j = i;
				while(j < n && s[j] == 'W')
				{
					j++;
				}
				ans += 2 * (j - i - 1);
				i = j - 1;
			}
		}
		sort(mass.begin(), mass.end());
		for(int i = 0; i < mass.size(); i++)
		{
			if(mass[i] <= k)
			{
				k -= mass[i];
				ans += 2 * mass[i];
				ans++;
			}
			else
			{
				ans += 2 * k;
				k = 0;
			}
		}
		if(ans == 0)
		{
			ans = max(0LL, 2 * k - 1);
			k = 0;
		}
		int t = min(k, sum2);
		k -= t;
		ans += 2 * t;
		if(k != 0)
		{
			ans += 2 * max(0LL, min(sum1, k));
		}
		cout << ans << "\n";
	}
    return 0;
}