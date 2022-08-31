#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	string c = "NOTA";
	string s;
	cin >> s;
	sort(c.begin(), c.end());
	ll best = -1;
	string bests = "";
	do {
		string cur = s;
		string res = "";
		ll score = 0;
		for(char l : c){
			string z = "";
			int f = 0;
			for(char x : cur){
				if(x == l){
					score += f;
					res += x;
				} else {
					f++;
					z += x;
				}
			}
			cur = z;
		}
		if(score > best){
			best = score;
			bests = res;
		}
	} while (next_permutation(c.begin(), c.end()));
	cout << bests << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}