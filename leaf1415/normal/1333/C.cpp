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

llint n;
llint a[200005], s[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	
	llint r = 0, ans = 0, cnt = 0;
	mp[0] = 1;
	for(int l = 0; l <= n-1; l++){
		while(cnt == 0 && r+1 <= n && mp[s[r+1]] == 0){
			r++;
			if(++mp[s[r]] == 2) cnt++;
		}
		ans += r-l;
		mp[s[l]]--;
		if(mp[s[l]] == 1) cnt--;
	}
	cout << ans << endl;
	
	return 0;
}