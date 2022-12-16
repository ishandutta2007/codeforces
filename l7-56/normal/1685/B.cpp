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
int a, b, c, d, n;
char s[maxn];
void work() {
	scanf("%d%d%d%d%s", &a, &b, &c, &d, s + 1), n = strlen(s + 1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += s[i] == 'A';
	if (cnt != a + c + d) return write("NO\n");
	vector <int> v[3];
	s[n + 1] = s[n];
	for (int l = 1, r; l <= n; l = r + 1) {
		for (r = l; r <= n && s[r] != s[r + 1]; ++r);
		if (s[l] == s[r]) v[0].push_back((r - l) / 2);
		else if (s[l] == 'A') v[1].push_back((r - l + 1) / 2);
		else v[2].push_back((r - l + 1) / 2);
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());
	int l0 = v[0].size(), l1 = v[1].size(), l2 = v[2].size();
	for (int i = 0; i < l1; ++i) {
		int len = v[1][i];
		if (len < c) c -= len;
		else {
			d -= max(len - 1 - c, 0);
			for (++i; i < l1; ++i) d -= v[1][i] - 1;
			for (i = 0; i < l2; ++i) d -= v[2][i];
			for (i = 0; i < l0; ++i) d -= v[0][i];
			return write(d <= 0 ? "YES\n" : "NO\n");
		}
	}
	for (int i = 0; i < l2; ++i) {
		int len = v[2][i];
		if (len < d) d -= len;
		else {
			c -= max(len - 1 - d, 0);
			for (++i; i < l2; ++i) c -= v[2][i] - 1;
			for (i = 0; i < l0; ++i) c -= v[0][i];
			return write(c <= 0 ? "YES\n" : "NO\n");
		}
	}
	c += d;
	for (int i = 0; i < l0; ++i) c -= v[0][i];
	write(c <= 0 ? "YES\n" : "NO\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}