#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e5 + 10;
int n, m, c[N], a[N];
vector<int> g[N];
void work() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) c[i] = 0;
	rep(i, 1, m) {
		int k;
		scanf("%d", &k);
		g[i].resize(k);
		rep(j, 0, k - 1) scanf("%d", &g[i][j]);
	}
	rep(i, 1, m) {
		if(SZ(g[i]) == 1) c[g[i][0]]++, a[i] = g[i][0];
	}
	rep(i, 1, n) if(c[i] > (m + 1) / 2) return printf("NO\n"), void();
	rep(i, 1, m) {
		if(SZ(g[i]) == 1) continue;
		int l = g[i][0], r = g[i][1];
		if(c[l] + 1 <= (m + 1) / 2) c[l]++, a[i] = g[i][0];
		else c[r]++, a[i] = g[i][1];
	}
	printf("YES\n"); 
	rep(i, 1, m) printf("%d ", a[i]);
	printf("\n");
	return;
}
int main() {
	int T;
	scanf("%d", &T);
	for(; T--; ) work(); 
	return 0;
}