#include<bits/stdc++.h>
using namespace std;

bool cmp(pair <string, int> a,pair <string, int > b)
{
	return a.first < b.first;
}
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
		string s;
		cin >> s;
		vector <pair <string, int> > m;
		for(int k = 1; k < n; k++)
		{
			string h1 = "";
			for(int j = 0; j + k - 1 < n; j++)
			{
				h1 += s[j + k - 1];
			}
			string h2 = "";
			for(int j = 0; j < k - 1; j++)
			{
				h2 += s[j];
			}
			if((n - k) % 2 == 0)
			{
				reverse(h2.begin(), h2.end());
			}
			h1 += h2;
			m.push_back({h1, k});
		}
		string h1 = "";
		for(int i = n - 1; i >= 0; i--)
		{
			h1 += s[i];
		}
		m.push_back({h1, n});
		sort(m.begin(), m.end());
		cout << m[0].first << "\n" << m[0].second << "\n";
	}
	return 0;
}