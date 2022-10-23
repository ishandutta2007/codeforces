#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N, K;
	cin >> N >> K;
	vector<string> S(N);
	for(string& s : S) cin >> s;
	K--;
	vector<vector<int> > score(N, vector<int>(N, 0));
	vector<vector<int> > psums(N+1, vector<int>(N+1, 0));
	vector<vector<pair<int,int> >> locs(K);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			score[i][j] = psums[i][j] + (S[i][j] == '0');
			psums[i+1][j+1] = max(psums[i+1][j+1], score[i][j]);
			psums[i+1][j+1] = max({psums[i+1][j+1], psums[i][j+1], psums[i+1][j], psums[i][j]});
			if(score[i][j] > K){
				cout << "NO" << '\n';
				return;
			}
			if(S[i][j] == '0') locs[score[i][j]-1].push_back({i, j});
		}
	}
	cout << "YES" << '\n';
	vector<vector<int> > used(N, vector<int>(N, 0));
	for(int r = 0; r < K; r++){
		vector<pair<int,int> > pts;
		for(auto [x, y] : locs[K-1-r]){
			if(used[x][y]) continue;
			pts.push_back({x, y});
		}
		pts.push_back({0, N-1-r});
		sort(pts.begin(), pts.end(), [&](pair<int,int> a, pair<int,int> b) {return a.first - a.second > b.first - b.second; } );
		pair<int,int> p = {N-1-r, 0};
		assert(!used[p.first][p.second]);
		used[p.first][p.second] = 1;
		for(auto g : pts){
			// cerr << "next " << g.first << ' ' << g.second << '\n';
			while(p != g){
				// for(int i = 0; i < N; i++){
				// 	for(int j = 0; j < N; j++){
				// 		cerr << (" X"[used[i][j]]);
				// 	}
				// 	cerr << '\n';
				// }
				if(p.second + 1 <= g.second && !used[p.first][p.second + 1]){
					p.second++;
					used[p.first][p.second] = 1;
				} else if(p.first - 1 >= g.first && !used[p.first - 1][p.second]){
					p.first--;
					used[p.first][p.second] = 1;
				} else assert(false);
				// cerr << p.first << ' ' << p.second << '\n';
				// cerr << g.first << ' ' << g.second << '\n';
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << (used[i][j]);
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}