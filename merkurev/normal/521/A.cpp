#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int mod = (int)1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> mx;
	for (char c : s)
		mx[c]++;

	int maxx = 0;
	int mx_cnt = 0;
	for (auto p : mx)
	{
		if (p.second > maxx)
		{
			maxx = p.second;
			mx_cnt = 0;
		}
		if (p.second == maxx)
			mx_cnt++;
	}

	int res = 1;
	for (int i = 0; i < n; i++)
		res = (long long)res * mx_cnt % mod;

	cout << res << endl;


	return 0;
}