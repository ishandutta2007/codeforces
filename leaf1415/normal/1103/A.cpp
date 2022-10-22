#include <iostream>
#include <string>

using namespace std;

string s;
int vnum, hnum;

int main(void)
{
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0'){
			cout << 1 << " " << ++vnum << endl;
			if(vnum == 4) vnum = 0;
		}
		else{
			if(hnum == 0) cout << 3 << " " << 1 << endl, hnum++;
			else cout << 3 << " " << 3 << endl, hnum = 0;
		}
	}
	
	return 0;
}