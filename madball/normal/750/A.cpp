#define CRT_SECURE_NO_WARNINGS
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

	int t = 240;
	int n, k;
	cin >> n >> k;
	t -= k;
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		t -= i * 5;
		if (t < 0)
			break;
		++res;
	}
	cout << res;
	return 0;
}