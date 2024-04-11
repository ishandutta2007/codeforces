	#include <bits/stdc++.h>
	using namespace std;
	typedef long long LL;

	int n, m;
	char stuff[51][51];
	char stuff2[51][51];
	int n1, m1;
	vector<pair<int,int> > ans[2];
	int flip = 0;

	// 0down, 1 right
	void solve(int i, int j, int dir, int f){
		if(dir == 0 && stuff[i][j] == 'U') return;
		if(dir == 1 && stuff[i][j] == 'L') return;
		if(dir == 0 && stuff[i][j] == 'L'){
			solve(i+1,j,1,f);
			ans[f].push_back(make_pair(i,j));
			stuff[i][j] = 'U';
			stuff[i+1][j] = 'D';
			stuff[i][j+1] = 'U';
			stuff[i+1][j+1] = 'D';
			return;
		}
		if(dir == 1 && stuff[i][j] == 'U'){
			solve(i,j+1,0,f);
			ans[f].push_back(make_pair(i,j));
			stuff[i][j] = 'L';
			stuff[i+1][j] = 'L';
			stuff[i][j+1] = 'R';
			stuff[i+1][j+1] = 'R';
			return;
		}
	}

	int main(){
		cin >> n >> m;
		for(int f = 0; f < 2; f++){
			for(int i = 0; i < n; i++){
				cin >> stuff[i];
			}
			if(n % 2 == 1){
				flip = 1;
				for(int i = 0; i < m; i++){
					for(int j = 0; j < n; j++){
						if(stuff[j][i] == 'L') stuff2[i][j] = 'U';
						if(stuff[j][i] == 'U') stuff2[i][j] = 'L';
						if(stuff[j][i] == 'R') stuff2[i][j] = 'D';
						if(stuff[j][i] == 'D') stuff2[i][j] = 'R';
					}
				}
				for(int i = 0; i < m; i++){
					for(int j = 0; j < n; j++){
						stuff[i][j] = stuff2[i][j];
					}
				}
				swap(m,n);
			}
			/*for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << stuff[i][j] << " ";
				}
				cout << endl;
			}*/

			for(int i = 0; i < n; i+= 2){
				for(int j = 0; j < m; j++){
					solve(i,j, 0,f);
				}
			}
			if(flip){
				swap(n,m);
			}			
		}
		cout << ans[0].size() + ans[1].size() << endl;
		reverse(ans[1].begin(), ans[1].end());
		for(int f = 0; f < 2; f++){
			for(int i = 0; i < ans[f].size(); i++){
				if(flip) swap(ans[f][i].first, ans[f][i].second);
				cout << ans[f][i].first + 1 << " " << ans[f][i].second + 1 << endl;
			}
		}




	}