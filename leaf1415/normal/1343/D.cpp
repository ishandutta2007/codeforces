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
llint a[200005];
llint dif[400005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 2; i <= 2*k; i++) dif[i] = 0;
		
		for(int i = 1; i <= n/2; i++){
			llint x = a[i], x2 = a[n+1-i];
			if(x > x2) swap(x, x2);
			llint l = max(2LL, x+1), r = min(2*k, x+k);
			llint l2 = max(2LL, x2+1), r2 = min(2*k, x2+k);
			if(r >= l2) dif[l]++, dif[r2+1]--;
			else{
				dif[l]++, dif[r+1]--;
				dif[l2]++, dif[r2+1]--;
			}
		}
		for(int i = 2; i <= 2*k; i++) dif[i] += dif[i-1];
		
		for(int i = 1; i <= n/2; i++){
			llint x = a[i], x2 = a[n+1-i];
			dif[x+x2]++;
		}
		
		llint ans = n/2*2, mx = 0;
		for(int i = 2; i <= 2*k; i++) mx = max(mx, dif[i]);
		ans -= mx;
		
		cout << ans << "\n";
	}
	flush(cout);
	return 0;
}