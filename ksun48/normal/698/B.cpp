#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[210000];
int vis[210000];
vector<int> works;
int st = 0;
void dfs(int a){
	if(a == st && vis[a]){
		works.push_back(a);
	}
	if (vis[a]) return;
	vis[a] = 1;
	for(int i = 0; i < edges[a].size(); i++) dfs(edges[a][i]);
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		edges[a[i]].push_back(i);
	}
	for(int i = 0; i < n; i++){
		st = i;
		if(!vis[i]) dfs(i);
	}
	int ok = 0;
	int num = works[0];
	for(int i = 0; i < works.size(); i++){
		if(a[works[i]] == works[i]){
			ok = 1;
			num = works[i];
		}
	}
	for(int i = 0; i < works.size(); i++){
		a[works[i]] = num;
	}
	printf("%d\n", works.size()-ok);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]+1);
	}
	printf("\n");
}