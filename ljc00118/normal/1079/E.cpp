#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 105;

int f[N][N * N], g[N][N * N], a[N], cnt[N];
int n, ans = 1, sum = 0, QAQ = 0;

inline int max(int a, int b) { return a > b ? a : b; } 

int main() {
	memset(f, -0x3f, sizeof(f)); read(n);
	for(register int i = 1; i <= n; i++) read(a[i]), cnt[a[i]]++, sum += a[i];
	f[0][0] = 0;
	for(register int i = 1; i <= 100; i++) {
		if(!cnt[i]) continue;
		memcpy(g, f, sizeof(g)); QAQ++;
		for(register int j = 1; j <= cnt[i]; j++) {
			int val = i * j;
			for(register int k = n; k >= j; k--) {
				for(register int t = sum; t >= val; t--) {
					g[k][t] = max(g[k][t], f[k - j][t - val] + 1);
				}
			}
		}
		memcpy(f, g, sizeof(f));
	}
	for(register int i = 1; i <= 100; i++) {
		for(register int j = 2; j <= cnt[i]; j++) {
//			fprintf(stderr, "f[%d][%d] = %d\n", j, i * j, f[j][i * j]);
			if(f[j][i * j] == 1) ans = max(ans, j);
		}
	}
	if(QAQ == 2) cout << n << endl;
	else cout << ans << endl;
	return 0;
}