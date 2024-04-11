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
const int N = 1000 + 10, P = 998244353;
int m, a[N], n;

int qpow(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) res = 1ll * res * a % P;
	return res;
}

int main() {
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d", &a[i]), n += a[i];
	if(m == 1) return printf("0\n"), 0;
	sort(a + 1, a + m + 1);
	int f0 = 0, f1 = 2ll * n % P;
	int num = n;
	int now = 0, ans = 0;
	for(int i = 1; i < n; i++) {
		while(now + 1 <= m && a[now + 1] == i) {
			ans = (ans - 1ll * f1 * qpow(num, P - 2) % P + P) % P;
			now++;
		}
		swap(f0, f1);
		num = 1ll * num * (n - i) % P;
		f1 = (1ll * f0 * (3 * n - 2 * i) % P - 1ll * f1 * (2 * n - i) % P * (n - i + 1) % P + P) % P;
	}
	ans = (ans + 1ll * f1 * qpow(num, P - 2) % P) % P;
	printf("%d\n", ans);
	return 0;
}