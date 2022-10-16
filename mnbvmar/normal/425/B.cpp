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


int tab[105][105];
int n, m, k;

void input(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &tab[i][j]);
}

int st[105];

int output(int res){
	if(res > k)
			printf("-1\n");
		else
			printf("%d\n", res);
}

int main(){
	input();
	
	int best = 10000;
	
	if(n > k){
		for(int r = 0; r <= k; r++){
			copy(tab[r], tab[r]+m, st);
			
			int res = 0;
			for(int i = 0; i < n; i++){
				int num[2] = {0,0};
				for(int j = 0; j < m; j++){
					num[tab[i][j]^st[j]]++;
				}
				res += min(num[0], num[1]);
			}
			best = min(best, res);
		}
		output(best);
	} else {
		for(int mask = 0; mask < (1<<n); mask++){
			
			int res = 0;
			for(int c = 0; c < m; c++){
				
				int num[2] = {0,0};
				for(int r = 0; r <n; r++){
					int bit = (mask & (1<<r)) != 0;
					num[tab[r][c]^bit]++;
				}
				res += min(num[0], num[1]);
			}
			//printf("bit=%d res=%d\n", mask, res);
			best = min(best, res);
		}
		output(best);
	}
	
	return 0;
}