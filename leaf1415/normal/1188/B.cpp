#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define llint long long
#define mod 998244353

using namespace std;

llint n, p, k;
llint a[300005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		mp[(a[i]*a[i]%p*a[i]%p*a[i]%p - k*a[i]%p + p)%p]++;
	}
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++) ans += it->second * (it->second-1) / 2;
	cout << ans << endl;
	
	return 0;
}