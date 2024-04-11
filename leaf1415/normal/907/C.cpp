#include <iostream>
#include <string>

using namespace std;

int N;
char c;
string s;
bool elim[26], tmp[26], unique;

int main(void)
{
	cin >> N;
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		cin >> c;
		cin >> s;
		
		if(c == '.'){
			for(int j = 0; j < s.size(); j++) elim[s[j] - 'a'] = true;
		}
		else if(c == '!'){
			if(unique) ans++;
			else{
				int cnt = 0;
				for(int j = 0; j < 26; j++) if(elim[j]) cnt++;
				if(cnt == 25){
					unique = true;
					ans++;
				}
			}
			for(int j = 0; j < 26; j++) tmp[j] = false;
			for(int j = 0; j < s.size(); j++) tmp[s[j] - 'a'] = true;
			for(int j = 0; j < 26; j++) if(!tmp[j]) elim[j] = true;
		}
		else if(c == '?'){
			if(unique) ans++;
			else{
				int cnt = 0;
				for(int j = 0; j < 26; j++) if(elim[j]) cnt++;
				if(cnt == 25){
					unique = true;
					ans++;
				}
			}
			elim[s[0] - 'a'] = true;
		}
	}
	if(unique) ans--;
	
	cout << ans << endl;
	return 0;
}