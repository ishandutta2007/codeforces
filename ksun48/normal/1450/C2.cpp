#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	int k = 0;
	for(string x : s) for(char y : x) if(y != '.') k++;
	for(int b = 0; b < 3; b++){
		for(string r : {"XO", "OX"}){
			vector<string> work = s;
			int ch = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if((i + j + b) % 3 == 0){
						if(work[i][j] == r[0]){
							work[i][j] = r[1];
							ch++;
						}
					}
					if((i + j + b + 1) % 3 == 0){
						if(work[i][j] == r[1]){
							work[i][j] = r[0];
							ch++;
						}
					}
				}
			}
			if(ch <= k/3){
				for(string x : work) cout << x << '\n';
				return;
			}
		}
	}
	assert(false);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}