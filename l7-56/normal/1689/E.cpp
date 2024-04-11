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

const int maxn = 3010;
int n, a[maxn], fa[maxn], siz[maxn];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}
bool check() {
	for (int i = 1; i <= n + 30; ++i) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 30; ++j)
			if ((a[i] >> j) & 1) merge(i, n + j + 1);
	int rt = get(1);
	for (int i = 2; i <= n; ++i)
		if (get(i) != rt) return 0;
	return 1;
}

void work() {
	read(n);
	int ans = 0;
	pii mx = {0, 0};
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		if (!a[i]) a[i]++, ans++;
	}
	if (check()) goto done;

	test: ;
	for (int i = 1; i <= n; ++i) {
		ans++, a[i]++;
		if (check()) goto done;
		a[i] -= 2;
		if (check()) goto done;
		ans--, a[i]++;
	}

	for (int i = 1; i <= n; ++i) mx = max(mx, (pii) {a[i] & (-a[i]), i});
	ans++, a[mx.sec]--;
	goto test;

	done: ;
	write(ans, '\n');
	for (int i = 1; i <= n; ++i) write(a[i], " \n"[i == n]);
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}