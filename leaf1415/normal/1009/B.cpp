#include <iostream>
#include <string>

using namespace std;

string s;

int main(void)
{
	cin >> s;
	
	string t;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1') cnt++;
		else t += s[i];
	}
	
	string ans;
	for(int i = 0; i <= t.size(); i++){
		if(i == t.size() || t[i] == '2'){
			ans += t.substr(0, i);
			for(int j = 0; j < cnt; j++) ans += "1";
			ans += t.substr(i);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}