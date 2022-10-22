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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
ll a[100005];
ll dp[25][100005];

ll cost, cl, cr;
ll occ[100005];

void add(ll x)
{
	cost += occ[a[x]];
	occ[a[x]]++;
}
void del(ll x)
{
	occ[a[x]]--;
	cost -= occ[a[x]];
}

ll getcost(ll l, ll r)
{
	while(l < cl) cl--, add(cl);
	while(cr < r) cr++, add(cr);
	while(cl < l) del(cl), cl++;
	while(r < cr) del(cr), cr--;
	return cost;
}

void calc(ll i, ll l, ll r, ll L, ll R)
{
	if(l > r) return;
	ll m = (l+r)/2;
	
	ll min_val = inf, min_j;
	assert(L <= min(R, m-1));
	for(int j = L; j <= min(R, m-1); j++){
		ll val = dp[i-1][j] + getcost(j+1, m);
		if(min_val > val){
			min_val = val;
			min_j = j;
		}
	}
	dp[i][m] = min_val;
	
	calc(i, l, m-1, L, min_j);
	calc(i, m+1, r, min_j, R);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) add(i);
	cl = 1, cr = n;
	
	rep(i, 0, k) rep(j, 0, n) dp[i][j] = inf/10;
	dp[0][0] = 0;
	
	rep(i, 1, k) calc(i, 1, n, 0, n);
	cout << dp[k][n] << endl;
	
	return 0;
}