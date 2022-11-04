#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	bool f = false;
	for(int i=0; i< s.size(); i++){
		char c = s[i];
		if(c=='H' || c=='Q' || c=='9')
			f = true;
	}
	if (f)
		cout << "YES";
	else
		cout << "NO";
}