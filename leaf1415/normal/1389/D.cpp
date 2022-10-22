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

llint T;
llint n, k;
llint l, r, L, R;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> l >> r >> L >> R;
		
		llint in = min(r, R) - max(l, L), out = max(r, R) - min(l, L);
		if(in > 0){
			llint rem = k - in*n;
			if(rem <= 0){
				cout << 0 << endl;
				continue;
			}
			if(rem <= (out-in) * n){
				cout << rem << endl;
				continue;
			}
			llint ans = (out-in) * n;
			rem -= (out-in) * n;
			ans += rem * 2;
			cout << ans << endl;
			continue;
		}
		
		in *= -1;
		llint ans = inf;
		for(int i = 1; i <= n; i++){
			llint tmp = in * i;
			if(k <= out * i) tmp += k;
			else tmp += out*i + (k-out*i)*2;
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
	
	return 0;
}