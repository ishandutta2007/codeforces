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

const int maxn = 4e5 + 10, inf = 1e9;
int n, m, res;
int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

int main() {
	read(n, m);
	vector < vector <int> > a(n + 10, vector <int> (m + 10));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			read(a[i][j]);
	for (int i = 1; i <= n; ++i) a[i][0] = a[i][m + 1] = inf;
	for (int j = 1; j <= m; ++j) a[0][j] = a[n + 1][j] = inf;
	auto check = [&] (int x, int y) {
		return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != 1 &&
		a[x][y] < a[x + 1][y] && a[x][y] < a[x - 1][y] &&
		a[x][y] < a[x][y + 1] && a[x][y] < a[x][y - 1];
	};
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			res += check(i, j);
	if (!res) return write("0\n"), 0;
	if (res > 5) return write("2\n"), 0;

	vector < vector <int> > b(n + 10, vector <int> (m + 10, 1));
	auto upd = [&] (int x, int y, int flg) -> void {
		for (int k = 0; k < 5; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 1 || nx > n || ny < 1 || ny > m || flg == b[nx][ny]) continue;
			b[nx][ny] = flg;
			if (flg) res += check(nx, ny);
			else res -= check(nx, ny);
		}
	};

	set <pii> s;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) if (check(i, j)) {
			for (int k = 0; k < 5; ++k) {
				int p = i + dx[k], q = j + dy[k];
				if (p < 1 || p > n || q < 1 || q > m) continue;
				for (int x = 1; x <= n; ++x)
					for (int y = 1; y <= m; ++y) {
						pii o = {a[p][q], a[x][y]};
						if (o.fir > o.sec) swap(o.fir, o.sec);
						upd(p, q, 0), upd(x, y, 0);
						swap(a[p][q], a[x][y]);
						upd(p, q, 1), upd(x, y, 1);
						if (!res) s.insert(o);
						upd(p, q, 0), upd(x, y, 0);
						swap(a[p][q], a[x][y]);
						upd(p, q, 1), upd(x, y, 1);
					}
			}
		}
	if (s.empty()) write("2\n");
	else write("1 ", s.size(), '\n');
	return 0;
}