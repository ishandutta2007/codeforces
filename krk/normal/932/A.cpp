#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	string res = s;
	reverse(s.begin(), s.end());
	res += s;
	cout << res << endl;
	return 0;
}