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
          Infty = 1000000000;

char strA[MaxN], strB[MaxN];
int A, B;
char numA[MaxN], numB[MaxN];

void input(){
	scanf("%s%s", strA, strB);
	A = strlen(strA);
	B = strlen(strB);
}



int main(){
	input();
	
	int N = max(A, B);
	fill(numA, numA+N+3, '0');
	fill(numB, numB+N+3, '0');
	
	REP(i, A)
		numA[N-A+i] = strA[i];
	REP(i, B)
		numB[N-B+i] = strB[i];
	
	
	N += 3;
	
	int ptr = 0;
	int who = 0;
	while(ptr < N){
		int diff = (numA[ptr] - numB[ptr]);
		ptr++;
		
		//printf("diff=%d who=%d\n", diff, who);
		
		if(diff == 0 && who >= -1 && who <= 1){
			who *= 2;
			continue;
		}
		
		if(diff >= 0 && who > 0){
			printf(">\n");
			return 0;
		}
		if(diff <= 0 && who < 0){
			printf("<\n");
			return 0;
		}
		if(diff > 0){
			if(who < 0)
				who++;
			else
				who = 2;
		}
		if(diff < 0){
			if(who > 0)
				who--;
			else
				who = -2;
		}
	}
	
	if(who > 0){
		printf(">\n");
	} else if(who < 0){
		printf("<\n");
	} else {
		printf("=\n");
	}
	
	
	return 0;
}