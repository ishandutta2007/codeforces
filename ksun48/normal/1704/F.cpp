#include <bits/stdc++.h>
using namespace std;

int N = 5.1e5;
vector<int> d(N, 0);
void init(){
	for(int i = 0; i < 300; i++){
		set<int> z;
		for(int j = 0; j <= i - 2; j++){
			z.insert(d[j] ^ d[i-2-j]);
		}
		while(z.count(d[i])) d[i]++;
	}
	for(int i = 300; i < N; i++){
		d[i] = d[i-34];
	}
}


void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int nr = 0;
	int nb = 0;
	for(char c : s){
		if(c == 'R') nr++;
		if(c == 'B') nb++;
	}
	if(nb > nr){
		cout << "Bob" << '\n';
		return;
	}
	if(nr > nb){
		cout << "Alice" << '\n';
		return;
	}
	vector<int> runs;
	int x = 0;
	for(int i = 0; i < n; i++){
		if(i > 0 && s[i] == s[i-1]){
			runs.push_back(x);
			x = 1;
		} else {
			x++;
		}
	}
	runs.push_back(x);
	int val = 0;
	for(int a : runs){
		val ^= d[a];
	}
	if(val == 0){
		cout << "Bob" << '\n';
	} else {
		cout << "Alice" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while(T--) solve();
}