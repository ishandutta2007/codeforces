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

const int MaxN = 1000005;

int N;
int tab[MaxN];
LL dp[MaxN];
int start_incr[MaxN], start_decr[MaxN];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &tab[i]);
}

LL getval(int to, int from){
	if(from > to) return 0;

	LL res = abs(tab[to]-tab[from]);
	res += dp[from];
	return res;
}


int main(){
	input();
	dp[0] = dp[1] = 0;
	start_incr[0] = start_decr[0] = 0;

	for(int i = 1; i < N; i++){
		if(tab[i] > tab[i-1]){
			start_incr[i] = start_incr[i-1];
			start_decr[i] = i;
		} else if(tab[i] < tab[i-1]){
			start_incr[i] = i;
			start_decr[i] = start_decr[i-1];
		} else {
			start_incr[i] = start_decr[i] = i;
		}

		dp[i+1] = max(max(getval(i, start_incr[i]), getval(i, start_incr[i]+1)),
			          max(getval(i, start_decr[i]), getval(i, start_decr[i]+1)));
	}
	printf("%I64d\n", dp[N]);
}