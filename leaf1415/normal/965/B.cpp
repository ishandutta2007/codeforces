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
typedef long long ll;
typedef pair<llint, llint> P;

ll k, n;
char c[105][105];
int w[105][105], h[105][105];
int a[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(y, 1, n){
		rep(x, 1, n){
			cin >> c[x][y];
		}
	}
	
	rep(y, 1, n){
		int cnt = 0;
		rep(x, 1, n){
			if(c[x][y] == '#') cnt = 0;
			else cnt++;
			w[x][y] = cnt;
		}
	}
	rep(x, 1, n){
		int cnt = 0;
		rep(y, 1, n){
			if(c[x][y] == '#') cnt = 0;
			else cnt++;
			h[x][y] = cnt;
		}
	}
	
	rep(y, 1, n){
		rep(x, 1, n){
			if(w[x][y] >= k){
				rep(i, 0, k-1) a[x-i][y]++;
			}
		}
	}
	rep(x, 1, n){
		rep(y, 1, n){
			if(h[x][y] >= k){
				rep(i, 0, k-1) a[x][y-i]++;
			}
		}
	}
	
	ll ans = -1, ans_x, ans_y;
	rep(y, 1, n){
		rep(x, 1, n){
			if(a[x][y] > ans){
				ans = a[x][y];
				ans_x = x, ans_y = y;
			}
		}
	}
	cout << ans_y << " " << ans_x << endl;
	
	return 0;
}