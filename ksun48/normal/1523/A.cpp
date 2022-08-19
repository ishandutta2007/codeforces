#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	m = min(m, 2*n + 2);
	string s;
	cin >> s;
	for(int _ = 0; _ < m; _++){
		string t = s;
		for(int i = 0; i < n; i++){
			int r = 0;
			if(i > 0 && s[i-1] == '1') r++;
			if(i+1 < n && s[i+1] == '1') r++;
			if(r == 1) t[i] = '1';
		}
		s = t;
	}
	cout << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}