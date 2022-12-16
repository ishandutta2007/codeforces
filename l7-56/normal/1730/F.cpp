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

const int maxn = 5010;
int n, k, p[maxn], pos[maxn], f[maxn][256], c[maxn];
void chkmn(int &a, int b) { if (a > b) a = b; }

int main() {
	read(n, k);
	for (int i = 1; i <= n; ++i) read(p[i]), pos[p[i]] = i;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j) c[i] += (pos[j] > pos[i]);
	f[1][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int s = 0; s < (1 << k); ++s) if (f[i][s] < 1e9) {
			int cst = c[i];
			for (int j = 0; j < k; ++j) if ((s >> j) & 1) cst += (pos[i + j + 1] > pos[i]);
			int j = 0;
			while (j < k && ((s >> j) & 1)) ++j;
			chkmn(f[i + j + 1][s >> (j + 1)], f[i][s] + cst);
			// printf("%d %d : %d -%d>\n", i, s, f[i][s], cst);
			for (j = 0; j < k; ++j) if (!((s >> j) & 1)) {
				cst = c[i + j + 1] - (pos[i] > pos[i + j + 1]);
				for (int l = 0; l < j; ++l) if (!((s >> l) & 1)) cst -= (pos[i + l + 1] > pos[i + j + 1]);
				for (int l = j; l < k; ++l) if ((s >> l) & 1) cst += (pos[i + l + 1] > pos[i + j + 1]);
				// printf("-%d %d>\n", j, cst);
				chkmn(f[i][s | (1 << j)], f[i][s] + cst);
			}
		}
	write(f[n + 1][0], '\n');
	return 0;
}