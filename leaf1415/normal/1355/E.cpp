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

llint n, a, r, m;
llint h[100005], sum[1000005];

llint calc(llint x)
{
	llint p = upper_bound(h, h+n+1, x) - h;
	llint d = sum[n]-sum[p-1] - (n-p+1)*x;
	llint s = (p-1)*x - sum[p-1];
	
	//cout << x << " " << d << " " << s << endl;
	
	llint ret = min(d, s) * m;
	if(d >= s) ret += (d-s)*r;
	else ret += (s-d)*a;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> a >> r >> m;
	m = min(m, a+r);
	
	for(int i = 1; i <= n; i++) cin >> h[i];
	sort(h+1, h+n+1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + h[i];
	
	//for(int i = 0; i <= 10; i++) cout << calc(i) << endl;
	
	llint ub = 1e9+7, lb = 0, mid1, mid2;
	while(ub-lb > 5){
		//cout << lb << " " << ub << endl;
		mid1 = (ub+2*lb)/3, mid2 = (2*ub+lb)/3;
		if(calc(mid1) <= calc(mid2)) ub = mid2;
		else lb = mid1;
	}
	llint ans = inf;
	for(int i = lb; i <= ub; i++) ans = min(ans, calc(i));
	cout << ans << endl;
	
	return 0;
}