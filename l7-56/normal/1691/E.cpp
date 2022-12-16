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
int n;
struct seg {
	int c, l, r;
} a[maxn];
void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i].c, a[i].l, a[i].r);
	sort(a + 1, a + n + 1, [] (seg a, seg b) { return a.l < b.l; });
	multiset <int> s[2];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int c = a[i].c, l = a[i].l, r = a[i].r;
		while (!s[0].empty() && (*s[0].begin()) < l) s[0].erase(s[0].begin());
		while (!s[1].empty() && (*s[1].begin()) < l) s[1].erase(s[1].begin());
		if (s[0].size() && s[1].size())
			s[c].insert(r), s[c].erase(s[c].begin());
		else if (s[!c].size()) {
			while ((int) s[!c].size() > 1) --ans, s[!c].erase(s[!c].begin());
			s[c].insert(r);
		}
		else ++ans, s[c].insert(r);
	}
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}