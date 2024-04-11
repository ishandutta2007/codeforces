#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int T;
string s, t;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int q = 0; q < T; q++){
		cin >> t >> s;
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1'){
				p = i;
				break;
			}
		}
		for(int j = p; j < t.size(); j++){
			if(t[j] == '1'){
				cout << j-p << "\n";
				break;
			}
		}
	}
	flush(cout);
	
	return 0;
}