#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	set<char> ss;
	for(char c : s){
		ss.insert(c);
	}
	int k = ss.size();
	for(int i = k; i < s.size(); i++){
		if(s[i] != s[i-k]){
			cout << "NO" << '\n';
			return;
		}
	}
	set<char> ts;
	for(int i = 0; i < k; i++){
		ts.insert(s[i]);
	}
	if(ts.size() < k){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}