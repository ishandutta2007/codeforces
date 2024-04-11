#include <bits/stdc++.h>
using namespace std;

void solve(){
	int r, c, k;
	cin >> r >> c >> k;
	vector<string> s(r);
	for(string& a : s) cin >> a;
	int nr = 0;
	for(string a : s){
		for(char b : a){
			if(b == 'R') nr++;
		}
	}
	int avg = nr / k;
	int extra = nr % k;
	string letters;
	for(char x = '0'; x <= '9'; x++) letters += x;
	for(char x = 'A'; x <= 'Z'; x++) letters += x;
	for(char x = 'a'; x <= 'z'; x++) letters += x;
	vector<pair<int,int> > ord;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(i & 1){
				ord.push_back({i, j});
			} else {
				ord.push_back({i, c-1-j});
			}
		}
	}
	vector<string> ans = s;
	int cur = 0;
	for(int id = 0; id < k; id++){
		int cnt = 0;
		int need = avg;
		if(extra){
			extra--; need++;
		}
		while(cnt < need || (cur < (int)ord.size() && id == k-1)){
			ans[ord[cur].first][ord[cur].second] = letters[id];
			if(s[ord[cur].first][ord[cur].second] == 'R') cnt++;
			cur++;
		}
	}
	for(string a : ans){
		cout << a << '\n';
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