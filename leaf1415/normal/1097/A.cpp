#include <iostream>
#include <string>

using namespace std;

string s, t[5];

int main(void)
{
	cin >> s;
	for(int i = 0; i < 5; i++){
		cin >> t[i];
	}
	
	for(int i = 0; i < 5; i++){
		if(s[0] == t[i][0] || s[1] == t[i][1]){
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	return 0;
}