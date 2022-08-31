#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool allleft = true;
	bool allright = true;
	for(int i = 0; i < n; i++){
		if(s[i] == '<') allleft = false;
		if(s[i] == '>') allright = false;
	}
	if(allleft || allright){
		cout << n << '\n';
	} else {
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '-' || s[(i+1)%n] == '-') cnt++;
		}
		cout << cnt << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}