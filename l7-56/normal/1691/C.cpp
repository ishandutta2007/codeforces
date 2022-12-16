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

const int maxn = 1e5 + 10;
int n, k;
char s[maxn];

void work() {
	scanf("%d%d%s", &n, &k, s + 1);
	vector <int> pos;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		if (s[i] == '1') pos.push_back(i), sum += 10 * (i < n) + (i > 1);
	if (!pos.size()) return write("0\n");
	int ans = sum;
	if ((int) pos.size() == 1) {
		int p = pos[0];
		if (p - 1 <= k) ans = min(ans, 10);
		if (n - p <= k) ans = min(ans, 1);
		return write(ans, '\n');
	}
	int lp = pos[0], rp = pos.back();
	if (lp - 1 <= k) ans = min(ans, sum - (lp > 1));
	if (n - rp <= k) ans = min(ans, sum - 10 * (rp < n));
	if (lp - 1 + n - rp <= k) ans = min(ans, sum - (lp > 1) - 10 * (rp < n));
	write(ans, '\n');
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}