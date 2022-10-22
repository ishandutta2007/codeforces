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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m, ta, tb, k;
llint a[200005], b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> ta >> tb >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	if(min(n, m) <= k){
		cout << -1 << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int i = 0; i <= k; i++){
		llint d = a[i+1]+ta;
		llint p = lower_bound(b+1, b+m+1, d) - b;
		if(p+(k-i) > m){
			cout << -1<< endl;
			return 0;
		}
		ans = max(ans, b[p+(k-i)]+tb);
	}
	cout << ans << endl;
	
	return 0;
}