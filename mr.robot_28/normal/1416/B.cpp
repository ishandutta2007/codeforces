#include<bits/stdc++.h>
using namespace std;
 
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> a(n);
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		if(sum % n != 0)
		{
			cout << -1 << "\n";
			continue;
		}
		vector <pair <pair <int, int> , int> > ans;
		for(int i = 1; i < n; i++)
		{
			if(a[i] % (i + 1) != 0)
			{
				ans.push_back({{1, i + 1}, i + 1 - a[i] % (i + 1)});
				a[0] -= (i + 1) - a[i] % (i + 1);
				a[i] += (i + 1) - a[i] % (i + 1);
			}
			ans.push_back({{i + 1, 1}, a[i] / (i + 1)});
			a[0] += a[i];
			a[i] = 0;
		}
		for(int i = 1; i < n; i++)
		{
			ans.push_back({{1, i + 1}, sum / n});
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
		}
	}
	return 0;
}