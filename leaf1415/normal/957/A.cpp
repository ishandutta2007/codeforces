#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < n; i++){
		if(s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]){
			cout << "No" << endl;
			return 0;
		}
	}
	
	if(s[0] == '?' || s[s.size()-1] == '?'){
		cout << "Yes" << endl;
		return 0;
	}
	for(int i = 1; i < n-1; i++){
		if(s[i] == '?'){
			if(s[i-1] == s[i+1] || s[i-1] == '?' || s[i+1] == '?'){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	
	return 0;
}