#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	vector<llint> vec;
	llint cnt = 0; char c = '^';
	for(int i = 0; i < n; i++){
		if(s[i] == c) cnt++;
		else{
			vec.push_back(cnt);
			cnt = 1;
		}
		c = s[i];
	}
	vec.push_back(cnt);
	vec.erase(vec.begin());
	//for(int i = 0; i < vec.size(); i++) cout<< vec[i] << " "; cout << endl;
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		if(i+1 < vec.size()) ans += vec[i+1];
		if(i > 0) ans += vec[i-1];
	}
	ans += n;
	ans -= vec.size()-1;
	
	ans = n*(n+1)/2 - ans;
	cout << ans << endl;
	
	return 0;
}