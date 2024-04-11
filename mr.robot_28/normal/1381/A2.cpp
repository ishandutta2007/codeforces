#include<bits/stdc++.h>
using namespace std;

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
		string a, b;
		cin >> a >> b;
		vector <int> ans;
		int last = n - 1, beg = 0;
		int x = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			if((a[last] ^ x) == b[i])
			{
				if(beg > last)
				{
					last++;
				}
				else
				{
					last--;
				}
				continue;
			}
			if((a[beg] ^ x) == b[i])
			{
				ans.push_back(1);
			}
			ans.push_back(i + 1);
			swap(beg, last);
			x ^= 1;
			if(beg > last)
			{
				last++;
			}
			else
			{
				last--;
			}
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
  	return 0;
}