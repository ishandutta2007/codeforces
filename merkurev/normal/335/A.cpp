#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	string s;
	cin >> s;
	int n;
	cin >> n;

	map<char, int> mx;
	for (char c : s)
		mx[c]++;

	if ((int)mx.size() > n)
	{
		cout << "-1" << endl;
		return 0;
	}

	for (int it = 1; ;it++)
	{
		int sum = 0;
		vector<pair<char, int> > list;
		for (auto p : mx)
		{
			int need_cnt = (p.second + it - 1) / it;
			sum += need_cnt;
			list.emplace_back(p.first, need_cnt);
		}

		if (sum > n)
			continue;

		string res;
		for (auto p : list)
			res += string(p.second, p.first);
		res += string(n - (int)res.length(), 'a');

		cout << it << endl;
		cout << res << endl;
		return 0;
	}

	return 0;
}