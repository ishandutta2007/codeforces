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

llint n, k;
llint a[100005], b[100005];

llint get(llint a, llint x)
{
	llint ub = a+1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(a-3*mid*mid+3*mid-3 >= x) lb = mid;
		else ub = mid;
	}
	return lb;
}

bool check(llint x)
{
	llint ret = 0;
	for(int i = 1; i <= n; i++) ret += get(a[i], x);
	return ret <= k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ub = 1.5e9, lb = -3.5e18, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	
	for(int i = 1; i <= n; i++){
		b[i] = get(a[i], ub);
		k -= b[i];
	}
	for(int i = 1; i <= n; i++){
		llint x = min(k, get(a[i], ub-1)-get(a[i], ub));
		b[i] += x;
		k -= x;
	}
	for(int i = 1; i <= n; i++) cout << b[i] << " "; cout << endl;
	
	
	return 0;
}