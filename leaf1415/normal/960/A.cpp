#include <iostream>
#include <string>

using namespace std;

int cnt[3];
string s;

int main(void)
{
	cin >> s;
	char prev = 'a';
	
	for(int i = 0; i < s.size(); i++){
		cnt[s[i]-'a']++;
		if(prev > s[i]){
			cout << "NO" << endl;
			return 0;
		}
		prev = s[i];
	}
	if(cnt[0] == 0 || cnt[1] == 0){
		cout << "NO" << endl;
		return 0;
	}
	if(cnt[0] == cnt[2] || cnt[1] == cnt[2]){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}