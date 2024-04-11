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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		k %= 2;
		k += 2;
		
		for(int i = 0; i < k; i++){
			llint mx = -inf;
			for(int j = 1; j <= n; j++) mx = max(mx, a[j]);
			for(int j = 1; j <= n; j++) a[j] = mx - a[j];
		}
		
		for(int j = 1; j <= n; j++) cout << a[j] << " "; cout << endl;
	}
	
	return 0;
}