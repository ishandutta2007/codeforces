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


char str[1005];
int N, P;

void input(){
	scanf("%d%d", &N, &P);
	scanf("%s", str);
}


bool good(int r){
	REP(i, r){
		if(i > 0 && str[i]==str[i-1]) return false;
		if(i > 1 && str[i]==str[i-2]) return false;
	}
	return true;
}

int main(){
	input();
	//int bad = -1;
	FORD(r, N-1, 0){
		char prev = str[r];
		FORI(c, str[r]+1, 'a'+P-1){
			str[r] = c;
			if(good(r+1)){
				for(int i = r+1; i < N; i++){
					
					FORI(c, 'a', 'a'+P-1){
						str[i] = c;
						if(good(i+1)) break;
					}
					if(!good(i)){ printf("NO\n"); return 0; }
					
				}
				printf("%s\n", str);
				return 0;
			}
		}
		str[r] = prev;
	}
	printf("NO\n");
	
}