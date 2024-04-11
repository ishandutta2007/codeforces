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
llint h, w;
char c[1005][1005];
llint p, q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w >> p >> q;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> c[x][y];
			}
		}
		
		llint ans = 0;
		for(int y = 1; y <= h; y++){
			llint a = 0, b = 0, cnt = 0;
			for(int x = 1; x <= w; x++){
				if(c[x][y] == '.') cnt++;
				else{
					a += cnt/2, b += cnt%2;
					cnt = 0;
				}
			}
			a += cnt/2, b += cnt%2;
			ans += min(a*q+b*p, (a*2+b)*p);
		}
		cout << ans << endl;
	}
	
	return 0;
}