#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	s = s + s;
	int res = 0;
	int cur = 1;
	for (int i = 1; i < s.length(); i++)
		if (s[i] != s[i - 1]) cur++;
		else { res = max(res, cur); cur = 1; }
	res = max(res, cur);
	res = min(res, int(s.length()) / 2);
	printf("%d\n", res);
	return 0;
}