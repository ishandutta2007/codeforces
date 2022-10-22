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
llint n, k;

llint getsum(llint b, llint n)
{
	llint ret = 0;
	if(n >= 0){
		for(int i = 0; i < n; i++) ret += b + i;
	}
	else{
		for(int i = 0; i < -n; i++) ret += b - i;
	}
	return ret;
}

llint get(llint s, llint d, llint c = -1)
{
	llint ret = 0, mul = 1;
	if(c != -1){
		llint x = min(c, s);
		ret += x;
		s -= x;
		mul = 10;
	}
	for(int i = 0; i < d; i++){
		if(s == 0) return ret;
		llint x = min(9LL, s);
		ret += mul * x;
		s -= x;
		mul *= 10;
	}
	
	bool flag = false;
	while(s){
		llint x = min(9LL, s);
		if(!flag){
			flag = true;
			x = min(x, 8LL);
		}
		ret += mul * x;
		s -= x;
		mul *= 10;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		
		llint ans = inf;
		for(int i = 0; i <= n; i++){
			if(getsum(i, k+1) != n) continue;
			for(int j = 0; j < 10; j++){
				llint res = get(i, inf, j);
				if(res%10 + k >= 10) continue;
				ans = min(ans, res);
			}
		}
		
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				if(j-i < 0) continue;
				llint sum = getsum(j, -i);
				for(int l = 1; j-9*l+1 >= 1; l++){
					if(sum + getsum(j-9*l+1, (k+1)-i) != n) continue;
					llint res = get(j, l);
					ans = min(ans, res-(i-1));
				}
			}
		}
		if(ans > inf/2) ans = -1;
		cout << ans << endl;
	}
	
	return 0;
}