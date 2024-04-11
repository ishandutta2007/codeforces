#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int nl = 0;
	int score = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'L') nl++;
		if(i > 0 && s[i] == 'W' && s[i-1] == 'W') score++;
	}
	score += n - nl;
	k = min(k, nl);
	score += 2*k;
	if(nl == n){
		if(k > 0) score -= 1;
	} else {
		vector<int> group;
		int csz = -1e8;
		for(int i = 0; i < n; i++){
			if(s[i] == 'W'){
				if(csz > 0){
					group.push_back(csz);
				}
				csz = 0;
			} else {
				csz++;
			}
		}
		sort(group.begin(), group.end());
		for(int a : group){
			if(k >= a){
				k -= a;
				score += 1;
			}
		}
	}
	cout << score << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}