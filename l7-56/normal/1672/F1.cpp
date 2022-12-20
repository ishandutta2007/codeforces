#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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
int n,a[maxn],b[maxn];
vector <int> c[maxn];
void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]), c[a[i]].push_back(i);
	vector <int> p(n);
	iota(p.begin(), p.end(), 1);
	sort(p.begin(), p.end(), [](int x, int y) { return c[x].size() > c[y].size(); });
	while (!c[p[0]].empty()) {
		vector <int> cir;
		for (int i : p) {
			if (c[i].empty()) break;
			cir.push_back(c[i].back()), c[i].pop_back();
		}
		int len = cir.size();
		for (int i = 0; i < len; ++i) b[cir[i]] = a[cir[(i + 1) % len]];
	}
	for (int i = 1; i <= n; ++i) write(b[i], " \n"[i == n]);
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}