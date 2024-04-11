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
char c[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> c[x][y];
			}
		}
		llint ans = 0;
		for(int i = 1; i <= w; i++){
			if(c[i][h] == 'D') ans++;
		}
		for(int i = 1; i <= h; i++){
			if(c[w][i] == 'R') ans++;
		}
		cout << ans << endl;
	}
	return 0;
}