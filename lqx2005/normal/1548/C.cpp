#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 3e6 + 10, P = 1e9 + 7;

int add(int x) {return x >= P ? x - P : x; }
int sub(int x) {return x < 0 ? x + P : x; }

void Add(int &x, int y) {if((x += y) >= P && (x -= P)); }
void Sub(int &x, int y) {if((x -= y) < 0 && (x += P)); }


int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

int n, q, fac[N], ifac[N], f[N][3];

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[n] = power(fac[n], P - 2);
	for(int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
	return;
}

int binom(int n, int m) {return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P; }

void initf() {
	for(int i = 1; i <= 3 * n; i++) {
		Add(f[3 * n][i % 3], binom(i, 3 * n));
	}
	for(int i = 3 * n - 1; i >= 1; i--) {
		f[i][0] = sub(f[i + 1][1] - f[i + 1][0]);
		Add(f[i][0], binom(3 * n + 1, i + 1));
		f[i][1] = sub(f[i + 1][2] - f[i + 1][1]);
		f[i][2] = sub(f[i + 1][0] - f[i + 1][2]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	init(N - 5);
	initf();
	for(int i = 1; i <= q; i++) {
		int x;
		cin >> x;
		cout << f[x][0] << endl;
	}
    return 0;
}