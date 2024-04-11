#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int tot = 0;
	for(char c : s){
		tot += (c - 'a') + 1;
	}
	if(s.size() & 1){
		tot -= 2 * (min(s.front() - 'a', s.back() - 'a') + 1);
	}
	if(tot < 0){
		cout << "Bob " << (-tot) << '\n';
	} else {
		cout << "Alice " << tot << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}