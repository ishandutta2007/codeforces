#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

int a[N];
int n;

pii query(int l, int r) {
	cout << "? " << l << " " << r << endl;
	pii ans; cin >> ans.first >> ans.second; return ans;
}

void solve(int l, int r) {
	if (a[l] == a[r]) {
		for (int i = l + 1; i < r; i++) a[i] = a[l];
		return;
	}
	if (l + 1 >= r) return;
	pii ans = query(l, r);
	if (ans.first == a[l]) {
		for (int i = l + 1; i < l + ans.second; i++) a[i] = a[l];
		a[l + ans.second] = query(l + ans.second, l + ans.second).first;
		solve(l + ans.second, r);
	} else if (ans.first == a[r]) {
		for (int i = r - ans.second + 1; i < r; i++) a[i] = a[r];
		a[r - ans.second] = query(r - ans.second, r - ans.second).first;
		solve(l, r - ans.second);
	} else {
		a[l + ans.second] = query(l + ans.second, l + ans.second).first;
		solve(l, l + ans.second); solve(l + ans.second, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	a[1] = query(1, 1).first;
	a[n] = query(n, n).first;
	solve(1, n);
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}