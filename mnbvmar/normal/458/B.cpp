#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <functional>
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
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


const int MaxN = 100005,
          Infty = 1010101010;
const ULL bigInfty = 1000000000000000000ULL;

int a[MaxN], b[MaxN], N, M;

void input(){
	scanf("%d%d", &N, &M);
	REP(i, N){
		scanf("%d", &a[i]);
	}
	REP(i, M){
		scanf("%d", &b[i]);
	}
}



int main(){
	input();
	
	sort(a, a+N, greater<int>());
	sort(b, b+M, greater<int>());
	a[N] = b[M] = -1;
	
	ULL bestVal = 1000000000ULL * 1000000000ULL * 10;
	
	ULL sumA = 0, sumB = 0;
	REP(i, N) sumA += a[i];
	REP(i, M) sumB += b[i];
	
	int ptrA = 0, ptrB = 0;
	LL totRes = 0;
	while(ptrA < N && ptrB < M){
		if(a[ptrA] >= b[ptrB]){
			totRes += sumB;
			sumA -= a[ptrA];
			bestVal = min(bestVal, totRes + sumA);
			ptrA++;
		} else {
			totRes += sumA;
			sumB -= b[ptrB];
			bestVal = min(bestVal, totRes + sumB);
			ptrB++;
		}
	}
	
	
	printf("%I64d\n", (LL)bestVal);
	
	return 0;
}