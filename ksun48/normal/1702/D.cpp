#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int p;
	cin >> p;
	int n = (int)s.size();
	vector<int> taken(n, 0);
	for(int i = 0; i < 26; i++){
		int cost = i+1;
		char c = 'a' + i;
		for(int j = 0; j < n; j++){
			if(s[j] != c) continue;
			if(p >= cost){
				p -= cost;
				taken[j] = 1;
			}
		}
	}
	for(int j = 0; j < n; j++){
		if(taken[j]){
			cout << s[j];
		}
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}