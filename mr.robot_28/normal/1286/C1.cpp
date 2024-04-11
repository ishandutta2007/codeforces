#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;

vector <vector <int> > query(int l, int r)
{
	cout << "? " << l << " " << r << endl;
	vector <vector <int> > res;
	int c = (r - l + 1);
	c = c * (c + 1) / 2;
	for(int i = 0; i < c; i++)
	{
		string s;
		cin >> s;
		vector <int> cnt(26, 0);
		for(int j = 0; j < sz(s); j++)
		{
			cnt[s[j] - 'a']++;
		}
		res.push_back(cnt);
	}
	return res;
}
bool cmp(vector <int> a, vector <int> b)
{
	int c1 =0 , c2 = 0;
	for(int i = 0; i < 26; i++)
	{
		c1 += a[i];
		c2 += b[i];
	}
	return c1 < c2;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	map <vector <int>, int> mp;
	vector <vector <int> > p = query(1, n);
	if(n == 1)
	{
		for(int i = 0; i < 26; i++)
		{
			if(p[0][i])
			{
				char t = 'a' + i;
				cout << "! " << t << endl;
			}
		}
		return 0;
	}
	vector <vector <int> > p1 = query(2, n);
	for(auto x : p)
	{
		mp[x]++;
	}
	for(auto x : p1)
	{
		mp[x]--;
	}
	vector <int> cnt1(26, 0);
	vector <vector <int> > p2;
	for(auto it : mp)
	{
	    if(it.Y)
        {
		p2.push_back(it.X);
        }
	}
	sort(p2.begin(), p2.end(), cmp);
	vector <int> cnt(26, 0);
	string s = "";
	for(int i = 0; i < sz(p2); i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(p2[i][j] > cnt[j])
			{
				cnt[j]++;
				char t = j + 'a';
				s += t;
			}
		}
	}
	cout << "! " << s << endl;
	return 0;
}