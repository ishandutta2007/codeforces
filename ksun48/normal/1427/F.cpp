#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	n *= 6;
	vector<int> color(n, 1);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		color[a] = 0;
	}
	const int FAIL = -1e8;
	vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
	vector<vector<int> > where(n+1, vector<int>(n+1, 0));
	for(int l = 0; l <= n; l += 3){
		for(int j = 0; j + l <= n; j++){
			if(l == 0){
				dp[j][j+l] = FAIL;
			} else {
				for(int k = j+1; k < j+l; k++){
					if(!dp[j][j+l] && dp[j][k] && dp[k][j+l]){
						dp[j][j+l] = k;
					}
				}
				for(int k = j+1; k < j+l-1; k++){
					if(!dp[j][j+l] && color[j] == color[k] && color[k] == color[j+l-1] && dp[j+1][k] && dp[k+1][j+l-1]){
						dp[j][j+l] = -k;
					}
				}
			}
		}
	}
	pair<int, int> works = {-1, -1};
	for(int a = 0; a <= n; a++){
		for(int b = 0; b <= n; b++){
			if(color[a] == 1 && dp[0][a] && dp[a][b] && dp[b][n]){
				works = {a, b};
			}
		}
	}
	assert(works.first >= 0);
	vector<pair<int,int> > segs;
	segs.push_back({0, works.first});
	segs.push_back({works.first, works.second});
	segs.push_back({works.second, n});

	vector<vector<int> > trips;
	int turn = 1;
	while(!segs.empty()){
		for(int i = 0; i < (int)segs.size(); i++){
			if(segs[i].first == segs[i].second){
				segs.erase(segs.begin() + i);
				goto here;
			}
		}
		for(int i = 0; i < (int)segs.size(); i++){
			int r = segs[i].first;
			int s = segs[i].second;
			assert(dp[r][s]);
			if(dp[r][s] > 0){
				int mid = dp[r][s];
				segs.erase(segs.begin() + i);
				segs.push_back({r, mid});
				segs.push_back({mid, s});
				goto here;
			}
		}
		for(int i = 0; i < (int)segs.size(); i++){
			int r = segs[i].first;
			int s = segs[i].second;
			if(dp[r][s] < 0 && s-r > 3 && color[r] == turn){
				int mid = -dp[r][s];
				trips.push_back({r, mid, s-1});
				segs.erase(segs.begin() + i);
				segs.push_back({r+1, mid});
				segs.push_back({mid+1, s-1});
				turn ^= 1;
				goto here;
			}
		}
		for(int i = 0; i < (int)segs.size(); i++){
			int r = segs[i].first;
			int s = segs[i].second;
			if(dp[r][s] < 0 && color[r] == turn){
				int mid = -dp[r][s];
				trips.push_back({r, mid, s-1});
				segs.erase(segs.begin() + i);
				segs.push_back({r+1, mid});
				segs.push_back({mid+1, s-1});
				turn ^= 1;
				goto here;
			}
		}
		here:;
	}
	reverse(trips.begin(), trips.end());
	for(vector<int> a : trips){
		cout << a[0] + 1 << ' ' << a[1] + 1 << ' ' << a[2] + 1 << '\n';
	}
}