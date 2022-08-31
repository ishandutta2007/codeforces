#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	int diff = 0;
	int same = 0;
	int same2 = 0;
	for(int i = 0; i <= n-1-i; i++){
		if(s[i] != s[n-1-i]){
			diff++;
		} else if(s[i] == '0'){
			if(i == n-1-i){
				same2++;
			} else {
				same++;
			}
		}
	}
	if(diff == 0){
		if(same2 && same > 0){
			cout << "ALICE" << '\n';
		} else {
			cout << "BOB" << '\n';
		}
	} else {
		b += diff;
		if(same2 == 0){
			a += (same + 1) / 2 * 2;
			b += (same / 2) * 2;
		} else {
			a += 1;
			b += (same + 1) / 2 * 2;
			a += (same / 2) * 2;
		}
		if(a == b){
			cout << "DRAW" << '\n';
		} else if(a < b){
			cout << "ALICE" << '\n';
		} else if(a > b){
			cout << "BOB" << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}