#include <bits/stdc++.h>
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
typedef vector<int> VI;
typedef pair<int,int> PII;
const double Eps = 1e-7;
inline bool is_zero(double x){ return (x >= -Eps) && (x <= Eps); }

const int Mod = 1000000007;
const int MaxN = 5005;

int N, A, B, K;
LL dp[MaxN][MaxN];
LL pref[MaxN];

void input(){
	scanf("%d%d%d%d", &N, &A, &B, &K);
}

int DLast, DNum;  // 0..DLast, actually at DNum

void proc_input(){
	if(A < B){
		DNum = A-1;
		DLast = B-2;
	} else {
		DNum = N-A;
		DLast = N-B-1;
	}
}


int main(){
	input();
	proc_input();
	
	dp[0][DNum] = 1;
	
	REP(rides, K){
		fill(pref, pref+N, 0);
		REP(level, DLast+1){
			int range = DLast-level;
			dp[rides+1][level] = (Mod-dp[rides][level])%Mod;
			
			int dn = max(0, level-range);
			
			pref[dn] += dp[rides][level];
		}
		
		LL totPref = 0;
		REP(level, DLast+1){
			totPref += pref[level];
			dp[rides+1][level] += totPref;
			dp[rides+1][level] %= Mod;
		}
	}
	
	LL result = 0;
	REP(level, DLast+1)
		result += dp[K][level];
	
	printf("%d\n", (int)(result%Mod));
}