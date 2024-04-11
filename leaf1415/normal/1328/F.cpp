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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint a[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) mp[a[i]]++;
	
	llint ans = inf, lsum = 0, lnum = 0, rsum = 0, rnum = n;
	for(int i = 1; i <= n; i++) rsum += a[i];
	for(auto it = mp.begin(); it != mp.end(); it++){
		rsum -= it->first*it->second;
		rnum -= it->second;
		
		llint lcost = lnum * (it->first-1) - lsum, rcost = rsum - (it->first+1) * rnum;
		if(it->second >= k){
			cout << 0 << endl;
			return 0;
		}
		
		//cout << lcost << " " << rcost << endl;
		
		if(lnum + it->second >= k){
			ans = min(ans, lcost + (k-it->second));
		}
		if(rnum + it->second >= k){
			ans = min(ans, rcost + (k-it->second));
		}
		ans = min(ans, lcost + rcost + (k-it->second));
		
		lsum += it->first*it->second;
		lnum += it->second;
	}
	cout << ans << endl;
	
	return 0;
}