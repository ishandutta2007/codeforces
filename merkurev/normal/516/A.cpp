#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<int, int> mx;

vector<vector<int> > fact =
{
	{0},
	{1},
	{2},
	{3},
	{2, 2},
	{5},
	{2, 3},
	{7},
	{2, 2, 2},
	{3, 3}
};

void add(int num, int dx)
{
	if (num <= 1)
		return;
	for (int i = 2; i <= num; i++)
	{
		for (int x : fact[i])
			mx[x] += dx;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (char c : s)
		add((int)(c - '0'), 1);

	string res;
	vector<int> l = {7, 5, 3, 2};
	for (int x : l)
	{
		while (mx[x] != 0)
		{
			res.push_back((char)(x + '0'));
			add(x, -1);
		}
	}

	cout << res << endl;

	return 0;
}