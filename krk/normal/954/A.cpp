#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	int res = n;
	for (int i = 0; i + 1 < s.length(); i++)
		if (s[i] == 'R' && s[i + 1] == 'U' ||
			s[i] == 'U' && s[i + 1] == 'R') { res--; i++; }
	printf("%d\n", res);
	return 0;
}