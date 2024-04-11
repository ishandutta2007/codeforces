/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
int _c = 0;
template <class _T> inline void read(_T &_a) {
	_a = 0; bool _f = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}
typedef long long LL;
typedef long double LD;

LL a, b, c, m, cnt = 0, ans = 0;
string s;
priority_queue <LL, vector<LL>, greater<LL> > A, B;

#define Pop(x) ans += x.top(), x.pop(), cnt++

int main() {
	cin >> a >> b >> c;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		LL hh;
		cin >> hh >> s;
		if (s == "USB") A.push(hh);
		else B.push(hh);
	}
	for (int i = 1; i <= a && !A.empty(); i++) Pop(A);
	for (int i = 1; i <= b && !B.empty(); i++) Pop(B);
	while (c && !A.empty() && !B.empty()) {
		if (A.top() < B.top()) Pop(A); else Pop(B); c--;
	}
	while (c && !A.empty()) Pop(A), c--;
	while (c && !B.empty()) Pop(B), c--;
	cout << cnt << " " << ans << endl;
	return 0;
}