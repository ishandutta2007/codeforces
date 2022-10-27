#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		int maxto = 1e9;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool flag = true;
		maxto = a[0];
		for(int i = 0; i < n; i++)
		{
			cin >> b[i];
			if(i == n - 1)
			{
				continue;
			}
			if(i == 0)
			{
				int e = min(a[i + 1], b[i]);
				a[i + 1] -= e;
				a[i] -= min(a[i], (b[i] - e));
				maxto = min(maxto, min(e, a[0]));
			}
			else
			{
				if(a[i] - b[i] > 0)
				{
					flag = false;
				}
				int e = min(a[i], b[i]);
				a[i] -= e;
				int t = min(b[i] - e, a[i + 1]);
				a[i + 1] -= t;
				if(t < b[i] - e)
				{
					a[0] -= min(maxto, b[i] - e - t);
					maxto -= min(maxto, b[i] - e - t);
				}
				maxto = min(maxto, t);
			}
		}
		if(!flag || b[n - 1] < a[0] + a[n - 1])
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
    return 0;
}