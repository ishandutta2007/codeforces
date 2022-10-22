#include <iostream>
#include <string>

using namespace std;

string s;

int main(void)
{
	cin >> s;
	int cntp = 0, cntl = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'o') cntp++;
		else cntl++;
	}
	if(cntp == 0){
		cout << "YES" << endl;
	}
	else if(cntl % cntp == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}