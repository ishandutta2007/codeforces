#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string g;
	string h;
	for(char c : s){
		if(g.empty() || c <= g.back()){
			g += c;
		} else {
			h += (char)min(int(c) + 1, int('9'));
		}
	}
	g += h;
	sort(g.begin(), g.end());
	cout << g << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}