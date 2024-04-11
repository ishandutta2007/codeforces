#include <bits/stdc++.h>

using namespace std;

int ans[4] = {4, 0, 0, 0};

int main()
{
	string s;
	cin >> s;
	if (s.length() == 1) s = "0" + s;
	int l = s.length();
	int v = (s[l - 2] - '0') * 10 + (s[l - 1] - '0');
	v %= 4;
	cout << ans[v] << endl;
}