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
const LD Eps = 1e-7;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


int N;

void input(){
	scanf("%d", &N);
}


int main(){
	input();
	
	if(N < 4){
		printf("NO\n");
	} else {
		printf("YES\n");
		if(N % 2 == 0){
			printf("1 * 2 = 2\n"
			       "2 * 3 = 6\n"
			       "6 * 4 = 24\n");
			
			for(int i = 5; i < N; i += 2){
				printf("%d - %d = 1\n"
				       "24 * 1 = 24\n", i+1, i);
			}
		} else {
			printf("5 + 3 = 8\n"
			       "8 - 2 = 6\n"
			       "6 * 1 = 6\n"
			       "6 * 4 = 24\n");
			
			for(int i = 6; i < N; i += 2){
				printf("%d - %d = 1\n"
				       "24 * 1 = 24\n", i+1, i);
			}
		}
	}
}