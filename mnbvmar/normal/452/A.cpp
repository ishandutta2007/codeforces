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


char strs[8][10] =
{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};


int N;
char S[10];

void input(){
	scanf("%d%s", &N, S);
	
}

bool good(int v){
	for(int i = 0; strs[v][i]; i++){
		if(S[i] != '.' && S[i] != strs[v][i]) return false;
	}
	return true;
}


int main(){
	input();
	for(int i = 0; i < 8; i++){
		if(good(i)){
			printf("%s\n", strs[i]);
			return 0;
		}
	}
	
	
	return 0;
}