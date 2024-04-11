#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		sort(s.begin(), s.end());
		
		for(int i = 0; i < (int)s.size()-1; i++){
			if(s[i] == s[i+1]){
				cout << "No" << endl;
				goto pass;
			}
		}
		if(s[0] + s.size() - 1 == s[s.size()-1]){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
		pass:;
	}
		
	return 0;
}