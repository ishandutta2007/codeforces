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
int n, m, a[maxn], b[maxn], cnt[maxn];
ll s[maxn];
pii seg[maxn];
vector <int> d[maxn];

void work() {
	read(n, m);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i) read(b[i]);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i] - b[i];
	set <int> st; queue <int> q;
	for (int i = 0; i <= n; ++i) {
		d[i].clear();
		if (s[i]) st.insert(i);
	}
	for (int i = 1; i <= m; ++i) {
		read(seg[i].fir, seg[i].sec);
		d[seg[i].fir - 1].push_back(i);
		d[seg[i].sec].push_back(i);
		cnt[i] = 2;
	}
	auto expand = [&] (int pos) {
		s[pos] = 0, st.erase(pos);
		for (int i : d[pos])
			if (--cnt[i] == 0) q.push(i);
	};
	for (int i = 0; i <= n; ++i) if (!s[i]) expand(i);
	while (!q.empty()) {
		int o = q.front(); q.pop();
		auto it = st.lower_bound(seg[o].fir);
		while (it != st.end() && *it <= seg[o].sec) { int x = *(it++); expand(x); }
	}
	for (int i = 0; i <= n; ++i) if (s[i]) return printf("NO\n"), void();
	printf("YES\n");
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}