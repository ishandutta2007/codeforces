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


/**** SEGMENT TREE ****/
const int MaxSiz = (1<<18),
          Base = (1<<17);

int segTree[MaxSiz];

void add(int p, int v){
	p += Base;
	while(p){
		segTree[p] += v;
		p /= 2;
	}
}
int get_sum(int L, int R){
	L += Base; R += Base;
	int res = segTree[L];
	if(L != R) res += segTree[R];
	
	while(L/2 != R/2){
		if(L%2==0) res += segTree[L+1];
		if(R%2==1) res += segTree[R-1];
		L /= 2; R /= 2;
	}
	return res;
}
/**** SEGMENT TREE ****/


int N, Q;
bool rev = false;
int idLeft, idRight;
int curLen;


void input(){
	scanf("%d%d", &N, &Q);
}


inline int get_id(int id){
	if(rev){
		return idRight - id;
	} else {
		return idLeft + id;
	}
}

void query_1(){
	int P;
	scanf("%d", &P);
	if(P*2 <= curLen){  // fold left->right
		for(int num = 0; num < P; num++){
			int idFrom = get_id(num),
			    idTo = get_id(P*2-num-1);
			
			int val = get_sum(idFrom, idFrom);
			add(idFrom, -val);
			add(idTo, val);
		}
		if(!rev){
			idLeft += P;
		} else {
			idRight -= P;
		}
		curLen -= P;
	} else {
		for(int num = curLen-1; num >= P; num--){
			int idFrom = get_id(num),
			    idTo = get_id(P*2-num-1);
			
			int val = get_sum(idFrom, idFrom);
			add(idFrom, -val);
			add(idTo, val);
		}
		if(!rev){
			idRight -= curLen-P;
			rev = true;
		} else {
			idLeft += curLen-P;
			rev = false;
		}
		curLen -= curLen-P;
	}
}

int query_2(){
	int L, R;
	scanf("%d%d", &L, &R);
	L = get_id(L);
	R = get_id(R-1);
	if(L > R) swap(L, R);
	//printf("%d %d\n", L, R);
	return get_sum(L, R);
}


void query(){
	int type;
	scanf("%d", &type);
	if(type == 1)
		query_1();
	else
		printf("%d\n", query_2());
	
	//printf("[%d,%d], rev=%d\n", idLeft,idRight,rev);
}


int main(){
	input();
	idLeft = 0;
	idRight = N-1;
	curLen = N;
	REP(i, N){
		add(i, 1);
	}
	
	while(Q--) query();
}