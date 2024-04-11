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
llint a[35][35];
llint cnt[105][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> a[x][y];
			}
		}
		for(int i = 1; i <= 100; i++) cnt[i][0] = cnt[i][1] = 0;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cnt[x+y][a[x][y]]++;
			}
		}
		llint len = h+w-1;
		for(int i = 1; i <= len/2; i++){
			cnt[i+1][0] += cnt[len+1-i+1][0];
			cnt[i+1][1] += cnt[len+1-i+1][1];
		}
		
		llint ans = 0;
		for(int i = 1; i <= len/2; i++){
			ans += min(cnt[i+1][0], cnt[i+1][1]);
		}
		cout << ans << endl;
	}
	
	return 0;
}