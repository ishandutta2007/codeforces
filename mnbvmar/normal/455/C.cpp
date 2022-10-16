#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <set>
#include <map>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define ALL(container) (container).begin(), (container).end()
#define FORI(i,from,to) for(int i = (from); i <= (to); i++)
#define FORD(i,from,to) for(int i = (from); i >= (to); i--)
#define REP(i,num) for(int i = 0; i < (num); i++)


using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


const int MaxN = 300005;

/* find-union */
int fu_pnt[MaxN], fu_rank[MaxN], fu_maxlen[MaxN];

void fu_init(int N){
	REP(i,N+1){
		fu_pnt[i] = i;
		fu_rank[i] = 0;
		fu_maxlen[i] = 0;
	}
}
int fu_find(int v){
	if(v == fu_pnt[v])
		return v;
	else
		return (fu_pnt[v] = fu_find(fu_pnt[v]));
}

void fu_setlen(int v, int len){
	fu_maxlen[fu_find(v)] = len;
}

void fu_union(int a, int b){
	a = fu_find(a);
	b = fu_find(b);
	if(a == b) return;
	
	int maxLen = (fu_maxlen[a]+1)/2 + (fu_maxlen[b]+1)/2 + 1;
	maxLen = max(maxLen, fu_maxlen[a]);
	maxLen = max(maxLen, fu_maxlen[b]);
	fu_maxlen[a] = fu_maxlen[b] = maxLen;
	
	
	if(fu_rank[a] < fu_rank[b]){
		fu_pnt[a] = b;
		fu_rank[b]++;
	} else {
		fu_pnt[b] = a;
		fu_rank[a]++;
	}
}


int N, M, Q;
vector<int> Adj[MaxN];
bool vis1[MaxN], vis2[MaxN];
int dist1[MaxN], dist2[MaxN];


void input(){
	scanf("%d%d%d", &N, &M, &Q);
	fu_init(N);
	
	while(M--){
		int a, b;
		scanf("%d%d", &a, &b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
		fu_union(a,b);
	}
}


int dfs(int v, bool *vis, int *dist){
	int maxDist = dist[v], maxPos = v;
	vis[v] = true;
	
	for(int s: Adj[v]){
		if(vis[s]) continue;
		dist[s] = dist[v]+1;
		
		int res = dfs(s, vis, dist);
		if(dist[res] > maxDist){
			maxDist = dist[res];
			maxPos = res;
		}
	}
	return maxPos;
}



int main(){
	input();
	
	FORI(v,1,N){
		if(!vis1[v]){
			int a = dfs(v, vis1, dist1);
			int b = dfs(a, vis2, dist2);
			int minDst = dist2[b];
			fu_setlen(v, minDst);
		}
	}
	
	while(Q--){
		int tp, x, y;
		scanf("%d", &tp);
		if(tp == 1){
			scanf("%d", &x);
			printf("%d\n", fu_maxlen[fu_find(x)]);
		} else {
			scanf("%d%d", &x, &y);
			fu_union(x, y);
		}
	}
	
	
	return 0;
}