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
P p[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i].second >> p[i].first;
	
	llint sum = 0;
	for(int i = 1; i <= n; i++) sum += p[i].second;
	if(sum < 0){
		for(int i = 1; i <= n; i++) p[i].second *= -1;
	}
	sort(p+1, p+n+1);
	
	llint ans = 0;
	for(int i = 0; i < 62; i++){
		llint l = lower_bound(p+1, p+n+1, P(1LL<<i, -inf)) - p, r = lower_bound(p+1, p+n+1, P(1LL<<(i+1), -inf)) - p;
		sum = 0;
		for(int j = l; j < r; j++) sum += p[j].second;
		if(sum > 0){
			ans |= 1LL<<i;
			for(int j = 1; j <= n; j++){
				if(p[j].first & (1LL<<i)) p[j].second *= -1;
			}
		}
	}
	cout << ans << endl;
	
	
	return 0;
}