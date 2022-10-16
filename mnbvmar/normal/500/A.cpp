#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int N, T;
int tab[50000];

void input(){
	scanf("%d%d", &N, &T);

	for(int i = 1; i < N; i++)
		scanf("%d", &tab[i]);
}

bool vis[50000];

void dfs(int v){
	if(v > N || vis[v]) return;
	vis[v] = true;

	if(v == N) return;

	dfs(tab[v]+v);
}

int main(){
	input();
	dfs(1);
	printf(vis[T] ? "YES\n" : "NO\n");
}