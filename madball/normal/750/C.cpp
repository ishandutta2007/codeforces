#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define FILENAME ""
typedef long long ll;

int main()
{
#ifdef LOCAL
	if (FILENAME == "TODO")
		throw;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if (FILENAME != "")
	{
		freopen(FILENAME".in", "r", stdin);
		freopen(FILENAME".out", "w", stdout);
	}
#endif

	int n, cur = 0;
	int div2max = -1000000000;
	int div1min = 1000000000;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int c, d;
		cin >> c >> d;
		if (d == 2)
			div2max = max(div2max, cur);
		else
			div1min = min(div1min, cur);
		cur += c;
	}
	//cout << div2max << ' ' << div1min << '\n';
	if (div2max >= div1min)
		cout << "Impossible";
	else if (div2max == -1000000000)
		cout << "Infinity";
	else
		cout << 1900 - (div2max + 1) + cur;

	return 0;
}