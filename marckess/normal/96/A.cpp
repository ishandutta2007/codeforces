#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	if ( s.find("1111111") != string::npos || 
		 s.find("0000000") != string::npos )
		cout << "YES";
	else
		cout << "NO";
	return 0;
}