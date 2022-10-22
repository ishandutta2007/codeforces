#include <iostream>
#include <map>
#define llint long long 

using namespace std;

llint n, m;
map<llint, llint> mp;

int main(void)
{
	cin >> n;
	llint a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(mp.count(a)) mp[a] = max(mp[a], b);
		else mp[a] = b;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(mp.count(a)) mp[a] = max(mp[a], b);
		else mp[a] = b;
	}
	
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans += it->second;
	}
	cout << ans << endl;
	
	return 0;
}