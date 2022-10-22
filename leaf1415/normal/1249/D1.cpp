#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint l[200005], r[200005];
vector<pair<P, llint> > vec;
set<P> S;
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		vec.push_back(make_pair(make_pair(l[i], 0LL), i));
		vec.push_back(make_pair(make_pair(r[i], 1LL), i));
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++){
		int id = vec[i].second;
		if(vec[i].first.second == 0){
			S.insert(make_pair(r[id], id));
			if(S.size() > k){
				auto it = S.end();
				it--;
				ans.push_back(it->second);
				S.erase(it);
			}
		}
		else{
			S.erase(make_pair(r[id], id));
		}
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}