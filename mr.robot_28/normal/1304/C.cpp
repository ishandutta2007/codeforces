#include<bits/stdc++.h>
 
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	while(q--)
	{
		int n, m;
		cin >> n >> m;
		vector <int> t(n), l(n), h(n);
		for(int i = 0; i < n; i++)
		{
			cin >> t[i] >> l[i] >> h[i];
		}
		int left = m, right = m;
		int time1 = 0;
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			left = left - (t[i] - time1);
			right = right + (t[i] - time1);
			if(right < l[i] || left > h[i])
			{
				flag = false;
				break;
			}
			left = max(left, l[i]);
			right = min(right, h[i]);
			time1 = t[i];
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}