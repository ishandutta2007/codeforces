#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > score(n, vector<int>(5));
	for(auto& x : score) for(int& y : x) cin >> y;
	int cur = 0;
	for(int i = 0; i < n; i++){
		int b = 0;
		for(int j = 0; j < 5; j++){
			if(score[i][j] < score[cur][j]){
				b++;
			}
		}
		if(b >= 3){
			cur = i;
		}
	}
	for(int i = 0; i < n; i++){
		int b = 0;
		for(int j = 0; j < 5; j++){
			if(score[i][j] < score[cur][j]){
				b++;
			}
		}
		if(b >= 3){
			cout << -1 << '\n';
			return;
		}
	}
	cout << (cur+1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}