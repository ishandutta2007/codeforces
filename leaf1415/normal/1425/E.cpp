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

using namespace std;

typedef long long llint;
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
typedef pair<llint, llint> P;

llint n, k;
llint a[100005], d[100005];
llint sum[100005], lmin[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> d[i];
	
	lmin[0] = inf;
	rep(i, 1, n){
		sum[i] = sum[i-1] + a[i];
		lmin[i] = min(lmin[i-1], d[i]);
	}
	
	llint ans = 0;
	if(k == 0){
		rep(i, 1, n) chmax(ans, (sum[n]-sum[i-1])-d[i]);
	}
	if(k == 1){
		rep(i, 2, n-1) chmax(ans, max(0LL, sum[i]-lmin[i]) + max(0LL, (sum[n]-sum[i])-d[i+1]));
		rep(i, 2, n-1) chmax(ans, sum[n]-d[1]-d[i]);
		rep(i, 2, n-1) chmax(ans, sum[n]-a[i]-d[1]);
		chmax(ans, sum[n]-a[2]-d[1]);
		chmax(ans, sum[n]-a[1]-d[2]);
	}
	if(k >= 2){
		chmax(ans, a[n]-d[n]);
		chmax(ans, sum[n]-lmin[n-1]);
	}
	cout << ans << endl;
	
	return 0;
}