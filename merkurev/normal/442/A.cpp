#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

pair<int, int> read()
{
	char c; int num;
	cin >> c >> num;
	num--;
	int a = 0;
	if (c == 'G')
		a = 1;
	if (c == 'B')
		a = 2;
	if (c == 'Y')
		a = 3;
	if (c == 'W')
		a = 4;
	return make_pair(a, num);
}

bool bit(int mask, int pos)
{
	return (mask & (1 << pos)) != 0;
}

bool is_good(vector<pair<int, int> > list)
{
	for (int i = 0; i < (int)list.size(); i++)
		if (list[i] != list[0])
			return false;
	return true;
}

bool is_good(vector<vector<pair<int, int> > > sets)
{
	for (auto l : sets)
		if (!is_good(l))
			return false;
	return true;
}

vector<vector<pair<int, int> > > split1(vector<vector<pair<int, int> > > sets, int a)
{
	vector<vector<pair<int, int> > > res;
	for (auto l : sets)
	{
		vector<pair<int, int> > s1, s2;
		for (auto p : l)
		{
			if (p.first == a)
				s1.push_back(p);
			else
				s2.push_back(p);
		}

		if (!s1.empty())
			res.push_back(s1);
		if (!s2.empty())
			res.push_back(s2);
	}
	return res;
}

vector<vector<pair<int, int> > > split2(vector<vector<pair<int, int> > > sets, int a)
{
	vector<vector<pair<int, int> > > res;
	for (auto l : sets)
	{
		vector<pair<int, int> > s1, s2;
		for (auto p : l)
		{
			if (p.second == a)
				s1.push_back(p);
			else
				s2.push_back(p);
		}

		if (!s1.empty())
			res.push_back(s1);
		if (!s2.empty())
			res.push_back(s2);
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<pair<int, int> > list(n);
	for (int i = 0; i < n; i++)
		list[i] = read();

	int ans = 10000;
	for (int mask1 = 0; mask1 < (1 << 5); mask1++)
	{
		vector<vector<pair<int, int> > > sets = {list};
		for (int i = 0; i < 5; i++)
		{
			if (!bit(mask1, i))
				continue;
			sets = split1(sets, i);  
		}

		for (int mask2 = 0; mask2 < (1 << 5); mask2++)
		{
			auto sets2 = sets;
			for (int i = 0; i < 5; i++)
			{
				if (!bit(mask2, i))
					continue;
				sets2 = split2(sets2, i);
			}

			if (is_good(sets2))
				ans = min(ans, __builtin_popcount(mask1) + __builtin_popcount(mask2));
		}
	}

	cout << ans << endl;

	return 0;
}