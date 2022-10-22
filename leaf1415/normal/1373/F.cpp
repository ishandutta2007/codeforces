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
#define inf 2e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
llint a[1000005], b[1000005];

llint calc(llint x)
{
	for(int i = 1; i < n; i++){
		llint d = a[i] - x;
		if(d > b[i]) return -inf;
		x = min(a[(i+1)%n], b[i] - d);
	}
	return x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		
		llint ub = min(b[0], a[1]), lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(calc(mid) >= 0) ub = mid;
			else lb = mid;
		}
		
		if(calc(ub) + (b[0]-ub) >= a[0]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}