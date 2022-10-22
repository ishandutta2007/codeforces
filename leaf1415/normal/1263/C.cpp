#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<string, int> P;

llint T;
llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		vector<llint> ans;
		llint x = 1; ans.push_back(n);
		
		while(x <= n){
			llint ub = n+1, lb = x, mid;
			while(ub-lb>1){
				mid=(ub+lb)/2;
				if(ans.back() > n/mid) ub = mid;
				else lb = mid;
			}
			x = ub, ans.push_back(n/x);
		}
		
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	return 0;
}