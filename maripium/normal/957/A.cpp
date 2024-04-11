#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1;i < s.size();++i) {
		if(s[i] == s[i - 1] && s[i] != '?') return cout << "NO" << endl,0;
		//else if(s[i] == s[i - 1] && s[i] == '?') return cout << "YES" << endl,0;
	}
	for(int i = 1;i < s.size();++i) {
		if(s[i] == s[i - 1] && s[i] == '?') return cout << "YES" << endl,0;
	}
	if(s[0] == '?' || s[s.size() - 1] == '?') return cout << "YES" << endl,0;
	for(int i = 1;i < s.size() - 1;++i) {
		if(s[i] == '?' && s[i - 1] == s[i + 1]) return cout << "YES" << endl,0;
	}
 	cout << "NO" << endl;
}