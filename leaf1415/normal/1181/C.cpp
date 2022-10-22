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

llint h, w;
char c[1005][1005];
int sum[26][1005][1005];

llint getsum(int sx, int sy, int tx, int ty, int c)
{
	if(sx > tx || sy > ty) return 0;
	return sum[c][tx][ty] - sum[c][sx-1][ty] - sum[c][tx][sy-1] + sum[c][sx-1][sy-1];
}

llint getlen(llint l, llint r, llint x, llint c)
{
	llint ub = w-x+2, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(getsum(x, l, x+mid-1, r, c) == mid*(r-l+1)) lb = mid;
		else ub = mid;
	}
	return lb;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c[x][y];
		}
	}
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			for(int i = 0; i < 26; i++){
				sum[i][x][y] = sum[i][x-1][y] + sum[i][x][y-1] - sum[i][x-1][y-1];
			}
			sum[c[x][y]-'a'][x][y]++;
		}
	}
	
	llint ans = 0;
	for(int x = 1; x <= w; x++){
		llint cnt = 1;
		for(int y = 1; y <= h; y++){
			if(c[x][y] == c[x][y-1]){
				cnt++;
				continue;
			}
			if(y-2*cnt <= 0 || y+cnt-1 > h){
				cnt = 1;
				continue;
			}
			
			llint len = inf;
			len = min(len, getlen(y-cnt, y-1, x, c[x][y-cnt]-'a'));
			len = min(len, getlen(y-2*cnt, y-cnt-1, x, c[x][y-2*cnt]-'a'));
			len = min(len, getlen(y, y+cnt-1, x, c[x][y]-'a'));
			ans += len;
			cnt = 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}