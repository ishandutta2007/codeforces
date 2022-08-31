#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
int r[110000];
int possible = 1;
vector<int> door[110000];
vector<int> edges[110000];
vector<int> val[110000];
int color[110000];
void dfs(int a, int c){
	if(color[a] + c == 1){
		possible = 0;
	}
	if(possible == 0) return;
	if(color[a] == c) return;
	color[a] = c;
	for(int j = 0; j < edges[a].size(); j++){
		dfs(edges[a][j],val[a][j] ^ c);
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> r[i];
	for(int i = 0; i < m; i++){
		color[i] = -1;
		int a;
		cin >> a;
		for(int j = 0; j < a; j++){
			int b;
			cin >> b;
			door[b-1].push_back(i);
		}
	}
	for(int i = 0; i < n; i++){
		int a = door[i][0];
		int b = door[i][1];
		edges[a].push_back(b);
		edges[b].push_back(a);
		val[a].push_back(1-r[i]);
		val[b].push_back(1-r[i]);
	}
	for(int i = 0; i < m; i++){
		if(color[i] == -1) dfs(i,0);
	}
	if(possible){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}