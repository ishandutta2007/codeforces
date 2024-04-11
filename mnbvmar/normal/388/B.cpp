// a solution with (probably) n <= 76
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int Base = 4,
          MaxN = 1005;

vector<int> Adj[MaxN];
int N;


void add_edge(int u, int v){
	if(v == N+1) v = 2; // final vertex should have been N!
	if(u == N+1) u = 2;
	
	Adj[u].push_back(v);
	Adj[v].push_back(u);
}

void create_graph(int K){
	int KK = K;
	int M = 1; // number of layers = 1 + floor(log_4(K))
	while(K>=Base){ M++; K /= Base; }
	K = KK;
	
	N = (Base+1)*M+1;
	
	// first vertex to 0th layer
	for(int v = 3; v <= Base+2; v++)
		add_edge(1, v);
		
	// layer contents
	for(int L = 0; L < M; L++){ //L-th layer; Base^L ways to go there
		int firstVert = L*(Base+1) + 3;
		int pathVert = firstVert + Base;
		
		// connection with previous layer
		if(L){
			int prevFirstVert = firstVert - Base - 1,
			    prevPathVert = pathVert - Base - 1;
			for(int i = 0; i < Base; i++)
				for(int j = 0; j < Base; j++)
					add_edge(prevFirstVert+i, firstVert+j);
			
			add_edge(prevPathVert, pathVert);
		}
		
		int currDigit = (K % Base);
		K /= Base;
		// edges in current layer
		for(int i = 0; i < currDigit; i++)
			add_edge(firstVert+i, pathVert);
	}
}

char str[MaxN];
void output_graph(){
	printf("%d\n", N);
	str[N] = 0;
	
	for(int i = 1; i <= N; i++){
		fill(str, str+N, 'N');
		for(int j = 0; j < Adj[i].size(); j++){
			int v = Adj[i][j];
			str[v-1] = 'Y';
		}
		printf("%s\n", str);
	}
}

int main(){
	int K;
	scanf("%d", &K);
	
	create_graph(K);
	output_graph();
}