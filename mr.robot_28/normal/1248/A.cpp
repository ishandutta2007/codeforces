#include <bits/stdc++.h>

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
		int n, m;
		cin >> n;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		for(int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			if(x % 2 == 0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			if(x % 2 == 0)
			{
				cnt3++;
			}
			else
			{
				cnt4++;
			}
		}
		cout << cnt1 * cnt3 + cnt2 * cnt4 << "\n";
	}
    return 0;
}