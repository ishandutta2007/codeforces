#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s, t;
	cin >> s >> t;
	int n = (int)s.size();
	for(int en = 0; en < n; en++){string g;
		for(int i = 0; i <= en; i++){
			g += s[i];
		}
		for(int i = en-1; i >= 0; i--){
			g += s[i];
		}
		if(g.find(t) != string::npos){
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}