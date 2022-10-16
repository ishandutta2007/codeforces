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
	int n, a;
	cin >> n >> a;
	int res = 0;
	if (a % 2)
		res = a / 2 + 1;
	else
		res = n / 2 - a / 2 + 1;
	cout << res << endl;
	return 0;
}