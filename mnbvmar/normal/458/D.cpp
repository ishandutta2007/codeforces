#include <iostream>
#include <iomanip>
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

int N, M, K;


void input(){
	cin >> N >> M >> K;
}

LD res = 0;
LD lgfact[100005];


void preproc(){
	lgfact[0] = 0;
	FORI(i, 1, 100002){
		lgfact[i] = lgfact[i-1] + logl(i);
		//if(i < 10) printf("%lf\n", lgfact[i]);
	}
}



double comp(vector<int> A, vector<int> B){
	/*printf("comp(");
	for(int a: A) printf("%d,", a);
	printf(")(");
	for(int b: B) printf("%d,", b);
	printf(")\n");*/
	
	for(int a: A)
		if(a < 0) return 0;
	for(int b: B)
		if(b < 0) return 0;
		
	double logres = 0;
	for(int a: A){
		logres += lgfact[a];
	}
	for(int b: B){
		logres -= lgfact[b];
	}
	
	
	if(logres < -300)
		return 0;
	if(logres > 300)
		return 1e100;
	
	return exp(logres);
}

int main(){
	input();
	preproc();
	
	FORI(r, 0, N){
		FORI(c, 0, N){
			int g = (N-r)*(N-c);
			res += comp({N, N, K, M+g-N*N}, 
			            {r, c, N-r, N-c, K+g-N*N, M});
			//printf("%Lf\n", res);
		}
	}
	
	if(res > 1e99){
		cout << "1e99\n";
	} else {
		cout << setprecision(12) << res << "\n";
	}
	
	
	
	return 0;
}