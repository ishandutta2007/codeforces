#include <bits/stdc++.h>
using namespace std;

void solve(){
	string t;
	cin >> t;
	reverse(t.begin(), t.end());
	map<char, int> freq;
	string ord;
	for(char c : t){
		if(!freq[c]) ord += c;
		freq[c]++;
	}
	int n = (int)ord.size();
	int len = 0;
	for(int i = 0; i < n; i++){
		len += freq[ord[i]] / (n-i);
	}
	reverse(t.begin(), t.end());
	if(len > t.size()){
		cout << -1 << '\n';
		exit(0);
	}
	string s = t.substr(0, len);
	reverse(ord.begin(), ord.end());
	string reals = s;
	string realt = "";
	for(char c : ord){
		realt += s;
		string news;
		for(char d : s){
			if(d != c) news += d;
		}
		s = news;
	}
	if(realt == t){
		cout << reals << " " << ord << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}