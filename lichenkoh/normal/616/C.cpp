#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXN 1004
#define MAXID 1000004
char a[MAXN][MAXN];
ll f[MAXN][MAXN];
ll g[MAXID];
char final[MAXN][MAXN];
bool seen[MAXN][MAXN];
inline bool valid(ll x, ll y) {
	return seen[x][y] == false && a[x][y] == '.';
}
void bfs(ll initx, ll inity, ll id) {
	if (!valid(initx,inity)) return;
	queue<pair<ll,ll> > q;
	vector<pair<ll,ll> > w;
	q.push(MP(initx,inity));
	seen[initx][inity] = true;
	ll ans = 0;
	while(!q.empty()) {
		pair<ll,ll> v = q.front();
		q.pop();
		w.PB(v);
		ans++;
		{
			ll y = v.second;
			for (ll x = v.first-1; x <= v.first+1; x += 2) {
				if (valid(x,y)){
					seen[x][y] = true;
					q.push(MP(x,y));
				}
			}
		}
		{
			ll x = v.first;
			for (ll y = v.second-1; y <= v.second+1; y += 2){
				if (valid(x,y)){
					seen[x][y] = true;
					q.push(MP(x,y));
				}
			}
		}
	}
	g[id] = ans;
	for (auto& v: w) {
		f[v.first][v.second] = id;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin >> n >> m;
	for (ll x = 0; x < MAXN; x++) {
		for (ll y = 0; y < MAXN; y++) {
			a[x][y] = '*';
			seen[x][y] = false;
		}
	}
	for (ll i = 0; i < MAXID; i++) {
		g[i] = 0;
	}
	for (ll i = 1; i <= n; i++) {
		string s; cin >> s;
		for (ll j = 1; j <= m; j++) {
			a[i][j] = s[j-1];
		}
	}
	ll id = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (valid(i,j)) {
				bfs(i,j,id);
				id++;
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (a[i][j] == '*') {
				set<ll> s;
				{
					ll y = j;
					for (ll x = i-1; x <= i+1; x += 2) {
						if (a[x][y] == '.'){
							s.insert(f[x][y]);
						}
					}
				}
				{
					ll x = i;
					for (ll y = j-1; y <= j+1; y += 2){
						if (a[x][y] == '.'){
							s.insert(f[x][y]);
						}
					}
				}
				ll ans = 1;
				for (auto& id: s) {
					ans += g[id];
				}
				ans = ans%10;
				char c = '0' + ans;
				final[i-1][j-1] = c;
			}
			else {
				final[i-1][j-1] = '.';
			}
		}
		final[i-1][m] = '\0';
	}
	for (ll i = 0; i < n; i++) {
		printf("%s\n", final[i]);
	}
}