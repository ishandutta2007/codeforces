// LUOGU_RID: 92595691
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
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
int n, q, m, cnt[maxn], lg[1 << 20];

int main() {
	for (int i = 0; i < 20; ++i) lg[1 << i] = i;
	read(n, q);
	ll ans = 0;
	for (int t = n; t; ) {
		++m;
		int x = min(t, (m + 1) / 2);
		t -= x, ans += (ll) x * m;
		cnt[m - (x * 2 - 1)]++, cnt[m + 1]--;
	}
	write(ans, '\n');
	for (int i = 2; i <= m; ++i) cnt[i] += cnt[i - 2];
	int x = 0, sum = 0;
	while (q--) {
		int k; read(k), k -= sum;
		while (k >= 2 * cnt[x]) k -= cnt[x], sum += cnt[x], ++x;
		int lbt = lg[k & -k];
		write(x + (k >> lbt) + lbt, '\n');
	}
	return 0;
}