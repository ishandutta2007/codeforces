#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		string s;cin >> s;
		for(int i = 0;i < s.length();i += 2)
			cout << s[i];
		cout << s[s.length()-1] << endl;
	}
	return 0;
}