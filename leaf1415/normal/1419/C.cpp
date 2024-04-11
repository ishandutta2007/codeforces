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
llint n;
llint x, a[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint sum = 0, mn = inf, mx = -inf;
		for(int i = 1; i <= n; i++){
			sum += a[i];
			chmin(mn, a[i]);
			chmax(mx, a[i]);
		}
		if(mn == mx && mn == x) cout << 0 << endl;
		else if(sum == x*n) cout << 1 << endl;
		else{
			llint cnt = 0;
			for(int i = 1; i <= n; i++) if(a[i] == x) cnt++;
			if(cnt) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	
	return 0;
}