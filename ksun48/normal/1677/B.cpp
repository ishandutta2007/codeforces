#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> score(n * m);
	{
		vector<int> col(m, 0);
		int cur = 0;
		for(int i = 0; i < n*m; i++){
			if(s[i] == '1'){
				int c = i % m;
				if(!col[c]){
					cur++;
					col[c] = 1;
				}
			}
			score[i] += cur;
		}
	}
	vector<int> psum(n*m+1);
	for(int i = 0; i < n*m; i++){
		psum[i+1] = psum[i] + (s[i] == '1');
	}
	{
		for(int x = 0; x < m; x++){
			int cur = 0;
			for(int y = x; y < n*m; y += m){
				int r = psum[y+1] - psum[max(y+1-m, 0)];
				if(r) cur++;
				score[y] += cur;
			}
		}
	}
	for(int i = 0; i < n*m; i++){
		cout << score[i] << " \n"[i == n*m-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}