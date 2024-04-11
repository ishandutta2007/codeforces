#include <bits/stdc++.h> 
using namespace std;
vector <vector <int> > dp;
string s;
int rez(int l, int r)
{
	int &ans = dp[l][r];
	if(ans != -1)
	{
		return ans;
	}
	if(l > r)
	{
		return 0;
	}
	if(l == r)
	{
		ans = 1;
		return 1;
	}
	ans = 1 + rez(l + 1, r);
	for(int j = l + 1; j <= r; j++)
	{
		if(s[l] == s[j])
		{
			ans = min(ans, rez(l + 1, j - 1) + rez(j, r));
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	cin >> s;
	dp.resize(n, vector <int> (n, -1));
	cout << rez(0, n - 1);
	return 0;
}