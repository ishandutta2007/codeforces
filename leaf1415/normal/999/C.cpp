#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string s;
int cnt[26];

int main(void)
{
	cin >> n >> k;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		cnt[s[i]-'a']++;
	}
	
	for(int i = 0; i < 26; i++){
		if(k >= cnt[i]){
			k -= cnt[i];
			cnt[i] = 0;
		}
		else{
			cnt[i] -= k;
			break;
		}
	}
	reverse(s.begin(), s.end());
	
	string ans;
	for(int i = 0; i < s.size(); i++){
		if(cnt[s[i]-'a']){
			ans += s[i];
			cnt[s[i]-'a']--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}