#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <complex>
#include <string.h>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>

using namespace std;

const int maxN = 200005,
          maxM = 200005;

vector< pair<int,int> > Adj[maxN];

int n, m;
int u[maxM], v[maxM], cc[maxM], a, b, c;
long long dg[maxN], fdg[maxN];
int dir[maxM];

queue<int> Q;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &c);
		u[i] = a; v[i] = b; cc[i] = c;
		Adj[a].push_back(make_pair(b,i));
		Adj[b].push_back(make_pair(a,i));
		dg[a] += c;
		dg[b] += c;
		dir[i] = -1;
	}
	
	Q.push(1);
	while(!Q.empty()){
		int z = Q.front(); Q.pop();
		//printf("z=%d\n", z);
		for(int i = 0; i < Adj[z].size(); i++){
			int s = Adj[z][i].first, ww = Adj[z][i].second;
			if(dir[ww] != -1) continue;
			
			//printf("i=%d,s=%d,ww=%d,u[]=%d,v[]=%d\n",i,s,ww,u[ww],v[ww]);
			if(z == u[ww]) dir[ww] = 0; else dir[ww] = 1;
			
			fdg[s] += cc[ww];
			if(s != n && dg[s]-fdg[s] == fdg[s]) Q.push(s);
		}
	}
	
	for(int i = 0; i < m; i++){
		//if(dir[i] == -1) 
		printf("%d\n", dir[i]);
	}
	return 0;
}