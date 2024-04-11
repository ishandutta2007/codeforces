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
int t, n, k;
int main() {
	scanf("%d", &t);
	rep(amo, 1, t) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) printf("%c", (char)('a' + i % 3));
		printf("\n");
	}
	return 0;
}