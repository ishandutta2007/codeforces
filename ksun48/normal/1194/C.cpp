#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s, t, p;
	cin >> s >> t >> p;
	int i = 0;
	for(char c : s){
		while(i < t.size() && t[i] != c) i++;
		if(i < t.size()){
			i++;
		} else {
			cout << "NO" << '\n';
			return;
		}
	}
	s += p;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	i = 0;
	for(char c : t){
		while(i < s.size() && s[i] != c) i++;
		if(i < s.size()){
			i++;
		} else {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int q;
	cin >> q;
	while(q--){
		solve();
	}
}