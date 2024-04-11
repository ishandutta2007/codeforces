#include <iostream>
#include <map>
#define llint long long

using namespace std;

llint n;
llint a[7005], b[7005];
map<llint, llint> mp, mp2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		mp[a[i]] += b[i], mp2[a[i]]++;
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(mp2[it->first] < 2) continue;
		llint x = it->first;
		for(int j = 1; j <= n; j++){
			if((x | a[j]) == x && x > a[j]) mp2[a[j]] = 2;
		}
	}
	/*for(auto it = mp.begin(); it != mp.end(); it++){
		cout << it->first << " " << it->second << endl;
	}*/
	
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(mp2[it->first] >= 2) ans += it->second;
	}
	cout << ans << endl;
	
	return 0;
}