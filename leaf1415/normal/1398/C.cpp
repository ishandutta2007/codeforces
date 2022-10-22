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
llint n;
llint a[100005], sum[100005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		char c;
		for(int i = 1; i <= n; i++){
			cin >> c;
			a[i] = c - '0' - 1;
			sum[i] = sum[i-1] + a[i];
		}
		
		mp.clear();
		for(int i = 0; i <= n; i++) mp[sum[i]]++;
		
		llint ans = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			ans += it->second * (it->second-1) / 2;
		}
		cout << ans << endl;
	}
	
	return 0;
}