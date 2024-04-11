#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


vector<vector<int> > edges;
vector<int> ans; 
int dfs(int v, int p){
	int num = 0;
	for(int a : edges[v]){
		if(a == p) continue;
		num += dfs(a, v);
	}
	if(num == 0) num++;
	ans.push_back(num);
	return num;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		a = i+1;
		cin >> b;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0, -1);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}