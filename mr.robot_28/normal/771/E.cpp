#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <pair <pair <int, int>, int> > > mass;	
vector <int> go_to1, go_to2, go_to3, dp;
void add(int i, int j, int sum)
{
	mass[min(i, j)].push_back({{i, j}, sum});
	dp[max(i, j)] = max(dp[max(i, j)], sum);
}
int n;
void go_from(int i, int j, int sum)
{
	if(i < n)
	{
		add(i + 1, j, sum);
		int k = go_to1[i];
		if(k != -1)
		{
			add(k, j, sum + 1);
		}
	}
	if(j < n)
	{
		add(i, j + 1, sum);
		int k = go_to2[j];
		if(k != -1)
		{
			add(i, k, sum + 1);
		}
	}
	if(i == j)
	{
		i = go_to3[i];
		if(i != -1)
		{
			add(i, i, sum + 1);
		}
	}
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n;
	go_to1.resize(n, -1);
	go_to2.resize(n, -1);
	mass.resize(n + 1);
	go_to3.resize(n, -1);
	dp.resize(n + 1, -1e9);
	vector <vector <int> > matrix(2, vector <int> (n));
	vector <int> pref1(n + 1), pref2(n + 1), pref3(n + 1);
	set <pair <int, int> > s1, s2, s3;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	for(int j = 0; j < n; j++)
	{
		pref1[j + 1] = pref1[j] + matrix[0][j];
		pref2[j + 1] = pref2[j] + matrix[1][j];
		pref3[j + 1] = pref3[j] + matrix[0][j] + matrix[1][j];
	}
	for(int i = n; i >= 0; i--)
	{
		set <pair <int, int> > :: iterator it;
		it = s1.lower_bound({pref1[i], 0});
		if(it != s1.end() && it -> first == pref1[i])
		{
			go_to1[i] = it -> second;
			s1.erase(*it);
		}
		s1.insert({pref1[i], i});
		it = s2.lower_bound({pref2[i], 0});
		if(it != s2.end() && it -> first == pref2[i])
		{
			go_to2[i] = it -> second;
			s2.erase(*it);
		}
		s2.insert({pref2[i], i});
		it = s3.lower_bound({pref3[i], 0});
		if(it != s3.end() && it -> first == pref3[i])
		{
			go_to3[i] = it -> second;
			s3.erase(*it);
		}
		s3.insert({pref3[i], i});
	}
	dp[0] = 0;
	for(int i = 0; i < n; i++)
	{
		go_from(i, i, dp[i]);
		int l1 = -1, r1 = -1;
		for(int j = 0; j < mass[i].size();  j++)
		{
			int l = mass[i][j].first.first;
			int r = mass[i][j].first.second;
			int funct = mass[i][j].second;
			if(funct == dp[i] + 1)
			{
				if(r == i && (l1 == -1 || l < l1))
				{
					l1 = l;
				}
				if(l == i && (r1 == -1 || r < r1))
				{
					r1 = r;
				}
			}
		}
		if(l1 != -1)
		{
			go_from(l1, i, dp[i] + 1);
		}
		if(r1 != -1)
		{
			go_from(i, r1, dp[i] + 1);
		}
	}
	cout << dp[n];
	return 0;
}