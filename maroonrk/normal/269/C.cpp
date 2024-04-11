#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
	
using namespace std;

typedef pair<int,int> pii;

struct Edge{
	int a,b,c,fr;
};

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

int main(){
	int n=read(),m=read();
	vector<Edge> edges(m);
	vector<vector<pii>> graph(n);
	vector<int> sum(n,0);
	REP(i,m){
		edges[i].a=read()-1;
		edges[i].b=read()-1;
		edges[i].c=read();
		edges[i].fr=-1;
		graph[edges[i].a].PB(MP(edges[i].b,i));
		sum[edges[i].a]+=edges[i].c;
		graph[edges[i].b].PB(MP(edges[i].a,i));
		sum[edges[i].b]+=edges[i].c;
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		REP(c,graph[v].size()){
			int to=graph[v][c].first;
			int e=graph[v][c].second;
			if(edges[e].fr==-1){
				edges[e].fr=v;
				if((sum[to]-=edges[e].c*2)==0&&to!=n-1)
					q.push(to);
			}
		}
	}
	REP(i,m){
		if(edges[i].a==edges[i].fr)
			printf("0\n");
		else
			printf("1\n");
	}
}