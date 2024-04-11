#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int n;

string s[200];

vector<int> eds[200];

int fl[200];

vector<int> vv;

int was[200];


void dfs(int v)
{
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i)
		if (!was[eds[v][i]])
			dfs(eds[v][i]);
		else
			if (was[eds[v][i]] == 1)
			{
				cout << "Impossible";
				exit(0);
			}
	vv.push_back(v);
	was[v] = 2;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < 200; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (fl[j])
				continue;
			if ((int)s[j + 1].size() <= i)
			{
				cout << "Impossible";
				return 0;
			}
			if ((int)s[j].size() <= i)
			{
				fl[j] = 1;
				continue;
			}
			if (s[j][i] == s[j + 1][i])
				continue;
			fl[j] = 1;
			eds[s[j][i] - 'a'].push_back(s[j + 1][i] - 'a');
		}
	}

	for (int i = 25; i >= 0; --i)
		if (!was[i])
			dfs(i);
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < 26; ++i)
	{
		cout << (char)(vv[i] + 'a');
	}

	return 0;
}