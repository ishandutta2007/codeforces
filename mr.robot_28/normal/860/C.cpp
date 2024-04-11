#include<bits/stdc++.h>
using namespace std;
string gstr(int a)
{
	string res = "";
	while(a > 0)
	{
		char t = '0' + a % 10;
		res += t;
		a = a / 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <string> s(n);
	vector <bool> used(n, false);
	vector <int> type(n);
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i] >> type[i];
		k += type[i];
	}
	vector <string> mass1, mass2;
	vector <int> vec1, vec2;
	for(int i = 0; i < n; i++)
	{
		int ch = 0;
		bool flag = true;
		if(s[i][0] == '0')
		{
			flag = false;
		}
		for(int j = 0; j< s[i].size(); j++)
		{
			if(s[i][j] < '0' || s[i][j] > '9')
			{
				flag= false;
			}
		}
		if(!flag)
		{
			if(type[i] == 1)
			{
				mass1.push_back(s[i]);
			}
			else
			{
				mass2.push_back(s[i]);
			}
		}
		else
		{
			for(int j = 0; j < s[i].size(); j++)
			{
				ch = ch * 10 + s[i][j] - '0';
			}
			if(ch == 0 || ch > n)
			{
				if(type[i] == 1)
				{
					mass1.push_back(s[i]);
				}
				else
				{
					mass2.push_back(s[i]);
				}
			}
			else if(ch > k && type[i] == 1)
			{
				vec1.push_back(ch);
			}
			else if(ch <= k && type[i] == 0)
			{
				vec2.push_back(ch);
			}
			if(ch >= 1 && ch <= n)
			{
				used[ch - 1] = true;
			}
		}
	}
	vector <int> p1, p2;
	for(int i = 0 ; i < k; i++)
	{
		if(!used[i])
		{
			p1.push_back(i + 1);
		}
	}
	for(int i = k; i < n; i++)
	{
		if(!used[i])
		{
			p2.push_back(i + 1);
		}
	}
	int st = 1e5 + 1;
	vector <pair <string, string> > ans;
	while(mass1.size() > 0 || mass2.size() > 0 || vec1.size() > 0 || vec2.size() > 0)
	{
		while(p1.size() > 0 || p2.size() > 0)
		{
			if(p1.size() > 0)
			{
				if(vec1.size() > 0)
				{
					ans.push_back({gstr(vec1.back()), gstr(p1.back())});
					p2.push_back(vec1.back());
					vec1.pop_back();
					p1.pop_back();
				}
				else if(mass1.size() > 0)
				{
					ans.push_back({mass1.back(), gstr(p1.back())});
					p1.pop_back();
					mass1.pop_back();
				}
			}
			else
			{
				if(vec2.size() > 0){
					ans.push_back({gstr(vec2.back()), gstr(p2.back())});
					p1.push_back(vec2.back());
					vec2.pop_back();
					p2.pop_back();
				}
				else
				{
					ans.push_back({mass2.back(), gstr(p2.back())});
					p2.pop_back();
					mass2.pop_back();
				}
			}
		}
		if(vec1.size() > 0)
		{
			ans.push_back({gstr(vec1.back()), gstr(st)});
			p2.push_back(vec1.back());
			vec1.pop_back();
			mass1.push_back(gstr(st));
			st++;
		}
		else if(vec2.size() > 0)
		{
			ans.push_back({gstr(vec2.back()), gstr(st)});
			p1.push_back(vec2.back());
			vec2.pop_back();
			mass2.push_back(gstr(st));
			st++;
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << "move ";
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}