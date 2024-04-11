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

ll n, m, Q;
ll a[100005], b[100005];
ll asum[2][100005], bsum[2][100005];
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) cin >> b[i];
	
	rep(i, 1, n){
		asum[0][i] = asum[0][i-1];
		asum[1][i] = asum[1][i-1];
		asum[i%2][i] += a[i];
	}
	rep(i, 1, m){
		bsum[0][i] = bsum[0][i-1];
		bsum[1][i] = bsum[1][i-1];
		bsum[i%2][i] += b[i];
	}
	
	ll sum = asum[1][n] - asum[0][n];
	rep(i, 1, m){
		ll r = i+n-1;
		if(r > m) break;
		vec.push_back(- (bsum[(i+1)%2][r] - bsum[(i+1)%2][i-1]) + (bsum[i%2][r] - bsum[i%2][i-1]));
	}
	sort(all(vec));
	
	ll p = lower_bound(all(vec), sum) - vec.begin();
	ll ans = inf;
	if(p < vec.size()) chmin(ans, abs(vec[p] - sum));
	if(p-1 >= 0) chmin(ans, abs(vec[p-1] - sum));
	cout << ans << "\n";
	
	
	ll l, r, x;
	rep(q, 1, Q){
		cin >> l >> r >> x;
		ll e = r/2-(l-1)/2, o = r-l+1 - e;;
		sum += o*x - e*x;
		
		ll p = lower_bound(all(vec), sum) - vec.begin();
		ll ans = inf;
		if(p < vec.size()) chmin(ans, abs(vec[p] - sum));
		if(p-1 >= 0) chmin(ans, abs(vec[p-1] - sum));
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}