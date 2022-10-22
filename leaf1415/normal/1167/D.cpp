#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	int h = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			if(h%2) cout << 1;
			else cout << 0;
			h++;
		}
		else{
			if(h%2) cout << 0;
			else cout << 1;
			h--;
		}
	}
	
	return 0;
}