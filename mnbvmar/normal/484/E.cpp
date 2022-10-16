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


const int SmallInfty = 1010101010;

/***/
const int MaxSize = (1<<18);
//int TA[MaxSize+5], TB[MaxSize+5];
LL TL[MaxSize], TR[MaxSize], TS[MaxSize], TB[MaxSize];
int Base;

void starttree(int siz){
	Base = 1;
	while(Base < siz) Base *= 2;

	fill(TL, TL+Base*2, 0);
	fill(TR, TR+Base*2, 0);
	fill(TS, TS+Base*2, -SmallInfty);
	fill(TB, TB+Base*2, 0);

	for(int i = Base-1; i > 0; i--){
		TS[i] = TS[2*i]*2;
	}
}

void putval(int P){
//	printf("P %d\n", P);
	P += Base;
	TL[P] = TR[P] = TB[P] = TS[P] = 1;
	P /= 2;
	while(P){
		TL[P] = max(TL[2*P], TS[2*P]+TL[2*P+1]);
		TR[P] = max(TR[2*P+1], TR[2*P]+TS[2*P+1]);
		TS[P] = TS[2*P] + TS[2*P+1];
		TB[P] = max(max(TB[2*P], TB[2*P+1]), TR[2*P]+TL[2*P+1]);
		P /= 2;
	}
}

LL getbest(int L, int R){
	L += Base; R += Base;
	LL result = max(TB[L], TB[R]);
	LL Lright=max(TB[L],0LL),
	   Rleft =max(TB[R],0LL);
	
//	printf("TB[L]=%lld, TB[R]=%lld\n", TB[L], TB[R]);

	while(L/2 != R/2){
		if(L % 2 == 0){
//			printf("TL,TR,TB,TS[%d]=%lld %lld %lld %lld\n",
//					L+1, TL[L+1], TR[L+1], TB[L+1], TS[L+1]);
			result = max(result, TB[L+1]);
			result = max(result, Lright+TL[L+1]);
			Lright = max(Lright+TS[L+1], TR[L+1]);
		}
		if(R % 2 == 1){
//			printf("TL,TR,TB,TS[%d]=%lld %lld %lld %lld\n",
//					R-1, TL[R-1], TR[R-1], TB[R-1], TS[R-1]);
			result = max(result, TB[R-1]);
			result = max(result, Rleft+TR[R-1]);
			Rleft  = max(Rleft+TS[R-1], TL[R-1]);
		}
		L /= 2; R /= 2;
	}
	result = max(result, Lright + Rleft);
//	printf("%lld, %lld, res = %lld\n", Lright, Rleft, result);
	return result;
}


/***/

const int MaxN = 100005,
	      MaxM = 100005;

int N, M;
int heights[MaxN];
int ql[MaxM], qr[MaxM], qw[MaxM];
int qmin[MaxN], qmax[MaxN], qmid[MaxN];
bool qres[MaxN];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &heights[i]);
	
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		scanf("%d%d%d", &ql[i], &qr[i], &qw[i]);
		ql[i]--; qr[i]--;
	}
}


int mapping[MaxN];
void decrease(){
	map<int,int> M;
	priority_queue<int> data;
	for(int i = 0; i < N; i++) data.push(heights[i]);

	int ptr = 0;
	while(!data.empty()){
		M[data.top()] = ptr++;
		data.pop();
	}

	for(int i = 0; i < N; i++){
		int val = heights[i],
			nval = M[val];
		mapping[nval] = val;
		heights[i] = nval;
	}
}

bool is_ok(){
	for(int i = 0; i < M; i++){
		if(qmin[i] != qmax[i]){
		//	printf("%d %d\n", qmin[i], qmax[i]);
			return false;
		}
	}
	return true;
}

void output(int x){
	printf("%d\n", mapping[x]);
}



struct act {
	bool is_join;
	int id;
	
	act(){}
	act(bool _is_join, int _id) : is_join(_is_join), id(_id) {}
};

vector<act> actions[MaxN];

void bsearch(){
	//printf("B\n");
	starttree(N);

	for(int i = 0; i <= N; i++) actions[i].clear();
	for(int i = 0; i < N; i++)
		actions[heights[i]].push_back(act(true, i));

	for(int i = 0; i < M; i++)
		actions[qmid[i]].push_back(act(false, i));

	
	for(int h = 0; h < N; h++){
		for(act A: actions[h]){
			int id = A.id;
			if(A.is_join){
				putval(id);
			} else {
				//printf("[%d]\n", id);
				qres[id] = (getbest(ql[id], qr[id]) >= qw[id]);
			}
		}
	}
}


int main(){
	input();
	decrease();

	for(int i = 0; i < M; i++){
		qmin[i] = 0;
		qmax[i] = N-1;
	}
	while(!is_ok()){
		//printf("A\n");
		for(int i = 0; i < M; i++){
			qmid[i] = (qmin[i] + qmax[i]) / 2;
		//	printf("%d ", qmid[i]);
		}
		//printf("\n");
		bsearch();
		for(int i = 0; i < M; i++){
			if(qmin[i] == qmax[i]) continue;
			if(qres[i]){
				qmax[i] = qmid[i];
			} else {
				qmin[i] = qmid[i]+1;
			}
		}
	}

	for(int i = 0; i < M; i++)
		output(qmin[i]);
}