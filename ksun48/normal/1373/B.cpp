#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	vector<int> f(2);
	for(char c : s) f[c-'0']++;
	int r = min(f[0], f[1]);
	cout << ((r & 1) ? "DA" : "NET") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}