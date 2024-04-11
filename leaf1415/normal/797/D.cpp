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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " <<
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}

ll n;
ll a[100005], l[100005], r[100005];
bool used[100005];
vector<ll> vec;

ll get(ll l, ll r)
{
	if(l > r) return 0;
	return upper_bound(all(vec), r) - lower_bound(all(vec), l);
}

ll ans = 0;
void dfs(int v, ll d, ll u)
{
	if(d > u) return;

	//cout << d << " " << u << endl;

	if(l[v] == -1) ans += get(d, min(u, a[v]-1));
	else dfs(l[v], d, min(u, a[v]-1));

	if(r[v] == -1) ans += get(max(d, a[v]+1), u);
	else dfs(r[v], max(d, a[v]+1), u);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n){
		cin >> a[i] >> l[i] >> r[i];
		if(l[i] != -1) used[l[i]] = true;
		if(r[i] != -1) used[r[i]] = true;
		vec.push_back(a[i]);
	}
	sort(all(vec));

	ll root;
	rep(i, 1, n) if(!used[i]) root = i;

	dfs(root, 0, 1000000000);
	cout << ans << endl;

	return 0;
}