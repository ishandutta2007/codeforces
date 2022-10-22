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
llint c, h, g;

double calc(llint x)
{
	double ret = (double)((x+1)*h + x*c) / (double)(2*x+1);
	return fabs(g - ret);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> c >> g;
		if(h == g){
			cout << 1 << endl;
			continue;
		}
		if(2*g <= h+c){
			cout << 2 << endl;
			continue;
		}
		
		llint ub = 1e9, lb = 0, mid1, mid2;
		while(ub-lb>5){
			mid1 = (2*lb+ub)/3, mid2 = (lb+2*ub)/3;
			double res = calc(mid1), res2 = calc(mid2);
			if(res < res2) ub = mid2;
			else lb = mid1;
		}
		
		llint ans = 0; double ans_val = inf;
		for(int i = lb; i <= ub; i++){
			if(ans_val > calc(i)){
				ans = i;
				ans_val = calc(i);
			}
		}
		cout << ans*2+1 << "\n";
	}
	flush(cout);
	
	return 0;
}