#include <iostream>
#include <string>
#define llint long long

using namespace std;

string s;
llint c[26], c2[26][26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	if(s.size() == 1){
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 0; i < s.size(); i++){
		llint x = s[i]-'a';
		for(int j = 0; j < 26; j++){
			c2[j][x] += c[j];
		}
		c[x]++;
	}
	
	llint ans = 0;
	for(int i = 0; i < 26; i++){
		ans = max(ans, c[i]);
		for(int j = 0; j < 26; j++){
			ans = max(ans, c2[i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}