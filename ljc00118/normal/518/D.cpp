#include <bits/stdc++.h>
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

const int N = 2005;

double f[N][N];
int n, t;
double p, ans;

int main() {
	cin >> n >> p >> t;
	f[0][0] = 1.0;
	for(register int i = 1; i <= t; i++) f[0][i] = f[0][i - 1] * (1.0 - p);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= t; j++) {
			f[i][j] = f[i - 1][j - 1] * p + f[i][j - 1] * ((i < n) ? (1.0 - p) : 1.0);
		}
		ans += f[i][t] * (double)i;
	}
	printf("%.7lf\n", ans);
	return 0;
}