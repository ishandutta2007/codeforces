#include <iostream>
#include <string>

using namespace std;

string s;
string c = "aiueo13579";

int main(void)
{
	cin >> s;
	
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < c.size(); j++){
			if(s[i] == c[j]){
				ans++;
				goto next;
			}
		}
		next:;
	}
	
	cout << ans << endl;
	return 0;
}