#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int cost = 0;
	for(char c : s) if(c == '1') cost++;
	int best = 0;
	for(int i = 0; i < k; i++){
		vector<int> saves;
		for(int j = i; j < n; j += k){
			saves.push_back((s[j] == '1') ? 1 : -1);
		}
		vector<int> psums = {0};
		for(int a : saves) psums.push_back(psums.back() + a);
		int minp = 0;
		for(int a : psums){
			minp = min(minp, a);
			best = max(best, a - minp);
		}
	}
	cout << cost - best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}