#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e5 + 10;
int n,a[maxn],q;
void work() {
	read(n);
	map <int, vi> mp[30];
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		for (int j = 0; j < 30; ++j) mp[j][a[i] >> j].push_back(i);
	}
	read(q);
	while (q--) {
		int l, r; read(l, r);
		vi lst; int res = 0;
		for (int j = 29; j >= 0; --j) {
			res <<= 1;
			vi &nw = mp[j][res], nx0;
			int cnt0 = upper_bound(nw.begin(), nw.end(), r) - lower_bound(nw.begin(), nw.end(), l), cnt1 = cnt0;
			for (int x : lst) if (!((x >> j) & 1)) ++cnt1, nx0.push_back(x);
			if (cnt0 == 1)
				lst.push_back(a[*lower_bound(nw.begin(), nw.end(), l)]);
			if (cnt1 < 2) res |= 1;
			else lst.swap(nx0);
		}
		write(res, '\n');
	}
}

int main() {
	int t; read(t);
	while (t--) work();
	return 0;
}