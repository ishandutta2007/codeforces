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

llint n, m;
llint l[100005];
llint ans[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> l[i];
	
	llint sum = 0;
	for(int i = 1; i <= m; i++) sum += l[i];
	if(sum < n){
		cout << -1 << endl;
		return 0;
	}
	
	llint p = 0;
	for(int i = m; i >= 1; i--){
		sum -= l[i];
		p = max(p+1, l[i]);
		p = max(p, n-sum);
		//cout << p << endl;
		if(p > n){
			cout << -1 << endl;
			return 0;
		}
		ans[i] = p-l[i]+1;
	}
	
	for(int i = 1; i <= m; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}