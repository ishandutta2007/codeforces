#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> s;
	string a, b;
	int ind = 0;
	while (ind + 1 < s.length()) {
		if ((s[ind] - '0') % 2 == 0 && s[ind] < s[s.length() - 1]) {
			a = s; swap(a[ind], a[s.length() - 1]); break;
		}
		ind++;
	}
	ind = int(s.length()) - 2;
	while (ind >= 0) {
		if ((s[ind] - '0') % 2 == 0 && s[ind] > s[s.length() - 1]) {
			b = s; swap(b[ind], b[s.length() - 1]); break;
		}
		ind--;
	}
	if (a.length() && (b.length() == 0 || a >= b)) cout << a << endl;
	else if (b.length() && (a.length() == 0 || b >= a)) cout << b << endl;
	else cout << "-1" << endl;
	return 0;
}