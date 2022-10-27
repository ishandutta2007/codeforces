#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int p, k;
	cin >> p >> k;
	int d = p / k;
	vector <int> ans;
	ans.push_back(p - d * k);
	p = -d;
	while(abs(p) >= k || p < 0)
	{
		if(p < 0)
		{
			int d = abs(p) / k;
			if(d * k + p < 0)
			{
				d++;
			}
			ans.push_back(p + d * k);
			p = d;
		}
		else
		{
			int d = p / k;
			ans.push_back(p - d * k);
			p = -d;
		}
	}
	if(p != 0)
	{
	ans.push_back(p);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
    return 0;
}