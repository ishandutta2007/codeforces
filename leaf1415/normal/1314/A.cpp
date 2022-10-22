#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint a[200005];
llint t[200005];
map<llint, vector<llint> > mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		mp[a[i]].push_back(t[i]);
	}
	mp[(llint)inf];
	
	llint sum = 0, pre = mp.begin()->first;
	priority_queue<llint> Q;
	for(auto it = mp.begin(); it != mp.end(); it++){
		//cout << it->first << " " << Q.size() << " " << sum << endl;
		
		llint rem = it->first - pre;
		while(rem > 0 && Q.size()){
			sum -= Q.top();
			Q.pop();
			rem--;
			ans += sum;
		}
		pre = it->first;
		
		vector<llint> &vec = it->second;
		for(int i = 0; i < vec.size(); i++){
			Q.push(vec[i]);
			sum += vec[i];
		}
	}
	cout << ans << endl;
	
	return 0;
}