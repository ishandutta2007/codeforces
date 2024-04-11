#include <iostream>
#include <string>

using namespace std;

int T;
int n;
string s;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		
		int l = 0, r = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '<') l++;
			else break;
		}
		for(int i = (int)s.size()-1; i >= 0; i--){
			if(s[i] == '>') r++;
			else break;
		}
		cout << min(l, r) << endl;
	}
	return 0;
}