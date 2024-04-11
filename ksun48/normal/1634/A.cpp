#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	string rs = s;
	reverse(rs.begin(), rs.end());
	if(s == rs || k == 0){
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}