#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
string s[300005];
vector<llint> vec[600005];
const llint zero = 300002;

int main(void)
{
	cin >> n;
	for(llint i = 0; i < n; i++) cin >> s[i];
	
	for(llint i = 0; i < n; i++){
		llint end = 0, mini = 0;
		for(llint j = 0; j < s[i].size(); j++){
			if(s[i][j] == '(') end++;
			else end--;
			mini = min(mini, end);
		}
		vec[zero + end].push_back(mini);
	}
	for(llint i = 0; i < 600005; i++){
		if(vec[i].size()){
			sort(vec[i].begin(), vec[i].end());
		}
	}
	
	llint ans = 0;
	for(int i = 0; i < 600005; i++){
		for(int j = 0; j < vec[i].size(); j++){
			if(vec[i][j] < 0) continue;
			
			llint end1 = i - zero;
			llint end2 = (i - zero) * -1 + zero;
			ans += vec[end2].end() - lower_bound(vec[end2].begin(), vec[end2].end(), -end1);
		}
	}
	cout << ans << endl;
	
	return 0;
}