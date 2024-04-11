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
typedef pair<llint, llint> P;

llint n, m, x;
llint a[2005], b[2005];
llint asum[2005], bsum[2005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) cin >> b[i];
	cin >> x;
	
	rep(i, 1, n) asum[i] = asum[i-1] + a[i];
	rep(i, 1, m) bsum[i] = bsum[i-1] + b[i];
	
	rep(i, 1, m){
		rep(j, i, m){
			vec.push_back(P(bsum[j]-bsum[i-1], j-i+1));
		}
	}
	sort(all(vec));
	
	llint mx = 0;
	for(auto &x : vec){
		chmax(mx, x.second);
		x.second = mx;
	}
	
	llint ans = 0;
	rep(i, 1, n){
		rep(j, i, n){
			llint p = upper_bound(all(vec), P(x/(asum[j]-asum[i-1]), inf)) - vec.begin();
			p--;
			if(p >= 0) chmax(ans, (j-i+1)*vec[p].second);
		}
	}
	cout << ans << endl;
	
	return 0;
}