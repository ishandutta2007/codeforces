#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s2.begin(), s2.end());
	map<pair<char, char>, int> freq;
	for(int i = 0; i < N; i++){
		freq[{min(s1[i], s2[i]), max(s1[i], s2[i])}] += 1;
	}
	bool works = true;
	int cnt = 0;
	for(auto [p, f] : freq){
		if(f & 1) cnt++;
		if(p.first != p.second && (f & 1)) works = false;
	}
	if(cnt >= 2) works = false;
	cout << (works ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}