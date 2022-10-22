#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

bool check(int l, int r)
{
	string t = s.substr(l, r-l+1);
	string u = t;
	reverse(u.begin(), u.end());
	return t == u;
}

int main(void)
{
	cin >> s;
	
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(i > j) continue;
			if(!check(i, j)) ans = max(ans, j-i+1);
		}
	}
	cout << ans << endl;
	
	return 0;
}