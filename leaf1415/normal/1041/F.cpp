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

llint n, m, y1, y2;
llint a[100005], b[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> y1;
	rep(i, 1, n) cin >> a[i];
	cin >> m >> y2;
	rep(i, 1, m) cin >> b[i];
	
	llint ans = 0;
	map<llint, llint> mp;
	rep(i, 1, n) mp[a[i]]++;
	rep(i, 1, m) mp[b[i]]++;
	for(auto x:mp) chmax(ans, x.second);
	
	rep(i, 0, 35){
		llint w = (1LL<<i)*2;
		map<llint, llint> mp;
		rep(j, 1, n) mp[a[j]%w]++;
		rep(j, 1, m) mp[(b[j]+w/2)%w]++;
		for(auto x:mp) chmax(ans, x.second);
	}
	cout << ans << endl;
	
	return 0;
}