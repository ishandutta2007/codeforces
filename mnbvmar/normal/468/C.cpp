#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <set>
#include <map>
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
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-7;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


ULL A;

void input(){
	LL x;
	scanf("%I64d", &x);
	A = x;
}

ULL get_num(int l){
	ULL res = 45*l;
	REP(i, l-1) res = (res*10)%A;
	return res;
}


int main(){
	input();
	int needl = 0;
	LL pwr = 1;
	while(pwr < A){ pwr *= 10; needl++; }
	
	//printf("%llu\n", get_num(2));
	
	LL rem = (A-get_num(needl));
	while(rem <= 0) rem += A;
	
	printf("%I64d 1%0*I64d\n", rem, needl, rem-1);
}