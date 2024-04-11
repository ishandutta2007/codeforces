#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint Q;
string s, t, p;
int cntr[26], cntp[26];

void cnt(string &s, int cnt[])
{
	for(int i = 0; i < 26; i++) cnt[i] = 0;
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> s >> t >> p;
		
		string r; int nx = 0;
		for(int i = 0; i < t.size(); i++){
			if(nx < s.size() && t[i] == s[nx]) nx++;
			else r += t[i];
		}
		if(nx < s.size()){
			cout << "NO" << endl;
			continue;
		}
		cnt(r, cntr), cnt(p, cntp);
		
		bool flag = true;
		for(int i = 0; i < 26; i++) if(cntr[i] > cntp[i]) flag = false;
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}