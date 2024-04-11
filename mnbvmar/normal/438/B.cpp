#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
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

int fu_pnt[MaxN], fu_rank[MaxN], fu_siz[MaxN];

int N, M;
int val[MaxN];
vector<int> Adj[MaxN];

void fu_init(){
	for(int i = 0; i <= N; i++){
		fu_pnt[i] = i;
		fu_rank[i] = fu_siz[i] = 1;
	}
}

int fu_find(int v){
	if(fu_pnt[v] == v)
		return v;
	else
		return (fu_pnt[v] = fu_find(fu_pnt[v]));
}

LL fu_union(int a, int b){
	a = fu_find(a);
	b = fu_find(b);
	
	if(a == b) return 0;
	
	int sa = fu_siz[a], sb = fu_siz[b];
	
	if(fu_rank[a] > fu_rank[b]){
		fu_pnt[b] = a;
		fu_rank[a]++;
		fu_siz[a] += fu_siz[b];
	} else {
		fu_pnt[a] = b;
		fu_rank[b]++;
		fu_siz[b] += fu_siz[a];
	}
	return (LL)sa * sb;
}


PII P[MaxN];

void input(){
	scanf("%d%d", &N, &M);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &val[i]);
		P[i] = PII(val[i], i);
	}
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	sort(P, P+N);
}


bool used[MaxN];

int main(){
	input();
	fu_init();
	
	LL sum = 0;
	fill(used, used+N, false);
	
	for(int i = N-1; i >= 0; i--){
		int v = P[i].second, val = P[i].first;
		used[v] = true;
		
		for(int s: Adj[v]){
			if(used[s]){
				sum += fu_union(v, s) * val;
			}
		}
	}
	
	printf("%.6lf\n", (double)((LD)sum / ((LL)N*(N-1)/2)));
	
	return 0;
}