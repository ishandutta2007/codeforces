#include <iostream>
#include <string>
#define llint long long

using namespace std;

string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	char c = '~';
	for(int i = 0; i < s.size(); i++){
		if(c < s[i]) cout << "Ann" << "\n";
		else cout << "Mike" << "\n";
		c = min(c, s[i]);
	}
	flush(cout);
	
	return 0;
}