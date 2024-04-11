#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int,int> > ops;
	string des;
	for(int i = 0; i < k-1; i++) des += "()";
	for(int i = 0; i < n/2-k+1; i++) des += "(";
	for(int i = 0; i < n/2-k+1; i++) des += ")";
	for(int i = 0; i < n; i++){
		if(s[i] == des[i]) continue;
		for(int j = i; j < n; j++){
			if(s[j] == des[i]){
				ops.push_back({i, j});
				reverse(s.begin() + i, s.begin() + j + 1);
				break;
			}
		}
	}
	assert(s == des);
	cout << ops.size() << '\n';
	for(pair<int,int> x : ops){
		cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}