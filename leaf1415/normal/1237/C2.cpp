#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> T;

llint n;
map<P, vector<P> > mp;
map<llint, vector<P> >mp2;
vector<P> rem, ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint x, y, z;
	for(int i = 1; i <= n; i++){
		cin >> x >> y >> z;
		mp[make_pair(x, y)].push_back(make_pair(z, i));
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		vector<P> &vec = it->second;
		sort(vec.begin(), vec.end());
		for(int i = 1; i < vec.size(); i+=2){
			ans.push_back(make_pair(vec[i-1].second, vec[i].second));
		}
		if((llint)vec.size() % 2) mp2[it->first.first].push_back(make_pair(it->first.second, vec.back().second));
	}
	for(auto it = mp2.begin(); it != mp2.end(); it++){
		//cout << it->first << " " << it->second.size() << endl;
		vector<P> &vec = it->second;
		sort(vec.begin(), vec.end());
		for(int i = 1; i < vec.size(); i+=2){
			ans.push_back(make_pair(vec[i-1].second, vec[i].second));
		}
		if((llint)vec.size() % 2) rem.push_back(vec.back());
	}
	for(int i = 1; i < rem.size(); i+=2){
		ans.push_back(make_pair(rem[i-1].second, rem[i].second));
	}
	
	for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	flush(cout);

	return 0;
}