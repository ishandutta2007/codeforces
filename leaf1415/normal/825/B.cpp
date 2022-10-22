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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll h = 10, w = 10;
char c[15][15];

bool check()
{
	rep(y, 1, h){
		ll cnt = 0;
		rep(x, 1, w){
			if(c[x][y] == 'X') cnt++;
			else cnt = 0;
			if(cnt >= 5) return true;
		}
	}
	rep(x, 1, w){
		ll cnt = 0;
		rep(y, 1, h){
			if(c[x][y] == 'X') cnt++;
			else cnt = 0;
			if(cnt >= 5) return true;
		}
	}
	rep(y, -2*h, 2*h){
		ll cnt = 0;
		rep(x, 1, w){
			if(x <= 0 || x > w || y+x <= 0 || y+x > h) continue;
			if(c[x][y+x] == 'X') cnt++;
			else cnt = 0;
			if(cnt >= 5) return true;
		}
	}
	rep(y, -2*h, 2*h){
		ll cnt = 0;
		rep(x, 1, w){
			if(x <= 0 || x > w || y-x <= 0 || y-x > h) continue;
			if(c[x][y-x] == 'X') cnt++;
			else cnt = 0;
			if(cnt >= 5) return true;
		}
	}
	
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(y, 1, h) rep(x, 1, w) cin >> c[x][y];
	
	rep(y, 1, h) rep(x, 1, w){
		if(c[x][y] != '.') continue;
		c[x][y] = 'X';
		if(check()){
			cout << "YES" << endl;
			return 0;
		}
		c[x][y] = '.';
	}
	cout << "NO" << endl;
	
	return 0;
}