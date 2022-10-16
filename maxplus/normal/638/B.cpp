#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> prev(26, -1), nxt(26, -1);
	int n;
	cin >> n;
	vector<bool> was(26);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j < s.size(); j++)
		{
			prev[s[j] - 'a'] = s[j - 1] - 'a';
			nxt[s[j - 1] - 'a'] = s[j] - 'a';
			was[s[j] - 'a'] = true;
		}
		was[s[0] - 'a'] = true;
	}
	for (int i = 0; i < 26; i++)
	{
		if (prev[i] == -1 && was[i])
		{
			int ind = i;
			while (ind != -1)
				cout << static_cast<char>('a' + ind), ind = nxt[ind];
		}
	}
	return 0;
}