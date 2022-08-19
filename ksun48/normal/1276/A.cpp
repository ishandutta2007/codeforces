#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> idx;
	for(int i = 0; i < n; i++){
		if(i + 5 <= n){
			if(s.substr(i, 5) == "twone"){
				idx.push_back(i + 3);
				s[i+2] = '.';
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(i + 3 <= n){
			if(s.substr(i, 3) == "one" || s.substr(i, 3) == "two"){
				idx.push_back(i + 2);
				s[i+1] = '.';
			}
		}
	}
	cout << idx.size() << '\n';
	for(int a : idx) cout << a << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}