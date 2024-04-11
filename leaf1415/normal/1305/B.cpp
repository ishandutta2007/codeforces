#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

string s;
vector<llint> lvec, rvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	llint n = s.size();
	s = "#" + s;
	for(int i = 1; i <= n; i++){
		if(s[i] == '(') lvec.push_back(i);
		else rvec.push_back(i);
	}
	
	reverse(rvec.begin(), rvec.end());
	
	llint x = 0;
	for(int i = 0; i < min((int)lvec.size(), (int)rvec.size()); i++){
		if(lvec[i] < rvec[i]) x++;
		else break;
	}
	
	vector<llint> ans;
	for(int i = 0; i < x; i++) ans.push_back(rvec[i]), ans.push_back(lvec[i]);
	sort(ans.begin(), ans.end());
	
	if(ans.size() == 0) cout << 0 << endl;
	else{
		cout << 1 << endl;
		cout << ans.size() << endl;
		for(int i = 0 ;i < ans.size(); i++) cout<< ans[i] << " "; cout<< endl;
	}

	return 0;
}