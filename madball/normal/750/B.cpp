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

	int n;
	int pos = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t;
		string s;
		cin >> t >> s;
		if (s == "South")
			pos += t;
		else if (s == "North")
			pos -= t;
		else if (pos == 0 || pos == 20000)
		{
			cout << "NO";
			return 0;
		}
		if (pos < 0 || pos > 20000)
		{
			cout << "NO";
			return 0;
		}
	}
	if (pos != 0)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}