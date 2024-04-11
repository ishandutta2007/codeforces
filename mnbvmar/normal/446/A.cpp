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

int tbl[MaxN], N;
int num[MaxN], numd[MaxN];


void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &tbl[i]);
}



int main(){
	input();
	
	num[N-1] = 1;
	num[N] = 0;
	for(int i = N-2; i >= 0; i--){
		if(tbl[i] < tbl[i+1])
			num[i] = num[i+1]+1;
		else
			num[i] = 1;
	}
	
	int res = min(*max_element(num, num+N) + 1, N);
	
	numd[0] = 1;
	for(int i = 1; i < N; i++){
		if(tbl[i] > tbl[i-1])
			numd[i] = numd[i-1]+1;
		else
			numd[i] = 1;
	}
	
	for(int i = 1; i < N-1; i++){
		if(tbl[i+1] - tbl[i-1] >= 2){
			//printf("%d  %d %d\n", i, numd[i-1], num[i+1]);
			res = max(res, numd[i-1]+num[i+1]+1);
		}
	}
	
	printf("%d\n", res);
	
	
	return 0;
}