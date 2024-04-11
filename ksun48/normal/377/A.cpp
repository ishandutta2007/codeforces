#include<iostream>
using namespace std;
#include<string>
typedef long long LL;
string stuff[600];
int n, m, k;
int nVis = 0;
int vis[600][600];
int lasti = -1, lastj = -1;
void dfs(int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m) return;
	if(stuff[i][j] != '.') return;
	if(vis[i][j]) return;
	if(nVis >= n*m-k){
		stuff[i][j] = 'X';
	}
	vis[i][j] = 1;
	nVis++;
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
	return;
}
void remove(){
	int ai, aj;
	nVis = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vis[i][j] = 0;
			if(stuff[i][j] == '.'){
				ai = i;
				aj = j;
			} else {
				vis[i][j] = 1;
				nVis++;
			}
		}
	}
	dfs(ai, aj);
	return;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> stuff[i];
	remove();
	for(int i = 0; i < n; i++){
		cout << stuff[i] << endl;
	}
}