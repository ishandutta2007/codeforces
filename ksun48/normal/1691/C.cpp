#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int score = 0;
	for(char c : s){
		if(c == '1') score += 11;
	}
	int best = score;
	int i = 0;
	while(i < n && s[i] == '0') i++;
	int j = n-1;
	while(j >= 0 && s[j] == '0') j--;
	if(i < n && i <= k) best = min(best, score - 1);
	if(j >= 0 && (n-1-j) <= k) best = min(best, score - 10);
	if(i < j && i < n && j >= 0 && (i + (n-1-j)) <= k) best = min(best, score-11);
	cout << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}