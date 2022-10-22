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

llint n, Q;
llint a[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i], mp[a[i]]++;
	
	llint x;
	rep(i, 1, Q){
		cin >> x;
		llint ans = 0;
		for(int i = 40; i >= 0; i--){
			llint c = mp[1LL<<i];
			llint u = min(x / (1LL<<i), c);
			ans += u, x -= u * (1LL<<i);
		}
		if(x == 0) cout << ans << "\n";
		else cout << -1 << "\n";
	}
	
	return 0;
}