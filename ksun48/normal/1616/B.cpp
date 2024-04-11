#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n == 1){
		cout << s << s << '\n';
		return;
	}
	if(s[0] <= s[1]){
		cout << s[0] << s[0] << '\n';
		return;
	}
	int i = 0;
	while(i + 1 < s.size() && s[i+1] <= s[i]) i++;
	string g = s.substr(0, i+1);
	cout << g;
	reverse(g.begin(), g.end());
	cout << g;
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}