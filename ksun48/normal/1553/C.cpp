#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	for(int j = 0; j <= 10; j++){
		for(int r = 0; r < 2; r++){
			vector<int> score(2, 0);
			for(int w = 0; w < 2; w++){
				for(int f = 0; f < 10; f++){
					if(f < j){
						if(s[f] == '0'){
							score[w] += 0;
						} else if(s[f] == '1'){
							score[w] += (f & 1) ? -1 : 1;
						} else {
							score[w] += r ? max((f & 1) ? -1 : 1, 0) : min((f & 1) ? -1 : 1, 0);
						}
					} else {
						score[w] += w ? max((f & 1) ? -1 : 1, 0) : min((f & 1) ? -1 : 1, 0);
					}
				}
			}
			if(score[0] > 0 && score[1] > 0){
				cout << j << '\n';
				return;
			}
			if(score[0] < 0 && score[1] < 0){
				cout << j << '\n';
				return;
			}
			if(score[0] == 0 && score[1] == 0){
				cout << j << '\n';
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}