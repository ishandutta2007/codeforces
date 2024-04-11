#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
string s, t;
vector<llint> vec, vec2;
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s >> t;
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'a' && t[i] == 'b') vec.push_back(i);
		if(s[i] == 'b' && t[i] == 'a') vec2.push_back(i);
	}
	
	if(((int)vec.size() + (int)vec2.size())%2 != 0){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0; i < (int)vec.size()/2*2; i+=2){
		ans.push_back(make_pair(vec[i], vec[i+1]));
	}
	for(int i = 0; i < (int)vec2.size()/2*2; i+=2){
		ans.push_back(make_pair(vec2[i], vec2[i+1]));
	}
	if((int)vec.size()%2){
		ans.push_back(make_pair(vec.back(), vec.back()));
		ans.push_back(make_pair(vec.back(), vec2.back()));
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
	
	return 0;
}