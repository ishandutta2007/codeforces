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
		string s;
		cin >> s;
		int left = 0, right = 0;
		int cnt = 0;
		int sum = 0;
		bool fl1 = 1;
		bool flag = 1;
		bool fl2 = 0, fl3 = 0;
		for(int i = 0; i < n;i++)
		{
			if(s[i] == '>')
			{
				fl2 = 1;
			}
			if(s[i] == '<')
			{
				fl3 = 1;
			}
			if(flag && s[i] == '-')
			{
				left++;
			}
			else if(!flag && s[i] == '-')
			{
				cnt++;
			}
			else if(!flag)
			{
				if(cnt != 0)
				{
				sum += cnt + 1;
				}
				cnt = 0;
			}
			else
			{
				flag = 0;
			}
		}
		for(int i = n - 1; i >= 0; i--)
		{
			if(s[i] == '-')
			{
				right++;
			}
			else
			{
				break;
			}
		}
	//	cout << left << " " << right << "\n";
		if(left >= n || !(fl3 & fl2))
		{
			cout << n << "\n";
		}
		else
		{
		 	if(right + left != 0)
			{
				sum += left + 1 + right;
			}
			cout << sum << "\n";
		}
	}
	return 0;
}