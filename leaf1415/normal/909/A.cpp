#include <iostream>
#include <string>

using namespace std;

string s, t;

int main(void)
{
	cin >> s >> t;
	
	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= t.size(); j++){
			ans = min(ans, s.substr(0, i) + t.substr(0, j));
		}
	}
	cout << ans << endl;
	return 0;
}