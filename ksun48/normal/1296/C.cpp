#include <bits/stdc++.h>
using namespace std;

void solve(){
	int r;
	cin >> r;
	string s;
	cin >> s;
	string g = "LRUD";
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	map<pair<int,int>, int> last;
	pair<int,int> cur = {0, 0};
	last[cur] = 0;
	pair<int,int> best = {-1, -1};
	for(int i = 0; i < (int)s.size(); i++){
		for(int j = 0; j < 4; j++){
			if(s[i] == g[j]){
				cur.first += dx[j];
				cur.second += dy[j];
			}
		}
		if(last.count(cur)){
			if(best.first == -1 || best.second - best.first > i - last[cur]){
				best = {last[cur], i};
			}
		}
		last[cur] = i+1;
	}
	if(best.first == -1){
		cout << -1 << '\n';
	} else {
		cout << best.first + 1 << ' ' << best.second + 1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}