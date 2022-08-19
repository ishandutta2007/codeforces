#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	k--;
	string s(n, 'a');
	for(int r = n-1; r >= 0; r--){
		if(k < n-1-r){
			s[r] = 'b';
			s[n-1-k] = 'b';
			break;
		}
		k -= (n-1-r);
	}
	cout << s << '\n';
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}