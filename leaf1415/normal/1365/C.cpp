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

llint n;
llint a[200005], b[200005], binv[200005];
llint cnt[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
	for(int i = 0; i < n; i++) cin >> b[i], b[i]--;
	for(int i = 0; i < n; i++) binv[b[i]] = i;
	
	for(int i = 0; i < n; i++){
		cnt[(i-binv[a[i]]+n)%n]++;
	}
	llint ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, cnt[i]);
	}
	cout << ans << endl;
	
	return 0;
}