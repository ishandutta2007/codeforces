#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <string>

using namespace std;

typedef long long LL;

const int MaxN = 100005;

vector<int> Adj[MaxN];
int n, k, p;
int depth[MaxN];

void input(){
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
}

void dfs(int v, int pnt, int dep){
	depth[v] = dep;
	
	for(int s: Adj[v]){
		if(s != pnt)
			dfs(s, v, dep+1);
	}
}


int main(){
	input();
	
	dfs(0, 0, 0);
		
	sort(depth, depth+n);
	//for(int i = 1; i < n; i++) printf("%d ", depth[i]);
	//printf("\n");
	
	// 'gasienica'
	int L, R = 1;
	int best = 0;
	LL sum = 0;
	int mx = depth[1];
	depth[n] = 1010101010;
	
	for(L=1; L < n; L++){
		sum -= depth[L-1];
		
		while(R <= n){
			if((LL)(R-L)*mx - sum > p)
				break;
				
			sum += depth[R];
			mx = max(mx, depth[R]);
			R++;
		}
		
		best = max(best, R-L-1);
	}
	
	printf("%d\n", min(best, k));
}