#include <iostream>
#include <string>

using namespace std;

string s;
int cnt[26];

int main(void)
{
	cin >> s;
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
	
	int kind = 0, kind2 = 0;
	for(int i = 0; i < 26; i++){
		if(cnt[i]){
			kind++;
			if(cnt[i] >= 2) kind2++;
		}
	}
	
	if(kind == 2 && kind2 == 2) cout << "Yes" << endl;
	else if(kind == 3 && kind2 >= 1) cout << "Yes" << endl;
	else if(kind == 4) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}