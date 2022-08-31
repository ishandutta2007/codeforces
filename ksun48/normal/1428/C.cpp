#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	string cur;
	for(char c : s){
		if(c == 'B' && !cur.empty()){
			cur.pop_back();
		} else {
			cur += c;
		}
	}
	cout << cur.size() << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}