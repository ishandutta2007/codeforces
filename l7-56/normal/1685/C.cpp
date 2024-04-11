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

const int maxn = 2e5 + 10;
int n, s[maxn];
char str[maxn];
void work() {
	read(n); scanf("%s", str + 1); n <<= 1;
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + (str[i] == '(') - (str[i] == ')');
	bool flg = 1;
	for (int i = 1; i <= n; ++i) flg &= (s[i] >= 0);
	if (flg) return write("0\n");

	int L = 1, R = n;
	while (L <= n && s[L] >= 0) ++L;
	while (R >= 1 && s[R] >= 0) --R;
	pii pl = {-1, -1}, pr = {-1, -1};
	for (int i = 1; i <= L; ++i) pl = max(pl, make_pair(s[i - 1], i));
	for (int i = R; i <= n; ++i) pr = max(pr, make_pair(s[i], i));
	int mx = 0;
	for (int i = pl.sec - 1; i <= pr.sec - 1; ++i) mx = max(mx, s[i - 1]);
	if (mx <= pl.fir + pr.fir) return write("1\n", pl.sec, ' ', pr.sec, '\n');

	pii p = {-1, -1};
	for (int i = 1; i <= n; ++i) p = max(p, make_pair(s[i], i));
	write("2\n1 ", p.sec, '\n', p.sec + 1, ' ', n, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}