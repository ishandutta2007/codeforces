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


int N;

void input(){
	scanf("%d", &N);	
}


LL incr(LL from, LL to){
	LL f = __builtin_popcountll(from);
	LL t = __builtin_popcountll(to);
	if(f == t)
		return min(from,to);
	else if(t > f)
		return to;
	else
		return from;
}

int main(){
	input();
	while(N--){
		LL l, r;
		scanf("%I64d%I64d", &l, &r);
		LL best = l;
		//if(
		best = incr(best, r);
		//int best = max(__builtin_popcount(l), __builtin_popcount(r));

		const LL maxval = 1000000000 * (LL)1000000000;
		LL nl = l;

		for(LL u = 1; u < maxval; u *= 2){
			if((l | u) <= r) l |= u;
			best = incr(best, l);
		}
		//best = max(best, __builtin_popcount(l));

		l = nl;

		for(LL u = maxval; u >= 1; u /= 2){
			LL what = (r / u) * u - 1;
			if(what >= l){
				//best = max(best, __builtin_popcount(what));
				best = incr(best, what);
			}
		}

		printf("%I64d\n", best);
	}
}