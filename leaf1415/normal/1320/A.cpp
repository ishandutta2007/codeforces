#include <iostream>
#include <utility>
#include <vector>
#include <map>
#define llint long long

using namespace std;

llint n;
llint a[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		mp[a[i]-i] += a[i];
	}
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++) ans = max(ans, it->second);
		cout<< ans << endl;
	
	return 0;
}