#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
	
using namespace std;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int maxN=200000;

struct Edge{
	int to,idx;
};
int est[maxN][2];
bool rem[maxN];
stack<Edge> graph[maxN*2]; 
int deg[maxN*2],col[maxN],red[maxN*2],blue[maxN*2];

void dfs(int v,int k){
	while(!graph[v].empty()){
		Edge e=graph[v].top();
		graph[v].pop();
		if(!rem[e.idx]){
			rem[e.idx]=true;
			col[e.idx]=k;
			dfs(e.to,1-k);
			break;
		}
	}
}

int main(){
	int n=read();
	REP(i,n){
		int x=read()-1,y=maxN+read()-1;
		est[i][0]=x;
		est[i][1]=y;
		graph[x].push(Edge{y,i});
		graph[y].push(Edge{x,i});
		deg[x]++;
		deg[y]++;
	}
	stack<int> oddV,oddE;
	REP(i,maxN*2)
		if(deg[i]&1)
			oddV.push(i);
	while(!oddV.empty()){
		int v=oddV.top();
		oddV.pop();
		if((deg[v]&1)==0)
			continue;
		Edge e;
		do{
			e=graph[v].top();
			graph[v].pop();
		}while(rem[e.idx]);
		rem[e.idx]=true;
		deg[v]--;
		deg[e.to]--;
		oddE.push(e.idx);
		if(deg[e.to]&1)
			oddV.push(e.to);
	}
	REP(i,maxN*2)
		dfs(i,0);
	while(!oddE.empty()){
		int e=oddE.top();
		oddE.pop();
		int s=est[e][0],t=est[e][1];
		if(red[s]<blue[s]||red[t]<blue[t]){
			red[s]++;
			red[t]++;
			col[e]=0;
		}else{
			blue[s]++;
			blue[t]++;
			col[e]=1;
		}
	}
	REP(i,n)
		printf(col[i]?"r":"b");
	printf("\n");
}