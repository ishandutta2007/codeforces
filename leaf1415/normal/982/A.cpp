#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	s = "0" + s + "0";
	
	for(int i = 1; i < s.size()-1; i++){
		if(s[i] == '0'){
			if(s[i-1] == '0' && s[i+1] == '0'){
				cout << "No" << endl;
				return 0;
			}
		}
		else{
			if(s[i-1] == '1' || s[i+1] == '1'){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}