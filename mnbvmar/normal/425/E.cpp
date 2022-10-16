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


const int MOD = 1000000007;

int N, K;
int DP[2][505][505];
int pwr[505];

void input(){
	scanf("%d%d", &N, &K);
	pwr[0] = 1;
	for(int i = 1; i <= 503; i++)
		pwr[i] = (pwr[i-1]*2)%MOD;
}


int main(){
	input();
	
	int sum = 0;
	
	for(int n = 0; n <= N; n++){
		int nb = n%2;
		int nbp = nb^1;
		
		// k == 0
		for(int k = 0; k <= K; k++)
			for(int p = 0; p <= n; p++)
				DP[nb][k][p] = 0;
		//fill(DP[nb][0], DP[nb][0]+N, 0);
		DP[nb][0][0] = 1;
		
		for(int k = 1; k <= K; k++){
			DP[nb][k][0] = 0;
			
			//printf("DP[%d][%d][%d]=%d\n", nb, k, n, DP[nb][k][n]);
			for(int p = 0; p <= n; p++){
				DP[nb][k][p] = (DP[nb][k][p] + (LL)DP[nbp][k][p] * (pwr[p]))%MOD;
				
				//printf("DP[%d][%d][%d]=%d; %d; %d; %d\n", nb,k,p,DP[nb][k][p],
				//DP[nbp][k-1][p], pwr[n-p], n-p);
				
				int mult = ((LL)pwr[p] * (pwr[n-p]+MOD-1))%MOD;
				DP[nb][k][n] =
					(DP[nb][k][n] + (LL)DP[nbp][k-1][p]*mult)%MOD;
					
				//printf("DP[%d][%d][%d]=%d; %d; %d; %d\n", nb,k,n,DP[nb][k][n],
				//DP[nbp][k-1][p], pwr[n-p], n-p);
			}
			//printf("DP[%d][%d][%d]=%d\n", nb, k, n, DP[nb][k][n]);
		}
	}
	
	//int sum = 0;
	for(int p = 0; p <= N; p++)
		sum = (sum+DP[N%2][K][p]) % MOD;
	
	printf("%d\n", sum);
	
	return 0;
}