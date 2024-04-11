#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[41][2][41][41 * 41];
int ans = 0, n;
set <string> pr;
vector <string> v;
map <string, int> mp;
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
void add(int len, int type, int pref, int suf, char t)
{
	string s = v[pref];
	s += t;
	int totype = type;
	while(!pr.count(s))
	{
		s.erase(s.begin());
	}
	if(s.size() == pr.size() - 1)
	{
		totype = 1;
	}
	int topref = s.size();
	s = v[suf];
	s += t;
	int tosuf = suf;
	if(s.size() == len + 1 && mp.count(s))
	{
		tosuf = mp[s];
	}
	dp[len + 1][totype][topref][tosuf] += dp[len][type][pref][suf];
}
string s;
void funct(int len, int type, int pref, int suf)
{
	if(!dp[len][type][pref][suf])
	{
		return;
	}
	if(len == n && type == 1)
	{
		ans += dp[len][type][pref][suf];
		return;
	}
	if(len == n)
	{
		string r = v[pref] + v[suf];
		if(r.find(s) !=string::npos)
		{
			ans += dp[len][type][pref][suf];
		}
		return;
	}
	add(len, type, pref, suf, '0');
	add(len, type, pref, suf, '1');
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> s;
	v.push_back("");
	pr.insert("");
	mp[""] = 0;
	for(int i = 0; i < s.size(); i++)
	{
		string t = "";
		for(int j = i; j < s.size(); j++)
		{
			t += s[j];
			if(!mp.count(t))
			{
				mp[t] = v.size();
				v.push_back(t);
			}
			if(i == 0)
			{
				pr.insert(t);
			}
		}
	}
	dp[0][0][0][0] = 1;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			for(int d = 0; d <= n; d++)
			{
				for(int k = 0; k < v.size(); k++)
				{
					funct(i, j, d, k);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}