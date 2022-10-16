#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

typedef unsigned long long ULL;

const int maxN = 80005;

vector<int> Adj[maxN];
int n, u, v;
bool vis[maxN];
int ins[maxN];

ULL sum = 0;

void dfs(int v){
	vis[v] = true;
	ins[v] = 1;
	
	ULL val, ss=0, sq=0;
	
	for(int i = 0; i < Adj[v].size(); i++){
		int s = Adj[v][i];
		if(vis[s]) continue;
		dfs(s);
		ins[v] += ins[s];
		
		ss += ins[s];
		sq += (ULL)ins[s] * ins[s];
	}
	
	//val = n-ins[v];
	//ss += val;
	//sq += val*val;
	val = (ss*ss-sq)/2;
	val += ins[v]-1;
	//printf("v=%d val=%llu ss=%llu sq=%llu ins=%d, nv=%llu\n", v, val, ss, sq, ins[v], val*(ins[v]*(n-ins[v]+1)-1-val));
	sum += val*val + val*(ins[v]*(n-ins[v]+1)-ins[v])*2;

}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &u, &v);
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	dfs(1);
	
	ULL rz = (ULL)n * (n-1)/2;
	rz *= rz;
	
	cout << rz-sum << endl;
}