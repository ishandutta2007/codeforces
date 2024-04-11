/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <map>
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

int n;
int a[200005];

vector <int> od, ev;

map <LL, bool> vis;

int ans = 0;

#define ok(i) ((i) < 1 || (i) >= n || ((i) & 1 ? a[i] < a[i + 1] : a[i] > a[i + 1]))


void work(int x) {
	if (x < 1 || x > n) return;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		swap(a[x], a[i]);
		bool flag = ok(x - 1) & ok(x) & ok(x + 1) & ok(i - 1) & ok(i) & ok(i + 1);
		for (int j = 0; j < od.size(); j++) flag &= ok(od[j] - 1) & ok(od[j]) & ok(od[j] + 1);
		for (int j = 0; j < ev.size(); j++) flag &= ok(ev[j] - 1) & ok(ev[j]) & ok(ev[j] + 1);
		if (flag) {
			int a = i ,b = x;
			if (a > b) swap(a, b);
			if (!vis[LL(a) * n + b]) vis[LL(a) * n + b] = 1, ans++;
		}
		swap(a[x], a[i]);
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) {
		if (i & 1) {if (!ok(i)) od.push_back(i);}
		else {if (!ok(i)) ev.push_back(i);}
	}
	if (max(od.size(), ev.size()) > 10) return puts("0"), 0;

	for (int i = 0; i < od.size(); i++) work(od[i] - 1), work(od[i]), work(od[i] + 1);
	for (int i = 0; i < ev.size(); i++) work(ev[i] - 1), work(ev[i]), work(ev[i] + 1);
	cout << ans << endl;
	return 0;
}