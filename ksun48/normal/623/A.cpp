#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int edges[1000][1000];
int state[1000];
int valid = 1;
int n, m;
void dfs(int v, int a){
	//cout << v << " " << a << endl;
	if(state[v] == 0){
		state[v] = a;
		for(int i = 0; i < n; i++){
			if(i != v && state[i] != 2){
				if(edges[i][v] == 0){
					dfs(i,4-a);
				} else {
					dfs(i,a);
				}
			}
		} 
	} else {
		if(state[v] != a){
			valid = 0;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < 1000; i++){
	for(int j = 0; j < 1000; j++){
		edges[i][j] = 0;
	}

	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[u][v] = 1;
		edges[v][u] = 1;
	}
	for(int i = 0; i < n; i++){
		state[i] = 0;
	}
	int r = -1;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++) sum += edges[i][j];
		if(sum == n-1){
			state[i] = 2;
		} else {
			r = i;
		}
	}
	if(r >= 0) dfs(r,1);
	if(valid == 0){
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		for(int i = 0; i < n; i++){
			char k = 'a'+state[i]-1;
			cout << k;
		}
		cout << endl;
	}
}