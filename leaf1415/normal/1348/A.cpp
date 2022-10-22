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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		llint ans = 0, cnt = 0, cnt2 = 0;
		for(int i = n; i >= 1; i--){
			if(cnt == n/2){
				ans += 1<<i;
				continue;
			}
			if(cnt2 == n/2){
				ans -= 1<<i;
				continue;
			}
			
			if(ans >= 0) ans -= 1<<i, cnt++;
			else ans += 1<<i, cnt2++;
		}
		cout << abs(ans) << endl;
	}
	
	return 0;
}