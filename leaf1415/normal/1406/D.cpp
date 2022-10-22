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

llint n, Q;
llint a[100005], d[100005];

llint calc(llint d)
{
	if(a[n]+d >= 0) return (a[n]+d+1)/2;
	return -(abs(a[n]+d)/2);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0;
	for(int i = 1; i <= n-1; i++) d[i] = a[i] - a[i+1];
	for(int i = 1; i <= n-1; i++) sum += max(0LL, d[i]);
	cout << calc(sum) << "\n";
	
	cin >> Q;
	llint l, r, x;
	for(int i = 1; i <= Q; i++){
		cin >> l >> r >> x;
		
		if(r == n) a[n] += x;
		
		if(l-1 >= 1) sum -= max(0LL, d[l-1]);
		if(r < n) sum -= max(0LL, d[r]);
		
		d[l-1] -= x, d[r] += x;
		
		if(l-1 >= 1) sum += max(0LL, d[l-1]);
		if(r < n) sum += max(0LL, d[r]);
		
		cout << calc(sum) << "\n";
	}
	flush(cout);
	
	return 0;
}