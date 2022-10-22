#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 110;
int t, n, k;
ll a[N];
int main() {
	scanf("%d", &t);
	for(; t--; ) {
		scanf("%d%d", &n, &k);
		n--;
		for(int i = 0; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		for(int i = 1; i <= n; i++) a[i] += a[i - 1];
		ll mx = 0;
		for(int i = 1; i <= n; i++) {
			ll d = a[i] - a[i - 1];
			mx = max(mx, (d * 100 + k - 1) / k - a[i - 1]);
		}
		printf("%lld\n", mx);
	}
	return 0;
}