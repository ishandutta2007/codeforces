#include <iostream>
#include <map>
#define llint long long

using namespace std;

llint n;
map<llint, llint> mp;

int main(void)
{
	cin >> n;
	llint a;
	for(int i = 0; i < n; i++){
		cin >> a;
		mp[a]++;
	}
	
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		bool flag = false;
		for(int i = 0; i < 40; i++){
			llint x = (1LL<<i) - it->first;
			if(x <= 0) continue;
			if(x == it->first && it->second == 1) continue;
			if(mp[x] > 0){
				flag = true;
				break;
			}
		}
		if(!flag) ans += it->second;
	}
	cout << ans << endl;
	return 0;
}