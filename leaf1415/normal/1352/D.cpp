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
llint a[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint ans = 0, ans2 = 0, move = 0, pre = 0, l = 0, r = n+1;
		while(1){
			if(l+1 >= r) break;
			move++;
			
			llint sum = 0;
			while(sum <= pre && l+1 < r) l++, sum += a[l];
			ans += sum, pre = sum;
			
			if(l+1 >= r) break;
			move++;
			
			sum = 0;
			while(sum <= pre && l+1 < r) r--, sum += a[r];
			ans2 += sum, pre = sum;
		}
		cout << move << " " << ans << " " << ans2 << endl;
	}
	
	return 0;
}