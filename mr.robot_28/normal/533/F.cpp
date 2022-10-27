#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
vector <int> st1, st2;
void add1(int &a, int b, int c)
{
	int k = abs(b) * abs(c) % mod1;
	if(b < 0)
	{
		a -= k; 
	}
	else
	{
		a += k;
	}
//	cout << a << "\n";
	if(a < 0)
	{
		a += mod1;
	}
	if(a >= mod1)
	{
		a -= mod1;
	}
}
void add2(int &a, int b, int c)
{
	a +=  b * c % mod2;
	if(a < 0)
	{
		a += mod2;
	}
	if(a >= mod2)
	{
		a -= mod2;
	}
}
signed main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	vector <int> ind1(26, -1);
	vector <int> mass;
	pair <int, int> sample = {0, 0};
	int c = 0;
	for(int i = 0; i < m; i++)
	{
		if(ind1[t[i] - 'a'] == -1)
		{
			mass.push_back(t[i] - 'a');
			ind1[t[i] - 'a'] = c;
			c++;
		}
	}
	for(int i = m - 1; i >= 0; i--)
	{
		sample.first = (sample.first * 27 + ind1[t[i] - 'a'] + 1) % mod1;
		sample.second = (sample.second * 27 + ind1[t[i] - 'a'] + 1) % mod2;
	}
	pair <int, int> hash = {0, 0};
	vector <int> ind(26,-1);
	c = 0;
	for(int i = n - m; i < n; i++)
	{
		if(ind[s[i] - 'a'] == -1)
		{
			ind[s[i] - 'a'] = c;
			c++;
		}
	}
	st1.resize(m + 1);
	st2.resize(m + 1);
	st2[0] = st1[0] = 1;
	for(int i = 1; i <= m; i++)
	{
		st1[i] = st1[i - 1] * 27 % mod1;
		st2[i] = st2[i - 1] * 27 % mod2;
	}
	vector <pair <int, int> > hashes(26, {0, 0});
	c = 0;
	for(int i = n - 1; i >= n - m; i--)
	{
		c++;
		hash.first= (hash.first * 27 + ind[s[i] - 'a'] + 1) % mod1;
		hash.second = (hash.second * 27 + ind[s[i] - 'a'] + 1) % mod2;
		for(int j = 0; j < 26; j++)
		{
			if(j != s[i] - 'a')
			{
		hashes[j].first = (hashes[j].first * 27 ) % mod1;
		hashes[j].second = (hashes[j].second * 27 ) % mod2;
			}
		}
		hashes[s[i] - 'a'].first = (hashes[s[i] - 'a'].first * 27 + 1) % mod1;
		hashes[s[i] - 'a'].second = (hashes[s[i] - 'a'].second * 27 + 1) % mod2;
	}
	vector <int> ans;
	for(int i = n - m; i >= 0; i--)
	{
		if(hash == sample)
		{
			bool flag = 1;
			vector <int> par(26, -1);
			for(int j = 0; j < 26; j++)
			{
				if(hashes[j].first != 0)
				{
					if(par[j] != -1 && par[j] != mass[ind[j]])
					{
						flag = 0;
					}
					par[j] = mass[ind[j]];
					if(par[mass[ind[j]]] != -1 && par[mass[ind[j]]] != j)
					{
						flag = 0;
					}
					par[mass[ind[j]]] = j;
				}
			}
			if(flag)
			{
				ans.push_back(i + 1);
			}
		}
		if(i != 0)
		{
			add1(hashes[s[i + m - 1] - 'a'].first, -st1[m - 1], 1);
			add2(hashes[s[i + m - 1] - 'a'].second, -st2[m - 1], 1);
			int t = ind[s[i - 1] - 'a'];
			for(int j = 0; j < 26; j++)
			{
				if(ind[j] != -1)
				{
					if(t == -1 || t >= ind[j])
					{
					ind[j]++;
					}
					hashes[j].first= hashes[j].first * 27 % mod1;
					hashes[j].second = hashes[j].second * 27 % mod2;
				}
			}
			ind[s[i - 1] - 'a'] = 0;
			add1(hashes[s[i - 1] - 'a'].first, 1, 1);
			add2(hashes[s[i - 1] - 'a'].second, 1, 1);
			hash = {0, 0};
			for(int j= 0; j < 26; j++)
			{
				add1(hash.first, 1, hashes[j].first * (ind[j] + 1) % mod1);
				add2(hash.second, 1, hashes[j].second * (ind[j] + 1) % mod2);
			}
		}
	}
	cout << ans.size() << "\n";
	if(ans.size() != 0)
	{
	for(int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
}
	return 0;
}