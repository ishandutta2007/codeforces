#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 100005;

int N, Q;
vector<tuple<int,int,int>> adj[MaxN];

int upEdge[MaxN], treeSize[MaxN];
int whichEdge[MaxN];


void input(){
	scanf("%d", &N);

	for(int i = 0; i < N-1; i++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].emplace_back(v,c,i+1);
		adj[v].emplace_back(u,c,i+1);
	}

	scanf("%d", &Q);
}

void dfs(int v, int p){
	treeSize[v] = 1;

	for(auto PA: adj[v]){
		int s, c, num;
		tie(s,c,num) = PA;
//		int s = PA.first, c = PA.second;

		if(s == p) continue;
		upEdge[s] = c;
		whichEdge[num] = s;
		dfs(s, v);

		treeSize[v] += treeSize[s];
	}
}

double edgeCoef[MaxN];

int main(){
	input();
	dfs(1, 1);

	double result = 0;

	for(int i = 2; i <= N; i++){
		edgeCoef[i] = (double)6 * treeSize[i] * (N-treeSize[i]) / N
			/ (N-1);

		result += edgeCoef[i] * upEdge[i];
	}

	while(Q--){
		int e, newCost;
		scanf("%d%d", &e, &newCost);

		int vert = whichEdge[e];
		int prevCost = upEdge[vert];

		result -= (prevCost-newCost)*edgeCoef[vert];
		upEdge[vert] = newCost;

		printf("%.10lf\n", result);

//		for(int i = 0; i < vert; i++){
//
//		}
	}
}