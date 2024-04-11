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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint T;
llint a, b, c, d;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> a >> b >> c >> d;
		if(a > b*c){
			cout << -1 << endl;
			continue;
		}
		if(c < d){
			cout << a << endl;
			continue;
		}
		llint m = (c+1+d-1)/d;
		llint x = (2*a-b*d) / (2*b*d);
		
		llint ans = 0;
		for(int i = -2; i <= 2; i++){
			llint y = x+i;
			y = max(0LL, y), y = min(y, m);
			ans = max(ans, (y+1)*a - b*d*y*(y+1)/2);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}