#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>
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
          MaxM = 100005;

int M, N;
double prefMaxProbab[MaxM], maxProbab[MaxM];

void input(){
	scanf("%d%d", &M, &N);
}



int main(){
	input();
	for(int i = 1; i <= M; i++)
		prefMaxProbab[i] = pow((double)i / M, N);
	prefMaxProbab[0] = 0;
	for(int i = 1; i <= M; i++)
		maxProbab[i] = prefMaxProbab[i] - prefMaxProbab[i-1];
		
	double res = 0;
	for(int i = 1; i <= M; i++)
		res += maxProbab[i] * i;
	
	printf("%.9lf\n", res);
	
	return 0;
}