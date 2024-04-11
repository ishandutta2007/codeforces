#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 305;

int N;

int tab[MaxN];
bool mat[MaxN][MaxN];


void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &tab[i+1]);

	for(int i = 1; i <= N; i++){
		char str[500];
		scanf("%s", str);
		for(int j = 1; j <= N; j++){
//			char c;
//			scanf("%c", &c);
			mat[i][j] = (str[j-1]=='1');
		}
	}
}

bool vis[MaxN];
vector<vector<int>> components;
vector<int> newComp;

void dfs(int v){
	vis[v] = true;
	newComp.push_back(v);

	for(int s = 1; s <= N; s++){
		if(vis[s]) continue;
		if(!mat[v][s]) continue;
		dfs(s);
	}
}

int main(){
	input();

	for(int i = 1; i <= N; i++){
		if(!vis[i]){
			newComp.clear();
			dfs(i);
			components.push_back(newComp);
		}
	}

	for(auto comp: components){
		sort(comp.begin(), comp.end());
		vector<int> values;
		for(int a: comp) values.push_back(tab[a]);

		sort(values.begin(), values.end());

		for(int i = 0; i < comp.size(); i++)
			tab[comp[i]] = values[i];
	}

	for(int i = 1; i <= N; i++)
		printf("%d ", tab[i]);
	printf("\n");
}