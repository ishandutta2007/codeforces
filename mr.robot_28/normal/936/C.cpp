#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector <int> ans;
	bool failed = false;
	for(int i = 0; i < n; i++)
	{
		int tgt = -1;
		for(int j = n - 1 - i; j >= 0; j--)
		{
			if(s[j] == t[i])
			{
				tgt = j;
				break;
			}
		}
		if(tgt == -1)
		{
			failed = true;
			break;
		}
		ans.push_back(n - tgt - 1);
		ans.push_back(1);
		ans.push_back(n);
		reverse(s.begin(), s.begin() + tgt);
		for(int j = tgt; j < n - 1; j++)
		{
			s[j] = s[j + 1];
		}
		s[n - 1] = t[i];
	}
	if(failed)
	{
		cout << -1;
	}
	else
	{
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
	}
    return 0;
}