#include <bits/stdc++.h>
using namespace std;

string get(string x){
	string z;
	int cb = 0;
	for(char c : x){
		if(c == 'B'){
			cb ^= 1;
		} else if(!z.empty() && z.back() == c){
			z.pop_back();
		} else {
			z += c;
		}
	}
	if(cb) z += "B";
	return z;
}

void solve(){
	string a, b;
	cin >> a >> b;
	cout << (get(a) == get(b) ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}