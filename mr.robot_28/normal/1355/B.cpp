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
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int cnt = 0;
		int sum = 0;
		int maxd = 0;
		for(int i = 0; i < n; i++)
		{
			sum++;
			maxd = max(maxd, a[i]);
			if(maxd == sum)
			{
				cnt++;
				sum = 0;
			}
		}
		cout << cnt << "\n";
	}
    return 0;
}