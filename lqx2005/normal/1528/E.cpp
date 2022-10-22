#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sit set<int>::iterator

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e6 + 10, P = 998244353, iv2 = (P + 1) / 2, iv6 = (P + 1) / 6;
int n, f[N], g[N], a[N], b[N], c[N];

void Add(int &x, int y) { if((x += y) >= P && (x -= P)); }
void Sub(int &x, int y) { if((x -= y) < 0 && (x += P)); }
int add(int x) { return x >= P ? x - P : x; }
int sub(int x) { return x < 0 ? x + P : x; } 

int main() {
	cin >> n;
	f[0] = g[0] = 1;
	for(int i = 1; i <= n + 1; i++) {
		f[i] = add(1ll * f[i - 1] * (f[i - 1] + 1) % P * iv2 % P + 1);
		g[i] = 1ll * add(add(1ll * f[i - 1] * f[i - 1] % P * f[i - 1] % P + 3ll * f[i - 1] % P * f[i - 1] % P) + 2ll * f[i - 1] % P) * iv6 % P;
		Add(g[i], 1);
	}
	for(int i = n + 1; i >= 1; i--) Sub(g[i], g[i - 1]), Sub(f[i], f[i - 1]);
	for(int i = 1; i <= n + 1; i++) {
		a[i] = f[i - 1];
		b[i] = sub(f[i] - a[i]);
		c[i] = sub(g[i] - f[i]);
	}
	int ns = add(add(g[n + 1] + b[n + 1]) + c[n + 1]);
	for(int i = 1; i <= n - 1; i++) Add(ns, 1ll * b[i + 1] * a[n - i + 1] % P);
	printf("%d\n", ns);
	return 0;
}