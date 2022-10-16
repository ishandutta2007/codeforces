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

const int MaxN = 5005;

PII P[MaxN];
int N;

void input(){
	scanf("%d", &N);
	REP(i, N)
		scanf("%d%d", &P[i].first, &P[i].second);
}


int main(){
	input();
	sort(P, P+N);
	
	int lastDay = 0;
	REP(i, N){
		if(lastDay <= P[i].second)
			lastDay = P[i].second;
		else
			lastDay = P[i].first;
	}
	printf("%d\n", lastDay);
}