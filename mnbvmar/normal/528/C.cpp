#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

const int MaxN = 100005;

int N, M, P;
vector<pair<int,int>> adj[MaxN];
vector<bool> isUsed[MaxN];
int curPos[MaxN];
int deg[MaxN];

vector<pair<int,int>> result;


void add_edge(int u, int v){
	adj[u].emplace_back(v, adj[v].size());
	if(u != v) adj[v].emplace_back(u, adj[u].size()-1);
	isUsed[u].push_back(false);
	if(u != v) isUsed[v].push_back(false);

	deg[u]++;
	deg[v]++;
}

void input(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
}

void euler(int v, int from = -1){
	while(curPos[v] < (int)adj[v].size()){
		if(isUsed[v][curPos[v]]){ curPos[v]++; continue; }
		
		int num = curPos[v];
		isUsed[v][num] = true;
		if(v != adj[v][num].first)
			isUsed[adj[v][num].first][adj[v][num].second] = true;
//		result.emplace_back(v, adj[v][num].first);

		euler(adj[v][num].first, v);
	}

	if(from != -1)
		result.emplace_back(from, v);
}

int main(){
	input();
	vector<int> odd;
	for(int i = 1; i <= N; i++)
		if(deg[i] % 2 == 1)
			odd.push_back(i);

	P = M;

	for(int i = 0; i < (int)odd.size(); i += 2){
		add_edge(odd[i], odd[i+1]);
		P++;
	}

	if(P % 2 == 1){
		add_edge(1, 1);
		P++;
	}

	euler(1);

	printf("%d\n", P);
	bool rev = false;
	for(auto edge: result){
		int u, v;
		tie(u, v) = edge;
		if(rev) swap(u, v);

		printf("%d %d\n", u, v);

		rev = !rev;
	}
}