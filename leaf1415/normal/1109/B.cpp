#include <iostream>
#include <string>

using namespace std;

string s;

bool check(string s)
{
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] != s[n-i-1]) return false;
	}
	return true;
}

int main(void)
{
	cin >> s;
	
	int m = s.size()/2;
	bool same = true;
	for(int i = 0; i < m; i++){
		if(s[i] != s[0]) same = false;
	}
	if(same){
		cout << "Impossible" << endl;
		return 0;
	}
	
	int ans = 2;
	
	for(int i = 1; i < s.size(); i++){
		string t = s.substr(i) + s.substr(0, i);
		if(check(t) && s != t) ans = 1;
	}
	cout << ans << endl;
	
	return 0;
}