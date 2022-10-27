#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool flag = 1;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
			{
				if(i < n - k && s[i + k] == '1'){
					flag = 0;
					break;
				}
				int j = i + k;
				while(j < n && s[j] == '?')
				{
					s[j] = '0';
					j += k;
				}
				j = i - k;
				while(j >= 0 && s[j] == '?')
				{
					s[j] = '0';
					j -= k;
				}
			}
			else if(s[i] == '1')
			{
				if(i < n - k && s[i + k] == '0'){
					flag = 0;
					break;
				}
				int j = i + k;
				while(j < n && s[j] == '?')
				{
					s[j] = '1';
					j += k;
				}
				j = i - k;
				while(j >= 0 && s[j] == '?')
				{
					s[j] = '1';
					j -= k;
				}
			}
		}
		if(flag)
		{
			int bal = 0;
			int cnt = 0;
			for(int i = 0; i < k; i++)
			{
				if(s[i] == '?')
				{
					cnt++;
				}
				else
				{
					bal += (s[i] - '0');
				}
			}
			if(bal <= k / 2 && bal + cnt >= k / 2)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			cout << "NO\n";
		}
		
	}
	return 0;
}