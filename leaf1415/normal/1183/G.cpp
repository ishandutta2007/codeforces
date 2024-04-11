#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
map<llint, llint> mp, mp1;
vector<P> vec;
vector<llint> vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int q = 0; q < T; q++){
		cin >> n;
		
		llint a, f;
		mp.clear(), mp1.clear();
		for(int i = 0; i < n; i++){
			cin >> a >> f;
			mp[a]++;
			if(f == 1) mp1[a]++;
		}
		vec.clear();
		for(auto it = mp.begin(); it != mp.end(); it++){
			vec.push_back(make_pair(it->second, mp1[it->first]));
		}
		sort(vec.rbegin(), vec.rend());
		
		vec2.clear();
		llint ans = 0, pre = 1e9;
		for(int i = 0; i < vec.size(); i++){
			pre = min(vec[i].first, pre-1);
			if(pre > 0) ans += pre, vec2.push_back(pre);
		}
		
	priority_queue<llint> Q;
		llint ans1 = 0, p = 0;
		for(int i = 0; i < vec2.size(); i++){
			while(p < vec.size() && vec[p].first >= vec2[i]){
				Q.push(vec[p].second);
				p++;
			}
			ans1 += min(vec2[i], Q.top());
			Q.pop();
		}
		cout << ans << " " << ans1 << "\n";
	}
	flush(cout);
	
	return 0;
}