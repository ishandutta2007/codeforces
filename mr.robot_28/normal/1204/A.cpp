#include <bits/stdc++.h>
using namespace std;

signed main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 1; i < s.size(); i++)
	{
		cnt += (s[i] - '0');
	}
	cout << (s.size() - 1) / 2 + (cnt > 0 || s.size() % 2 == 0);
	return 0;
}