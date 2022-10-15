/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

int main() {
	string a, b;
	cin >> a;
	cout << a;
	reverse(a.begin(), a.end());
	cout << a << endl;
	
	return 0;
}