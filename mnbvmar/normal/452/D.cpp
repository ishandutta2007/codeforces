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


int K, N[3], T[3];
int leaveTime[1005][3];

void input(){
	scanf("%d", &K);
	for(int i = 0; i < 3; i++) scanf("%d", &N[i]);
	for(int i = 0; i < 3; i++) scanf("%d", &T[i]);
}



int main(){
	input();
	
	for(int i = 0; i <= 1000; i++)
		leaveTime[i][0] = leaveTime[i][1] = leaveTime[i][2] = 0;
	
	int ltime = 0;
	
	for(int pc = 0; pc < K; pc++){
		int tmstart = 0, tdelta = 0;
		for(int i = 0; i < 3; i++){
			int pcmod = pc % N[i];
			
			tmstart = max(leaveTime[pcmod][i]-tdelta, tmstart);
			tdelta += T[i];
		}
		//printf("[%d]\n", tmstart);
		
		int tm = tmstart;
		for(int i = 0; i < 3; i++){
			int pcmod = pc % N[i];
			
			leaveTime[pcmod][i] = tm = tm + T[i];
		}
		
		ltime = max(ltime, tm);
	}
	
	printf("%d\n", ltime);
	
	
	return 0;
}