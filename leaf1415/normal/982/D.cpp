#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define llint long long

using namespace std;

llint n;
llint a[100005];
llint pos[100005];
set<llint> s;
map<llint, llint> mp;

vector<llint> comp;

int main(void)
{
	cin >> n;
	for(llint i = 0; i < n; i++) cin >> a[i];
	
	for(llint i = 0; i < n; i++) comp.push_back(a[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(llint i = 0; i < n; i++){
		a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
	}
	for(llint i = 0; i < n; i++) pos[a[i]] = i;
	
	comp.push_back(comp.back()+1);
	llint ans = n, ans_n = 0;
	mp[n] = 1;
	s.insert(-1), s.insert(n);
	for(llint i = n-1; i >= 0; i--){
		auto p = s.upper_bound(pos[i]);
		auto q = p; q--;
		llint range = *p - *q - 1;
		mp[range]--;
		if(mp[range] == 0) mp.erase(range);
		mp[pos[i] - *q - 1]++;
		mp[*p - pos[i] - 1]++;
		if(mp.count(0)) mp.erase(0);
		s.insert(pos[i]);
		
		if(mp.size() > 0){
			auto e = mp.end(); e--;
			//for(auto it = mp.begin(); it != mp.end(); it++) cout << it->first << " "; cout << endl;
			if(mp.begin()->first == e->first){
				if(mp.begin()->second >= ans_n){
					ans = i;
					ans_n = mp.begin()->second;
				}
			}
		}
	}
	if(ans == 0) cout << 1 << endl;
	else cout << comp[ans-1]+1 << endl;
	
	return 0;
}