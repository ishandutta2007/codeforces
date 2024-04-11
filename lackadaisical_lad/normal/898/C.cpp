#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<string, vector<string>> mp;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int k;
		cin >> k;
		while (k--)
		{
			string t;
			cin >> t;
			mp[s].push_back(t);
		}
	}
	for (auto &p : mp)
		for (int i = 0; i < p.second.size(); i++)
			for (int j = 0; j < p.second.size(); j++)
			{
				if (i == j)
					continue;
				int k = (int)p.second[j].length() - (int)p.second[i].length();
				if (p.second[i][0] == '#')
					continue;
				if (p.second[j][0] == '#' && k == 1)
					continue;
				if (k >= 0)
				{
					bool f = true;
					for (int x = k; x < p.second[j].size(); x++)
						if (p.second[i][x - k] != p.second[j][x])
						{
							f = false;
							break;
						}
					if (f)
						p.second[i] = '#' + p.second[i];
				}
			}
	cout << mp.size() << endl;
	for (auto p : mp)
	{
		set<string> q;
		for (string i : p.second)
			if (i[0] !='#')
				q.insert(i);
		cout << p.first << ' ' << q.size() << ' ';
		for (string i : q)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}