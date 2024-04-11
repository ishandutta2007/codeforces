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
llint n, l;
llint a[100005], b[100005];

bool check(double x)
{
	double t = 0;
	for(int i = 1; i <= n+1; i++){
		if(x <= a[i]){
			t += (double)(x - a[i-1]) / i;
			break;
		}
		t += (double)(a[i]-a[i-1]) / i;
	}
	
	x = l - x;
	for(int i = 1; i <= n+1; i++){
		if(x <= b[i]){
			t -= (double)(x - b[i-1]) / i;
			break;
		}
		t -= (double)(b[i]-b[i-1]) / i;
	}
	
	return t >= 0;
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> l;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			b[i] = l - a[i];
		}
		a[n+1] = b[n+1] = l;
		reverse(b+1, b+n+1);
		
		double ub = l, lb = 0, mid;
		for(int i = 0; i < 100; i++){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		
		double ans = 0;
		for(int i = 1; i <= n+1; i++){
			if(ub <= a[i]){
				ans += (double)(ub - a[i-1]) / i;
				break;
			}
			ans += (double)(a[i]-a[i-1]) / i;
		}
		printf("%.11f\n", ans);
	}
	
	return 0;
}