#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	vector<vector<int>> go(1, vector<int>(2));
	vector<int> total(1);

	auto add = [&](string s)
	{
		int st = 0;
		for (char c : s)
		{
			int x = (c - '0') & 1;
			if (!go[st][x])
			{
				go[st][x] = go.size();
				go.push_back(vector<int>(2));
				total.push_back(0);
			}
			st = go[st][x];
			total[st]++;
		}
	};

	auto rem = [&](string s)
	{
		int st = 0;
		for (char c : s)
		{
			int x = (c - '0') & 1;
			st = go[st][x];
			total[st]--;
		}
	};

	auto count = [&](string s)
	{
		int st = 0;
		for (char c : s)
			if (!go[st][c - '0']) return 0;
			else st = go[st][c - '0'];
		return total[st];
	};

	auto fix = [](string s){
		reverse(s.begin(), s.end());
		while (s.length() < 19)
			s += "0";
		return s;
	};

	while (t--)
	{
		char op;
		string s;

		cin >> op >> s;

		if (op == '+') s = fix(s), add(s);
		else if (op == '-') s = fix(s), rem(s);
		else
		{
			s = fix(s);
			cout << count(s) << endl;
		}
	}

	return 0;
}