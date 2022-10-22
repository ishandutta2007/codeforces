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
llint a, k;

llint get(llint x)
{
	llint mx = 0, mn = 10;
	for(;x;x/=10){
		mx = max(mx, x%10);
		mn = min(mn, x%10);
	}
	return mx * mn;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> k;
		
		for(int i = 2; i <= k; i++){
			llint res = get(a);
			if(res == 0) break;
			a += res;
		}
		cout << a << endl;
	}
	
	return 0;
}