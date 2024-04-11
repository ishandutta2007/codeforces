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
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		vector <int> w(k);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for(int i = 0; i < k; i++)
		{
			cin >> w[i];
		}
		sort(a.begin(), a.end());
		int sum = 0;
		int cnt1 = 0;
		for(int i = n - k; i < n; i++)
		{
			sum += a[i];
		}
		for(int i = 0; i < k; i++)
		{
			w[i]--;
			if(w[i] == 0)
			{
				cnt1++;
			}
		}
		for(int i = n - cnt1; i < n; i++)
		{
			sum += a[i];
		}
		sort(w.begin(), w.end());
		int it = 0;
		for(int i = k - 1; i >= 0; i--)
		{
			if(w[i] == 0)
			{
				break;
			}
			sum += a[it];
			while(w[i] > 0)
			{
				w[i]--;
				it++;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}