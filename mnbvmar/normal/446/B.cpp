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


const int MaxSiz = 1005,
          MaxK = 1000005;

int N, M, K, P;
int tab[MaxSiz][MaxSiz];
int sumRow[MaxSiz], sumCol[MaxSiz];
LL bestRow[MaxK], bestCol[MaxK];

void input(){
	scanf("%d%d%d%d", &N, &M, &K, &P);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			scanf("%d", &tab[i][j]);
			sumRow[i] += tab[i][j];
			sumCol[j] += tab[i][j];
		}
}

void proc_max(int *sum, LL *best, int num, int opp){
	best[0] = 0;
	priority_queue<LL> Q;
	
	for(int i = 0; i < num; i++) Q.push(sum[i]);
	
	for(int i = 1; i <= K; i++){
		LL v = Q.top(); Q.pop();
		best[i] = best[i-1] + v;
		//printf("%lld\n", v);
		Q.push(v - opp*P);
	}
	//printf("\n");
}


int main(){
	input();
	proc_max(sumRow, bestRow, N, M);
	proc_max(sumCol, bestCol, M, N);
	//printf("Y\n");
	
	LL res = -1010101010LL * 1010101010;
	
	for(int i = 0; i <= K; i++){
		res = max(res, bestRow[i] + bestCol[K-i] - (LL)i*(K-i)*P);
	}
	
	printf("%I64d\n", res);
	
	
	return 0;
}