#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#define llint long long

using namespace std;

llint T;
llint n, x;
string s;
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		cin >> s;
		
		mp.clear();
		llint h = 0;
		for(int i = 0; i < n; i++){
			mp[h]++;
			if(s[i] == '0') h++;
			else h--;
		}
		if(h == 0){
			if(mp[x]) cout << -1 << endl;
			else cout << 0 << endl;
			continue;
		}
		
		llint ans = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			llint a = it->first;
			if((x-a > 0 && h < 0) || (x-a < 0 && h > 0)) continue;
			if((x-a) % abs(h)) continue;
			ans += it->second;
		}
		cout << ans << endl;
	}
	
	return 0;
}