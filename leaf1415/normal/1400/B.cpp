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
llint p, f;
llint A, B, a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> p >> f;
		cin >> A >> B >> a >> b;
		if(a > b){
			swap(A, B);
			swap(a, b);
		}
		
		llint ans = 0;
		for(int i = 0; i <= A; i++){
			if(i*a > p) break;
			llint j = min(B, (p-a*i)/b);
			llint x = min(A-i, f/a);
			llint y = min(B-j, (f-x*a)/b);
			ans = max(ans, i+j+x+y);
		}
		cout << ans << endl;
	}
	
	return 0;
}