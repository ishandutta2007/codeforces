#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint Q;
llint b, w;
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> b >> w;
		bool flag = false;
		if(w > b) swap(b, w), flag = true;
		if(b-w > 2*w+1){
			cout << "NO" << "\n";
			continue;
		}
		ans.clear();
		for(int i = 1; i <= w; i++){
			ans.push_back(make_pair(2, 2*i));
			ans.push_back(make_pair(2, 2*i-1));
		}
		llint rem = b-w;
		if(rem){
			ans.push_back(make_pair(2, 2*w+1));
			rem--;
		}
		for(int i = 1; i <= w; i++){
			if(rem){
				ans.push_back(make_pair(1, 2*i));
				rem--;
			}
			if(rem){
				ans.push_back(make_pair(3, 2*i));
				rem--;
			}
		}
		cout << "YES" << "\n";
		for(int i = 0; i < ans.size(); i++){
			if(flag) ans[i].first++;
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
	flush(cout);
	
	return 0;
}