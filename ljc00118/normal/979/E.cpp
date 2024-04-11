#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int md = 1e9 + 7;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += md;
	return x;
}

const int N = 2e5 + 5;

int Pow[N], a[N], f[N][2][2][2][2][2];
int n, p, ans;

int main() {
	read(n); read(p);
	for(register int i = 1; i <= n; i++) read(a[i]);
	Pow[0] = 1; for(register int i = 1; i <= n; i++) Pow[i] = mul(Pow[i - 1], 2);
	f[0][0][0][0][0][0] = 1;
	rep(i, 1, n) rep(x, 0, 1) rep(y, 0, 1) rep(_x, 0, 1) rep(_y, 0, 1) rep(sum, 0, 1) {
		int &res = f[i][x][y][_x][_y][sum]; if(x + y + _x + _y > i) continue;
		if(a[i] != 0 && x && _y) rep(j, 0, 1) res = add(res, mul(f[i - 1][j][y][_x][_y][sum], Pow[i - 2]));
		if(a[i] != 0 && y && _y) rep(j, 0, 1) res = add(res, mul(f[i - 1][x][j][_x][_y][sum ^ 1], Pow[i - 2]));
		if(a[i] != 0 && y && (_y ^ 1)) rep(j, 0, 1) res = add(res, mul(f[i - 1][x][j][_x][_y][sum ^ 1], Pow[i - 1]));
		if(a[i] != 1 && y && _x) rep(j, 0, 1) res = add(res, mul(f[i - 1][x][y][j][_y][sum], Pow[i - 2]));
		if(a[i] != 1 && y && _y) rep(j, 0, 1) res = add(res, mul(f[i - 1][x][y][_x][j][sum ^ 1], Pow[i - 2]));
		if(a[i] != 1 && (y ^ 1) && _y) rep(j, 0, 1) res = add(res, mul(f[i - 1][x][y][_x][j][sum ^ 1], Pow[i - 1]));
		if(i == n && sum == p) ans = add(ans, res);
//		printf("f[%d][%d][%d][%d][%d][%d] = %d\n", i, x, y, _x, _y, sum, res);
	}
	cout << ans << endl;
	return 0;
}

// Rotate Flower Round.