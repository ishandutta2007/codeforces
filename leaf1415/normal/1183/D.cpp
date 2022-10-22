#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint n;
map<llint, llint> mp;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		
		llint a;
		mp.clear();
		for(int i = 0; i < n; i++){
			cin >> a;
			mp[a]++;
		}
		vec.clear();
		for(auto it = mp.begin(); it != mp.end(); it++){
			vec.push_back(it->second);
		}
		sort(vec.rbegin(), vec.rend());
		
		llint ans = 0, pre = 1e9;
		for(int i = 0; i < vec.size(); i++){
			pre = min(vec[i], pre-1);
			if(pre > 0) ans += pre;
		}
		cout << ans << endl;
	}
	return 0;
}