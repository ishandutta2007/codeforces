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

const int MaxLen = 100005,
          NumCh = 26;

int N, K;
int totalSize = 1;
int nextNode[MaxLen][NumCh];
bool canWin[MaxLen], canLose[MaxLen];
char str[MaxLen];

void input(){
	scanf("%d%d", &N, &K);
	REP(i,N){
		scanf("%s", str);
		int len = strlen(str);
		int ptr = 0;
		REP(pos, len){
			char c = str[pos]-'a';
			//printf("%d %d %d\n", c, nextNode[ptr][c], ptr);
			
			if(!nextNode[ptr][c]){
				nextNode[ptr][c] = totalSize++;
			}
			ptr = nextNode[ptr][c];
		}
	}
}

void dfs(int v){
	bool leaf = true;
	
	for(int ch = 0; ch < NumCh; ch++){
		if(nextNode[v][ch]){
			dfs(nextNode[v][ch]);
			leaf = false;
		}
	}
	
	if(leaf){
		canWin[v] = false;
		canLose[v] = true;
		return;
	}
	
	for(int ch = 0; ch < NumCh; ch++){
		int numNode = nextNode[v][ch];
		if(numNode){
			if(!canLose[numNode]){
				canLose[v] = true;
			}
			if(!canWin[numNode]){
				canWin[v] = true;
			}
		}
	}
	//printf("%d: %d%d\n", v, canWin[v], canLose[v]);
}



int main(){
	input();
	dfs(0);
	
	if(canWin[0] && canLose[0]){ // steal
		printf("First\n");
	} else if(canLose[0]){
		printf("Second\n");
	} else if(canWin[0]){
		printf(K % 2 == 0 ? "Second\n" : "First\n");
	} else {
		printf("Second\n");
	}
	
	
	return 0;
}