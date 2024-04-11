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
int n, p, k;
map<int, int> cnt;
int main() {
	scanf("%d%d%d", &n, &p, &k);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int y = 1ll * x * x % p * x % p * x % p;
		y = (y - 1ll * k * x % p + p) % p;
		cnt[y]++;
	}
	LL ans = 0;
	for(auto v : cnt) ans += 1ll * v.y * (v.y - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}