#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#define llint long long
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n, x, y;
P p[100005];
map<llint, llint> mp;

int main(void)
{
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++){
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p+n);
	
	llint ans = 0;
	for(int i = 0; i < n; i++){
		llint l = p[i].first, r = p[i].second;
		auto it = mp.lower_bound(l);
		if(mp.size() == 0 || it == mp.begin()) ans += x, ans %= mod;
		else{
			it--;
			if((l - it->first) * y >= x) ans += x, ans %= mod;
			else{
				ans += (l - it->first) * y % mod, ans %= mod;
				it->second--;
				if(it->second <= 0) mp.erase(it);
			}
		}
		mp[r]++;
		ans += (r - l) * y % mod, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}