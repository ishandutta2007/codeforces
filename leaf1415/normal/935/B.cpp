#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	int x = 0, y = 0;
	int prev = 0, ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'U') y++;
		else x++;
		if(x > y){
			if(prev == -1) ans++;
			prev = 1;
		}
		if(x < y){
			if(prev == 1) ans++;
			prev = -1;
		}
	}
	cout << ans << endl;
	return 0;
}