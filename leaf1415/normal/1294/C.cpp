#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T, n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		vector<llint> ans;
		for(int i = 2; i*i <= n; i++){
			if(n % i == 0){
				ans.push_back(i);
				n /= i;
			}
			if(ans.size() >= 2) break;
		}
		if(n > 1) ans.push_back(n);
		if(ans.size() < 3) cout << "NO" << endl;
		else{
			if(ans[0] == ans[2] || ans[1] == ans[2]){
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
			for(int i = 0; i < 3; i++) cout << ans[i] << " "; cout << endl;
		}
	}
	flush(cout);
	
	return 0;
}