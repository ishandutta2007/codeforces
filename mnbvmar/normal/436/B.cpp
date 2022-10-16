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



/**********************************************************************/


int N, M, K;
char board[2005][2005];

void input(){
	scanf("%d%d%d", &N, &M, &K);
	
	for(int i = 0; i < N; i++)
		scanf("%s", board[i]);
}


int num[2005];

int main(){
	input();
	
	fill(num, num+2005, 0);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			int what = -1;
			switch(board[i][j]){
				case 'R':
					what = i+j;
					break;
				case 'L':
					what = j-i;
					break;
				case 'U':
					what = (i % 2 == 0 ? j : -1);
					break;
			}
			if(what >= 0 && what < M) num[what]++;
		}
		
	for(int i = 0; i < M; i++) printf("%d ", num[i]);
	printf("\n");
	
	return 0;
}