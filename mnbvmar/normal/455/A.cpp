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
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


const int MaxVal = 100005;

int countNum[MaxVal];
LL dpRes[MaxVal];
int N;

void input(){
	scanf("%d", &N);
	REP(i, N){
		int a;
		scanf("%d", &a);
		countNum[a]++;
	}
}



int main(){
	input();
	
	REP(val, MaxVal){
		if(val < 2){
			dpRes[val] = max(dpRes[0], (LL)countNum[val]*val);
		} else {
			dpRes[val] = max(dpRes[val-2]+(LL)countNum[val]*val, dpRes[val-1]);
		}
	}
	printf("%I64d\n", dpRes[MaxVal-1]);
	
	
	return 0;
}