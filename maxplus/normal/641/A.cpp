#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <string>

using namespace std;


signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> was(n, false);
	int ind = 0;
	while (ind >= 0 && ind < n && !was[ind])
	{
		was[ind] = true;
		ind = ind + a[ind] * (s[ind] == '<' ? -1 : 1);
	}
	if (ind >= 0 && ind < n)
	{
		cout << "INFINITE" << endl;
	}
	else
	{
		cout << "FINITE" << endl;
	}
}