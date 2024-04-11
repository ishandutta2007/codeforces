#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int N = 120;
ll a[N][N];
ll calc(ll t, ll x, ll y) {
	memset(a, 0, sizeof a);
	if (t < x + y) return 0;
	a[0][0] = t - x - y + 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (i + 1 < N) a[i + 1][j] += a[i][j] / 2;
			if (j + 1 < N) a[i][j + 1] += (a[i][j] + 1) / 2;
		}
	return a[x][y];
}

void work() {
	ll t, x, y; read(t, x, y);
	printf(calc(t - 1, x, y) != calc(t, x, y) ? "YES\n" : "NO\n");
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}