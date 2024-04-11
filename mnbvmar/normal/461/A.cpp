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


const int MaxN = 300005;

int N;

int data[MaxN];


void input(){
	scanf("%d", &N);
	REP(i, N){
		scanf("%d", &data[i]);
	}
}



int main(){
	input();
	
	LL result = 0;
	sort(data, data+N);
	REP(i, N){
		result += (LL)min(i+2,N) * data[i];
	}
	printf("%I64d\n", result);
}