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
#define inf 3e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint T;
llint x, y;
llint c[6];

llint calc()
{
	llint ret = inf;
	if(x >= 0 && y >= 0){
		llint X = x, Y = y, M = 0;
		if(c[1]+c[5] > c[0]){
			M = min(X, Y);
			X -= M, Y -= M;
		}
		ret = min(ret, M*c[0]+X*c[1]+Y*c[5]);
	}
	if(x >= 0 && y <= x){
		llint U = 0, D = 0, R = 0;
		if(y > 0) U = y, R = x-y;
		else U = 0, R = x, D = -y;
		if(c[2]+c[0] < c[1]) D += R, U += R, R = 0;
		ret = min(ret, U*c[0]+R*c[1]+D*c[2]);
	}
	if(y >= 0 && x <= y){
		llint U = 0, D = 0, R = 0;
		if(x > 0) U = x, R = y-x;
		else U = 0, R = y, D = -x;
		if(c[4]+c[0] < c[5]) D += R, U += R, R = 0;
		ret = min(ret, U*c[0]+R*c[5]+D*c[4]);
	}
	
	if(x <= 0 && y <= 0) ret = min(ret, -x*c[4]-y*c[2]);
	if(x >= 0 && y <= x) ret = min(ret, x*c[0]+(x-y)*c[2]);
	if(y >= 0 && y >= x) ret = min(ret, y*c[0]+(y-x)*c[4]);
	
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> y >> x;
		for(int i = 0; i < 6; i++) cin >> c[i];
		
		llint ans = calc();
		x *= -1, y *= -1;
		for(int i = 0; i < 3; i++) swap(c[i], c[i+3]);
		ans = min(ans, calc());
		
		cout << ans << endl;
	}
	
	return 0;
}