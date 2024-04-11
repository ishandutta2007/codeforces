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


int N, M, K, W;

char board[1005][10][10];

int Adj[1005][1005];


void input(){
	scanf("%d%d%d%d", &N, &M, &K, &W);
	for(int i = 1; i <= K; i++){
		for(int r = 0; r < N; r++){
			scanf("%s", board[i][r]);
		}
	}
}

int dist(int i, int j){
	int num = 0;
	for(int r = 0; r < N; r++)
		for(int c = 0; c < M; c++)
			if(board[i][r][c] != board[j][r][c]) num++;
	return num;
}

void graph(){
	for(int i = 1; i <= K; i++){
		Adj[0][i] = Adj[i][0] = N*M;
	}
	
	for(int i = 1; i <= K; i++){
		for(int j = 1; j <= K; j++)
			Adj[i][j] = dist(i,j)*W;
	}
}

int minDist[1005], where[1005];
bool used[1005];

void act(int v){
	used[v] = true;
	for(int i = 0; i <= K; i++){
		if(minDist[i] > Adj[i][v]){
			minDist[i] = Adj[i][v];
			where[i] = v;
		}
	}
}

vector<PII> Res;
int sum;

int main(){
	input();
	graph();
	
	fill(minDist, minDist+1005, 1010101010);
	fill(where, where+1005, -1);
	fill(used, used+1005, false);
	
	minDist[0] = where[0] = 0;
	used[0] = true;
	
	act(0);
	
	for(int i = 1; i <= K; i++){		
		int wheremin = -1, minv = 1010101010;
		
		for(int v = 0; v <= K; v++){
			if(used[v]) continue;
			
			if(minDist[v] < minv){
				minv = minDist[v];
				wheremin = v;
			}
		}
		
		sum += minv;
		Res.push_back({wheremin, where[wheremin]});
		act(wheremin);
	}
	
	printf("%d\n", sum);
	for(PII R: Res){
		printf("%d %d\n", R.first, R.second);
	}
	
	return 0;
}