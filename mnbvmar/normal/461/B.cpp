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


const int MaxN = 100005,
          Mod = 1000000007;

int N;
vector<int> adjGraph[MaxN];
bool black[MaxN];

void input(){
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		int p;
		scanf("%d", &p);
		adjGraph[p].push_back(i);
		adjGraph[i].push_back(p);
	}
	
	REP(v, N){
		int x;
		scanf("%d", &x);
		black[v] = (x==1);
	}
}


int pow_mod(int a, int b, int m){
	if(!b) return 1;
	int res = pow_mod(a, b/2, m);
	res = ((LL)res*res) % m;
	
	if(b % 2 == 1)
		res = ((LL)res*a) % m;
	
	return res;
}


int waysNoOut[MaxN],
    waysOneOut[MaxN];
bool vis[MaxN];

void dfs(int v, int p){
	vis[v] = true;
	for(int s: adjGraph[v]){
		if(s != p)
			dfs(s, v);
	}
	
	if(black[v]){
		waysNoOut[v] = 0;
		waysOneOut[v] = 1;
		for(int s: adjGraph[v]){
			if(s == p) continue;
			
			int waysConn = waysNoOut[s] + waysOneOut[s];
			waysOneOut[v] = ((LL)waysOneOut[v] * waysConn) % Mod;
		}
	} else {
		waysNoOut[v] = 1;
		for(int s: adjGraph[v]){
			if(s == p) continue;
			
			int waysConn = waysNoOut[s] + waysOneOut[s];
			waysNoOut[v] = ((LL)waysNoOut[v] * waysConn) % Mod;
		}
		
		
		waysOneOut[v] = 0;
		for(int s: adjGraph[v]){
			if(s == p) continue;
			
			int add = waysNoOut[v];
			int waysPrev = waysNoOut[s] + waysOneOut[s],
			    waysNew = waysOneOut[s];
			add = ((LL)add * pow_mod(waysPrev, Mod-2, Mod)) % Mod;
			add = ((LL)add * waysNew) % Mod;
			
			waysOneOut[v] = (waysOneOut[v] + add) % Mod;
		}
	}
	//printf("%d => %d %d\n", v, waysNoOut[v], waysOneOut[v]);
}

int dptree(){
	dfs(0,0);
	return (waysOneOut[0]) % Mod;
}


int main(){
	input();
	printf("%d\n", dptree());
}