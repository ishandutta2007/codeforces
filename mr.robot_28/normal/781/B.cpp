#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> colored;
void dfs(int v, int col, int pred)
{
	colored[v] = col;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			if(colored[g[v][i]] != -1)
			{
				continue;
			}
			dfs(g[v][i], col, v);
		}
	}
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	colored.resize(n, -1);
	vector <pair <string, string> > A(n);
	vector <pair< pair <string, string>, int> > t;
	for(int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		A[i] = {s1, s2};
		string s3 = "aaa";
		s3[0] = s1[0];
		s3[1] = s1[1];
		s3[2] = s1[2];
		string s4 = "aaa";
		s4[0] = s1[0];
		s4[1] = s1[1];
		s4[2] = s2[0];
		t.push_back(make_pair(make_pair(s3, s4), i));
	}
	sort(t.begin(), t.end());
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{
				if(t[i].first.first == t[j].first.second)
				{
					g[t[j].second].push_back(t[i].second);
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		int j = i;
		set <string > k;
		while(j < n && t[i].first.first == t[j].first.first)
		{
			if(k.find(t[j].first.second) != k.end())
			{
				cout << "NO\n";
				return 0;
			}
			k.insert(t[j].first.second);
			j++;
		}
		if(j > i + 1)
		{
			for(int k = i; k < j; k++)
			{
				if(colored[t[k].second] == 0)
				{
					cout << "NO";
					return 0;
				}
				if(colored[t[k].second] == -1)
				{
					dfs(t[k].second, 1, -1);
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(colored[i] == -1)
		{
			colored[i] = 0;
		}
	}
	set <string > k1;
	for(int i = 0; i < n; i++)
	{
		if(colored[i] == 0)
		{
		string s3 = "aaa";
		s3[0] = A[i].first[0];
		s3[1] = A[i].first[1];
		s3[2] = A[i].first[2];
			k1.insert(s3);
		}
		else
		{
			string s3 = "aaa";
			s3[0] = A[i].first[0];
			s3[1] = A[i].first[1];
			s3[2] = A[i].second[0];
			k1.insert(s3);
		}
	}
	if(k1.size() < n)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
	{
		if(colored[i] == 0)
		{
			cout << A[i].first[0] << A[i].first[1] << A[i].first[2] << "\n";
		}
		else
		{
			cout << A[i].first[0] << A[i].first[1] << A[i].second[0] << "\n";
		}
	}
    return 0;
}