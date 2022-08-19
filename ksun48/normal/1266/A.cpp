#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	if(s.find('0') == -1){
		cout << "cyan" << '\n';
		return;
	}
	int even = 0;
	for(char v : s){
		if((v - '0') % 2 == 0) even++;
	}
	if(even <= 1){
		cout << "cyan" << '\n';
		return;		
	}
	int x = 0;
	for(char v : s){
		x += (v - '0');
	}
	if(x % 3 == 0){
		cout << "red" << '\n';
	} else {
		cout << "cyan" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}