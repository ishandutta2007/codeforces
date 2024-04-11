#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, Q;
vector<ll> G[200005];
int Prev[200005][18];
int depth[200005];

void predfs(int v, int p, int d)
{
	depth[v] = d;
	Prev[v][0] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		predfs(G[v][i], v, d+1);
	}
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);

	for(int i = 17; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 17; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

ll get(ll u, ll v)
{
	return depth[u]+depth[v]-2*depth[getLCA(u, v)];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> Q;
	ll p;
	rep(i, 2, n){
		cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}

	predfs(1, 0, 0);
	for(int i = 1; i < 18; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}

	ll a, b, c;
	rep(i, 1, Q){
		cin >> a >> b >> c;
		ll x[] = {get(a, b), get(b, c), get(c, a)};
		sort(x, x+3);
		cout << (x[1]+x[2]-x[0])/2 + 1 << "\n";
	}
	flush(cout);

	return 0;
}