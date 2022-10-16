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


const int MaxN = 1005,
          MaxM = 2005;


int N, M;
int res = 0;
int v[MaxN];

void input(){
	scanf("%d%d", &N, &M);
	
	for(int i = 0; i < N; i++)
		scanf("%d", &v[i+1]);
	
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		res += min(v[a],v[b]);
	}
}



int main(){
	input();
	printf("%d\n", res);
	
	return 0;
}