#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	set<string> rs;
	set<string> rs1;
	for(string& x : s){
		string y = x;
		reverse(y.begin(), y.end());
		if(x == y){
			cout << "YES" << '\n';
			return;
		}
		if(rs.count(x) || rs1.count(x) || rs.count(x.substr(1))){
			cout << "YES" << '\n';
			return;			
		}
		rs.insert(y);
		rs1.insert(y.substr(1));
	}
	cout << "NO" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}