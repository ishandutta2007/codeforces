#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<bool> v(27,false);
	string s;
	cin >> s;
	int c=0;
	for(int i = 0; i< s.size(); i++){
		if (v[s[i]-'a'] == false){
			c++;
			v[s[i]-'a'] = true;
		}
	}

	if ( c % 2 == 0 )
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";

	return 0;
}