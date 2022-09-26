#include<bits/stdc++.h>
using namespace std;

const string alp = "abcdefghijklmnopqrstuvwxyz";
int main() {
	string s;
	cin >> s;
	//if(s.size() < 26) return cout << -1 << endl,0;
	int cur = 0;
	for(int i = 0;i < s.size();++i) {
		if(s[i] <= cur + 'a'){
			s[i] = cur + 'a';
			cur++;
			if(cur == 26) break;
		} 
	}
	if(cur < 26) return cout << -1 << endl,0;
	cout << s << endl;
}