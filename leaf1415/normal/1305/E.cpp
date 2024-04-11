#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint n, m;
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		if(m <= 0) break;
		llint x = (i-1)/2;
		if(m >= x){
			ans.push_back(i);
			m -= x;
		}
		else{
			ans.push_back(i-1+(i-1-2*m));
			m = 0;
			break;
		}
	}
	
	if(m > 0){
		cout << -1 << endl;
		return 0;
	}
	llint rem = n - (int)ans.size();
	for(int i = 1; i <= rem; i++){
		ans.push_back(i * 100000 + 1);
	}
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;

	return 0;
}