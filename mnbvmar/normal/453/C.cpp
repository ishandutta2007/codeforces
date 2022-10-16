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


const int MaxN = 100005;

int N, M;
vector<int> Adj[MaxN];
vector<int> res;
int parity[MaxN];
int numOdd = -1;
bool vis[MaxN];
bool print_first = true;

void input(){
	scanf("%d%d", &N, &M);
	REP(i,M){
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	REP(i,N){
		scanf("%d", &parity[i]);
		if(parity[i]) numOdd = i;
	}
}

void add_res(int v){
	//printf("%d\n", v);
	res.push_back(v);
	parity[v] = !parity[v];
}

void dfs(int v, int p){
	vis[v] = true;
	add_res(v);
	
	for(int s: Adj[v]){
		if(vis[s]) continue;
		dfs(s, v);
	}
	if(parity[v]){
		if(v != p){
			add_res(p);
			add_res(v);
		} else {
			print_first = false;
			parity[v] = !parity[v];
		}
	}
	if(v != p) add_res(p);
}



int main(){
	input();
	if(numOdd == -1){
		printf("0\n");
		return 0;
	}
	dfs(numOdd, numOdd);
	
	REP(i,N){
		if(parity[i]){
			printf("-1\n");
			return 0;
		}
	}
	
	if(print_first)
		printf("%d\n", res.size());
	else
		printf("%d\n", res.size()-1);
		
	for(int r: res){
		if(!print_first)
			print_first = true;
		else
			printf("%d ", r+1);
	}
	printf("\n");
	
	return 0;
}