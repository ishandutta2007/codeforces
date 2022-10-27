#include<bits/stdc++.h> 
using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int l = 0, r = n / k + 1;
	while(r - l > 1)
	{
		bool flag = false;
		int midd = (r + l) / 2;
		vector <int> dp(26, 0);
		for(int i = 0; i < n; i++)
		{
			int j = i;
			while(j < n && s[j] == s[i])
			{
				j++;
			}
			dp[s[i] - 'a'] += (j - i) / k;
			if(dp[s[i] - 'a'] >= midd)
			{
				flag = true;
			}
			i = j - 1;
		}
		if(flag)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	cout << l;
	return 0;
}