#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll MAXN = 504;
bool a[MAXN][MAXN];
char ans[MAXN];
vector<ll> g[MAXN];
ll col[MAXN];
void dfs(ll x, ll p, ll color) {
	col[x] = color;
	for (auto &y: g[x]) {
		if (y==p) continue;
		if (col[y] == UNDEF) {
			dfs(y,x, color^1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin >> n >> m;
	for (ll x = 0; x <= n; x++) {
		for (ll y = 0; y <= n; y++) {
			a[x][y] = false;
		}
	}
	for (ll i=0;i<m;i++) {
		ll x,y; cin >> x >> y;
		x--; y--;
		a[x][y] = true;
		a[y][x] = true;
	}
	for (ll x = 0; x < n; x++) {
		for (ll y = x+1; y < n; y++) {
			if (a[x][y] == false) {
				g[x].PB(y);
				g[y].PB(x);
			}
		}
	}
	for (ll x=0;x<n;x++) {
		col[x] = UNDEF;
	}
	for (ll x = 0; x < n; x++) {
		if (g[x].size() == 0) {
			ans[x] = 'b';
		}
		else {
			if (col[x] == UNDEF) {
				dfs(x,-1,0);
			}
		}
	}
	for (ll x=0;x<n;x++) {
		if (col[x] == 0) {
			ans[x] = 'a';
		}
		else if (col[x] == 1) {
			ans[x] = 'c';
		}
	}
	ans[n] = '\0';
	bool ok = true;
	for (ll x=0;x<n;x++) {
		for (ll y=x+1;y<n;y++) {
			if (a[x][y]) {
				if (abs(ans[x]-ans[y]) == 2) {
					ok = false;
				}
			}
			else {
				if (!(2 == abs(ans[x] - ans[y]))) {
					ok = false;
				}
			}
		}
	}
	if (ok) {
		printf("Yes\n");
		printf("%s\n",ans);
	}
	else {
		printf("No\n");
	}


}