#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int inf = 1e9 + 10;
int n, m;
void work() {
	read(n, m);
	vector < vector <int> > a(n + 10, vector <int> (m + 10)), b;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) read(a[i][j]);
	b = a;
	for (int i = 1; i <= n; ++i) sort(b[i].begin() + 1, b[i].begin() + m + 1);
	int x = 0, y = 0;
	auto upd = [&] (int i) {
		if (x == -1) return;
		int p1 = 0, p2 = 0, cnt = 0;
		for (int j = 1; j <= m; ++j) cnt += a[i][j] != b[i][j];
		if (cnt == 0) {
			if (x && a[i][x] != a[i][y]) return void(x = y = -1);
			return;
		}
		if (cnt != 2) return void(x = y = -1);
		for (int j = 1; j <= m; ++j)
			if (a[i][j] != b[i][j]) swap(p1, p2), p1 = j;
		if (p1 > p2) swap(p1, p2);
		if (x && (p1 != x || p2 != y)) x = y = -1;
		else x = p1, y = p2;
	};
	for (int i = 1; i <= n; ++i) upd(i);
	if (x == -1) write("-1\n");
	else if (x == 0) write("1 1\n");
	else {
		for (int i = 1; i <= n; ++i) swap(a[i][x], a[i][y]);
		if (a != b) write("-1\n");
		else write(x, ' ', y, '\n');
	}
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}