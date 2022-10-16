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


const int MaxN = 100005,
          Infty = 2121212121;

int N, L, X, Y;
int marks[MaxN];

void input(){
	scanf("%d%d%d%d", &N,&L,&X,&Y);
	REP(i, N)
		scanf("%d", &marks[i]);
	marks[N] = Infty;
}

VI find_dist(int dst){
	if(dst > L) return {};
	
	VI result;
	int lptr = 0, rptr = 0;
	while(lptr < N){
		while(marks[lptr]+dst > marks[rptr]) rptr++;
		//printf("%d %d\n", lptr, rptr);
		if(marks[lptr]+dst == marks[rptr]) result.push_back(marks[lptr]);
		lptr++;
	}
	//printf("\n");
	return result;
}


bool check0(){
	return !find_dist(X).empty() && !find_dist(Y).empty();
}

int try_one(){
	VI res = find_dist(X+Y);
	if(!res.empty()){
		return res[0]+X;
	}
	
	res = find_dist(Y-X);
	for(int M: res){
		if(M-X >= 0) return M-X;
		if(M+Y <= L) return M+Y;
	}
	return 0;
	
	return 0;
}


int main(){
	input();
	bool measureX, measureY;
	
	measureX = !find_dist(X).empty();
	measureY = !find_dist(Y).empty();
	
	if(measureX && measureY){
		printf("0\n");
		return 0;
	}
	if(measureX || measureY){
		printf("1\n");
		if(!measureX){
			printf("%d\n", X);
		} else {
			printf("%d\n", Y);
		}
		return 0;
	}
	int mrk;
	if((mrk = try_one())){
		printf("1\n%d\n", mrk);
		return 0;
	}
	
	printf("2\n%d %d\n", X, Y);
	return 0;
}