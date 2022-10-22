#include <iostream>
#include <string>

using namespace std;

string s;

int main(void)
{
	cin >> s;
	
	int ans = (s.size()+1)/2;
	bool flag = false;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == '1') flag = true;
	}
	if(s.size() % 2 && !flag) ans--;
	cout << ans << endl;
	
	return 0;
}