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

llint n, x;
llint d[200005], dsum[200005], fsum[200005];

llint get(llint l, llint r, llint sum[])
{
	llint ret = sum[r];
	if(l > 0) ret -= sum[l-1];
	return ret;
}

llint getsum(llint s, llint len, llint sum[])
{
	llint ret = 0;
	ret += len/n*sum[n-1], len %= n;
	
	llint l = s, r = s+len-1;
	if(r < n) return ret + get(l, r, sum);
	ret += get(l, n-1, sum);
	ret += get(0, r%n, sum);
	return ret;
}

llint calc(llint x)
{
	return x*(x+1)/2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> d[i];
	reverse(d, d+n);
	
	dsum[0] = d[0], fsum[0] = calc(d[0]);
	for(int i = 1; i < n; i++) dsum[i] = dsum[i-1] + d[i];
	for(int i = 1; i < n; i++) fsum[i] = fsum[i-1] + calc(d[i]);
	
	llint ans = 0;
	for(int i = 0; i < n; i++){
		llint ub = x+5, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(getsum(i, mid, dsum) <= x) lb = mid;
			else ub = mid;
		}
		llint tmp = getsum(i, lb, fsum), rem = x - getsum(i, lb, dsum);
		tmp += calc(d[(i+lb)%n]) - calc(d[(i+lb)%n]-rem);
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	
	return 0;
}