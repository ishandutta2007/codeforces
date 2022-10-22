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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 1000000007


using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, root, Q;
vector<ll> G[100005];
ll a[100005];
ll depth[100005], l[100005], r[100005];
vector<P> vec;
const ll B = 320;
ll mn[320][100005];


void dfs(int v, int p, int d)
{
	l[v] = vec.size();
	depth[v] = d;
	vec.push_back(P(a[v], d));
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v, d+1);
	}
	r[v] = (int)vec.size()-1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> root;
	rep(i, 1, n) cin >> a[i];
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(root, -1, 0);
	
	//rep(i, 1, n) cout << depth[i] << " " << l[i] << " " << r[i] << endl;
	
	ll Bmax = (n-1)/B;
	rep(i, 0, Bmax) rep(j, 0, n) mn[i][j] = inf;
	rep(i, 0, n-1) chmin(mn[i/B][vec[i].second], vec[i].first);
	rep(i, 0, Bmax) rep(j, 1, n) chmin(mn[i][j], mn[i][j-1]);
	
	cin >> Q;
	ll p, q, x, k, ans = 0;
	while(Q--){
		cin >> p >> q;
		x = (p+ans)%n+1, k = (q+ans)%n;
		
		ll L = l[x], R = r[x], d = min(n, depth[x] + k); ans = inf;
		//cout << L << " " << R << endl;
		if(L/B == R/B){
			rep(i, L, R){
				if(vec[i].second <= d) chmin(ans, vec[i].first);
			}
		}
		else{
			ll LL = (L+B-1)/B*B, RR = R/B*B;
			rep(i, L, LL-1) if(vec[i].second <= d) chmin(ans, vec[i].first);
			rep(i, RR, R) if(vec[i].second <= d) chmin(ans, vec[i].first);
			rep(i, LL/B, RR/B-1) chmin(ans, mn[i][d]);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}