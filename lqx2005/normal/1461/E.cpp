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
typedef long double db;
const int N = 1e6 + 10; 
ll l, r, k, x, y, t;
ll vis[N];
int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y);
	k -= l, r -= l;
	if(y < x) {
		if(k + y <= r) k += y;
		if((k - y) / (x - y) >= t) printf("Yes\n");
		else printf("No\n");
		return 0;
	}
	ll now = k;
	ll tim = 0;
	while(!vis[now % x] && tim < t) {
		tim += (now / x);
		vis[now % x] = 1;
		now = now % x + y;
		if(now > r) break;
	}
	if(tim >= t) printf("Yes\n");
	else {
		if(now > r) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}