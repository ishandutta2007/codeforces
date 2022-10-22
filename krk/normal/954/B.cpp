#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int res;

int main()
{
	cin >> n;
	cin >> s;
	res = n;
	for (int i = 1; 2 * i <= s.length(); i++)
		if (s.substr(0, i) == s.substr(i, i))
			res = min(res, i + 1 + int(s.length()) - 2 * i);
	printf("%d\n", res);
	return 0;
}