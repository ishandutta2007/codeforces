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
		
		int pos = -1;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '8'){
				pos = i;
				break;
			}
		}
		if(pos == -1 || s.size()-pos < 11) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
		
	return 0;
}