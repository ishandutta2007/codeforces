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


const int MaxA = 30,
          MaxN = 105,
          Infty = 10101010;

int N;
int a[MaxN];

pair<int,int> inputData[MaxN];


int best[MaxN], bestVal=Infty;
int nonOne = 0;
int seq[MaxN];
int bad[MaxA*2];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &inputData[i].first);
		inputData[i].second = i;
	}
	fill(bad, bad+2*MaxA, 0);
}


int gcdtab[80][80];


int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}


void brute(int pos, int minVal, int diff){
	int left = N-pos;
	
	if(diff > bestVal) return;
	
	//printf("brute(%d,%d,%d) %d %d %d %d %d\n", pos, minVal, diff, seq[0],seq[1],seq[2],seq[3],seq[4]);
	if(pos == N){
		if(diff < bestVal){
			copy(seq, seq+N, best);
			bestVal = diff;
		}
		return;
	}
	
	if(minVal > a[N-1] && diff + (minVal-a[N-1])*left+left*(left-1)/2 >= bestVal) return;
	
	if(minVal >= 2*MaxA) return;
	
	bool good = true;
	
	for(int i = nonOne; i < pos; i++)
		if(gcdtab[seq[i]][minVal] > 1) good = false;
	
	if(good){
		seq[pos] = minVal;
		if(seq[pos] == 1) nonOne++;
		
		brute(pos+1, minVal, diff+abs(minVal-a[pos]));
		
		if(seq[pos] == 1) nonOne--;
	}
	
	brute(pos, minVal+1, diff);
}


void output(){
	int res[MaxN];
	
	REP(i,N){
		res[inputData[i].second] = best[i];
	}
	REP(i,N)
		printf("%d ", res[i]);
	printf("\n");
}


int main(){
	input();
	sort(inputData, inputData+N);
	REP(i,N) a[i] = inputData[i].first;
	
	REP(a,80) REP(b,80) gcdtab[a][b] = gcd(a,b);
	
	brute(0, 1, 0);
	
	output();
	
	return 0;
}