#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
vector<int> e[110000];
int vis[110000];
int no = 0;
// 0 = point
// 1 = side from both points
// 2 = halfplane
// 3 = double halfplane from 1
// 4 = double halfplane from side
// 5 = plane
int dfs(int a){
	if(vis[a]) return -1;
	//cout << a << endl;
	vis[a] = 1;
	int n[6];
	for(int i = 0; i < 6; i++) n[i] = 0;
	for(int i = 0; i < e[a].size(); i++){
		int r = dfs(e[a][i]);
		if(r >= 0){
			n[r]++;
			//cout << e[a][i] << " " << r << endl;
		}
	}
	if(n[5] >= 1){
		no = 1;
		return 5;
	}
	if(n[3] + n[4] >= 2){
		no = 1;
		return 5;
	}
	if(n[2]*(n[3]+n[4]) >= 1){
		no = 1;
		return 5;
	}
	if(n[2] >= 3){
		no = 1;
		return 5;
	}
	if(n[4] == 1){
		if(n[3] +n[2]+n[1]>= 1){
			no = 1;
			return 5;
		}
		if(n[0] >= 2){
			no = 1;
			return 5;
		}
		if(n[0] == 1){
			return 5;
		}
		if(n[0] == 0){
			return 4;
		}
	}
	if(n[3] == 1){
		if(n[2]+n[1]>= 1){
			no = 1;
			return 5;
		}
		if(n[0] >= 3){
			no = 1;
			return 5;
		}
		if(n[0] == 2){
			return 5;
		}
		return 4;
	}
	if(n[2] == 2){
		return 3;
	}
	if(n[2] == 1){
		return 2;
	}
	if(n[1] >= 1){
		return 2;
	}
	if(n[0] >= 3){
		return 2;
	}
	if(n[0] >= 2){
		return 1;
	}
	return 0;
}
int main(){
	cin >> n;
	int r = 0;
	for(int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
		vis[i] = 0;
	}
	for(int i = 0; i < n; i++){
		if(e[i].size() == 1){
			r = i;
		}
	}
	dfs(r);
	for(int i = 0; i < n; i++){
		//cout << dfs(i) << endl;
	}
	if(no == 1){
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}