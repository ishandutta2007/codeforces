#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<int, int> mp;

int main(void)
{
	cin >> n;
	
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		int mn = 0, h = 0;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '(') h++;
			else h--;
			mn = min(mn, h);
		}
		if(h >= 0 && mn == 0) mp[h]++;
		if(h < 0 && mn == h) mp[h]++;
	}
	
	int ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->first < 0) continue;
		if(it->first == 0) ans += it->second/2;
		if(it->first > 0) ans += min(it->second, mp[it->first*-1]);
	}
	cout << ans << endl;
	
	return 0;
}