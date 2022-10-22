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
llint ans[10005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n == 1){
		cout << "! " << 1 << endl;
		return 0;
	}
	
	llint p = 1, res, res2;
	for(int i = 2; i <= n; i++){
		cout << "? " << p << " " << i << endl;
		cin >> res;
		cout << "? " << i << " " << p << endl;
		cin >> res2;
		
		if(res > res2){
			ans[p] = res;
			p = i;
		}
		else ans[i] = res2;
	}
	ans[p] = n;
	
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}