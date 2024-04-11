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



int n, k;
int tab[200];

void input(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &tab[i]);
	}
}

int out[200], in[200];

int find(int L, int R){
	copy(tab+L, tab+R+1, in);
	int sizin=R-L+1;
	
	sort(in, in+sizin);
	
	copy(tab, tab+L, out);
	copy(tab+R+1, tab+n, out+L);
	int sizout = L+(n-R-1);
	sort(out, out+sizout);
	
	int sumin = 0;
	for(int i = 0; i < sizin; i++)
		sumin += in[i];
		
	for(int i = 0; i < k; i++){
		if(i < sizin && i < sizout && in[i] < out[sizout-i-1])
			sumin += out[sizout-i-1]-in[i];
	}
	//printf("L=%d R=%d s=%d\n", L, R, sumin);
	return sumin;
}

int main(){
	input();
	int best = -1000000;
	for(int L = 0; L < n; L++){
		for(int R = L; R < n; R++){
			best = max(best, find(L,R));
		}
	}
	printf("%d\n", best);
	
	return 0;
}