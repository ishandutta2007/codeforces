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


const int MaxN = 505;

int tbl[MaxN], N, M;
double best = 0;

void input(){
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &tbl[i]);
}



int main(){
	input();
	while(M--){
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		best = max(best, (double)(tbl[A]+tbl[B]) / C);
	}
	printf("%.12lf\n", best);
	
	return 0;
}