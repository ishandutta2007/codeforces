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

const int maxn = 40;
int n,k,a[maxn],r[maxn],c[maxn],s[maxn][maxn];

int main() {
	read(n, k);
	set <int> st; st.insert(0);
	for (int i = 1, v = 0; i <= n; ++i) {
		for (a[i] = 1; st.find(v ^ a[i]) != st.end(); a[i] <<= 2);
		st.insert(v ^= a[i]);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < n; ++j)
			write(r[j] = a[j], " \n"[j == n - 1]);
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= n; ++j)
			write(c[i] = a[i] << 1, " \n"[j == n]);
	fflush(stdout);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			s[i][j] = i == 1 ? s[i][j - 1] ^ r[j - 1] : s[i - 1][j] ^ c[i - 1];
	int lst = s[1][1];
	while (k--) {
		int x; read(x);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if ((lst ^ s[i][j]) == x) {
					write(i, ' ', j, '\n');
					lst = s[i][j];
					goto done;
				}
		done : fflush(stdout);
	}
	return 0;
}