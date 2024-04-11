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
llint n, k;
llint a[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		mp.clear();
		for(int i = 1; i <= n; i++){
			llint r = (k - a[i]%k) % k;
			if(r > 0) mp[r]++;
		}
		P p = P(0, 0);
		for(auto it = mp.begin(); it != mp.end(); it++){
			p = max(p, P(it->second, it->first));
		}
		cout << max(0LL, (p.first-1)*k + p.second + 1) << "\n";
	}
	flush(cout);
	
	return 0;
}