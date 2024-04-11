#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m;
set<string> S;
vector<string> svec, pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		S.insert(s);
	}
	
	for(auto it = S.begin(); it != S.end(); it++){
		string t = *it;
		reverse(t.begin(), t.end());
		if(*it == t){
			svec.push_back(*it);
			continue;
		}
		if(*it < t && S.count(t)) pvec.push_back(*it);
	}
	
	string ans;
	for(int i = 0; i < pvec.size(); i++) ans += pvec[i];
	if(svec.size()) ans += svec.front();
	
	reverse(pvec.begin(), pvec.end());
	for(int i = 0; i < pvec.size(); i++){
		string t = pvec[i];
		reverse(t.begin(), t.end());
		ans += t;
	}
	
	cout << ans.size() << endl;
	cout << ans << endl;
	
	return 0;
}