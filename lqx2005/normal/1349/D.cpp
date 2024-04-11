#include<bits/stdc++.h>

using namespace std;

#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 3e5 + 10, P = 998244353;
int n, c[N];

int add(int x) { return x >= P ? x - P : x; }
int sub(int x) { return x < 0 ? x + P : x; }

int qpow(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) res = 1ll * res * a % P;
	return res;
}

int main() {
	scanf("%d", &n);
	int m = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		c[x]++;
		m += x;
	}
	c[m] = sub(c[m] - 1);
	int inv = 1ll * m * (n - 1) % P * qpow(n, P - 2) % P;
	int f0 = 0, f1 = 0, ans = 0;
	for(int i = 0; i <= m; i++) {
		ans = sub(ans - 1ll * c[i] * f1 % P);
		swap(f0, f1);
		f1 = sub(1ll * f0 * sub(add(m + 1ll * n * i % P) - 2ll * i % P) % P - 1ll * i * (n - 1) % P * f1 % P);
		f1 = add(f1 + inv);
		f1 = 1ll * f1 * qpow(m - i, P - 2) % P;
	}
	printf("%d\n", ans);
	return 0;
}