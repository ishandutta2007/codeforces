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

int n, m;

void input(){
	scanf("%d%d", &n, &m);
}



int main(){
	input();
	
	if(m == 1 && n == 1){
		printf("%.12lf\n", 1.0);
		return 0;
	}
	
	double res = (m-1)*(n-1);
	res /= (m*n-1);
	res += 1;
	res /= n;
	
	printf("%.12lf\n", res);
	
	return 0;
}