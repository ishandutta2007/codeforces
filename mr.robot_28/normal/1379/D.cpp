#include<bits/stdc++.h>
 
using namespace std;

signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	vector <pair <int, int> > x(n);
	vector <pair <int, int> > scan;
	if(k == 0)
	{
		cout << 0 << " " << 0;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		x[i] = {a, b};
		b = b % (m / 2);
		if(b + k - 1 >= m / 2)
		{
			scan.push_back({b + 1, -1});
			scan.push_back({0, -1});
			scan.push_back({b + k - m / 2, 1});
		}
		else
		{
			scan.push_back({b + 1, -1});
			scan.push_back({b + k, 1});
		}
	}
	sort(scan.begin(), scan.end());
	int ans = 1e9;
	int ansmin = 0;
	int bal = 0;
	if(scan[0].first != 0)
	{
		cout << 0 << " " << 0;
		return 0;
	}
	for(int i = 0; i < scan.size(); i++)
	{
		bal -= scan[i].second;
		if(i == scan.size() - 1 || scan[i].first != scan[i + 1].first)
		{
			if(bal < ans && scan[i].first < m / 2)
			{
				ans = bal;
				ansmin = scan[i].first;
			}
		}
	}
	cout << ans << " " << ansmin << "\n";
	for(int i = 0; i < n; i++)
	{
		x[i].second %= (m / 2);
		int b = x[i].second;
		if(b + k - 1 >= m / 2)
		{
			if(ansmin >= b + 1 || ansmin < b + k - m / 2)
			{
				cout << i + 1 << " ";
			}
		}
		else if(ansmin >= b + 1 && ansmin < b + k)
		{
			cout << i + 1 << " ";
		}
	}
	return 0;
}