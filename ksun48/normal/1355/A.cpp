#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	ll n, k;
	cin >> n >> k;
	k--;
	while(k){
		string s = to_string(n);
		char m1 = '9';
		char m2 = '0';
		for(char c : s){
			m1 = min(m1, c);
			m2 = max(m2, c);
		}
		int res = (m1 - '0') * (m2 - '0');
		if(res == 0) break;
		n += res;
		k--;
	}
	cout << n << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}