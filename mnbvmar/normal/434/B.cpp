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


const int MaxS = 1005;

int N, M, Q;
int tab[MaxS][MaxS];
int prefRow[MaxS][MaxS], prefCol[MaxS][MaxS];


void input(){
	scanf("%d%d%d", &N, &M, &Q);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++){
			scanf("%d", &tab[i][j]);
		}
}

void proc_row(int i){
	prefRow[i][0] = 0;
	for(int j = 1; j <= M; j++){
		prefRow[i][j] = prefRow[i][j-1] + tab[i][j];
	}
}

void proc_col(int j){
	prefCol[0][j] = 0;
	for(int i = 1; i <= N; i++){
		prefCol[i][j] = prefCol[i-1][j] + tab[i][j];
	}
}

void proc_query(){
	int type, r, c;
	scanf("%d%d%d", &type, &r, &c);
	
	if(type == 1){ // change
		tab[r][c] = 1-tab[r][c];
		proc_row(r);
		proc_col(c);
	} else {
		if(!tab[r][c]){
			printf("0\n");
			return;
		}
		
		int DL = c, DR = c;
		while(tab[r][DL] && DL > 0) DL--;
		while(tab[r][DR] && DR <= M) DR++;
		DL++; DR--;
		
		int best = (DR-DL+1);
		
		// w gore
		int ndl = DL, ndr = DR;
		for(int row = r-1; row > 0; row--){
			if(!tab[row][c]) break;
			while(prefRow[row][c]-prefRow[row][ndl-1] != c-ndl+1) ndl++;
			while(prefRow[row][ndr]-prefRow[row][c-1] != ndr-c+1) ndr--;
			best = max(best, (ndr-ndl+1)*(r-row+1));
		}
		//printf("[%d]\n", best);
		
		// w dol
		ndl = DL; ndr = DR;
		for(int row = r+1; row <= N; row++){
			if(!tab[row][c]) break;
			while(prefRow[row][c]-prefRow[row][ndl-1] != c-ndl+1) ndl++;
			while(prefRow[row][ndr]-prefRow[row][c-1] != ndr-c+1) ndr--;
			best = max(best, (ndr-ndl+1)*(row-r+1));
		}
		//printf("[%d]\n", best);
		
		int DU = r, DD = r;
		while(tab[DU][c] && DU > 0) DU--;
		while(tab[DD][c] && DD <= N) DD++;
		DU++; DD--;
		//printf("%d %d\n", DU, DD);
		
		best = max(best, DD-DU+1);
		//printf("[%d]\n", best);
		
		// w lewo
		int ndu = DU, ndd = DD;
		for(int col = c-1; col > 0; col--){
			if(!tab[r][col]) break;
			while(prefCol[r][col]-prefCol[ndu-1][col] != r-ndu+1) ndu++;
			while(prefCol[ndd][col]-prefCol[r-1][col] != ndd-r+1) ndd--;
			best = max(best, (ndd-ndu+1)*(c-col+1));
		}
		//printf("[%d]\n", best);
		
		// w prawo
		ndu = DU; ndd = DD;
		for(int col = c+1; col <= M; col++){
			if(!tab[r][col]) break;
			while(prefCol[r][col]-prefCol[ndu-1][col] != r-ndu+1) ndu++;
			while(prefCol[ndd][col]-prefCol[r-1][col] != ndd-r+1) ndd--;
			best = max(best, (ndd-ndu+1)*(col-c+1));
		}
		//printf("[%d]\n", best);
		
		
		printf("%d\n", best);
	}
}


int main(){
	input();
	for(int i = 1; i <= N; i++){
		proc_row(i);
	}
	for(int i = 1; i <= M; i++){
		proc_col(i);
	}
	
	while(Q--){
		proc_query();
	}
	
	return 0;
}