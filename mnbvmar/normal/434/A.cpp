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



const int MaxN = 100005,
          MaxM = 100005;
          
int tab[MaxM], N, M;
vector<int> occur[MaxN];

void input(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d", &tab[i]);
		occur[tab[i]].push_back(i);
	}
}


LL sum = 0, best = 0;

int main(){
	input();
	
	for(int i = 0; i < M-1; i++)
		sum += abs(tab[i]-tab[i+1]);
		
	best = sum;
	
	for(int i = 1; i <= N; i++){
		vector<int> poss;
		//poss.push_back(i);
		
		for(int v: occur[i]){
			if(v && tab[v-1] != tab[v]) poss.push_back(tab[v-1]);
			if(v != M-1 && tab[v+1] != tab[v]) poss.push_back(tab[v+1]);
		}
		
		LL sumDecr = 0, sumZero = 0;
		int deg = -poss.size(), last = 0;
		for(int v: occur[i]){
			if(v && tab[v-1] != tab[v]){ sumDecr += abs(tab[v]-tab[v-1]); sumZero += tab[v-1]; }
			if(v != M-1 && tab[v+1] != tab[v]){ sumDecr += abs(tab[v]-tab[v+1]); sumZero += tab[v+1]; }
		}
		
		
		sort(poss.begin(), poss.end());
		LL sumPrim = sum - sumDecr + sumZero;
		//printf("i=%d sum=%lld decr=%lld zero=%lld\n", i, sum, sumDecr, sumZero);
		
		//int deg = -poss.size(), last = 0;
		//printf("deg=%d\n", deg);
		
		for(int v: poss){
			int diff = v - last;
			sumPrim += (LL)deg * diff;
			//printf("v=%d sumPrim=%lld\n", v, sumPrim);
			best = min(best, sumPrim);
			last = v;
			
			deg += 2; 
		}
	}
	
	printf("%I64d\n", best);
	
	return 0;
}