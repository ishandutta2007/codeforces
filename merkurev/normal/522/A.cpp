#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

string to_lower(string str)
{
	for (int i = 0; i < (int)str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	map<string, int> dp;
	dp["polycarp"] = 1;
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		string name1, mid, name2;
		cin >> name1 >> mid >> name2;
		name1 = to_lower(name1);
		name2 = to_lower(name2);
		dp[name1] = dp[name2] + 1;
		ans = max(ans, dp[name1]);
	}

	cout << ans << endl;

	return 0;
}