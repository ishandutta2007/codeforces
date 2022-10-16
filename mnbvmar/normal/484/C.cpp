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


const int MaxN = 1000005;

char str[MaxN], nstr[MaxN];
int N, M;

void input(){
	scanf("%s%d", str, &M);
	N = strlen(str);
}


int perm[MaxN*2];
int nperm[MaxN*2];
bool vis[MaxN*2];


void power(int pwr){
	fill(vis, vis+2*N, false);
	for(int i = 0; i < 2*N; i++){
		if(vis[i]) continue;

		vector<int> cyc;
		int v = i;
		do {
			vis[v] = true;
		//	printf("%d\n", v);
			cyc.push_back(v);
			v = perm[v];
		} while(v != i);

		int jump = pwr % cyc.size();

		int ptr2 = i;
		while(jump--) ptr2 = perm[ptr2];

		for(int i = 0; i < cyc.size(); i++){
			nperm[cyc[i]] = ptr2;
			ptr2 = perm[ptr2];
		}
	}
	copy(nperm, nperm+2*N, perm);
}

void first_perm(){
	for(int i = 1; i < 2*N; i++)
		perm[i] = i-1;
	perm[0] = 2*N-1;
}

int main(){
	input();
	while(M--){
		int k, d;
		scanf("%d%d", &k, &d);
		first_perm();
	
	//	printf("z\n");	
		int ptr = N-1;
		for(int i = 0; i < d; i++){
			for(int j = i; j < k; j += d){
				perm[N+j] = ptr++;
			}
		}
	//	for(int i = 0; i < 2*N; i++) printf("%d -> %d\n", i, perm[i]);
	//	printf("y\n");

		power(N-k+1);
		int incr = k-1;
	//	for(int i = 0; i < 2*N; i++)
	//		printf("%d -> %d\n", i, perm[i]);

		for(int i = 0; i < N; i++){
			nstr[perm[N+i]-incr] = str[i];
		}
		copy(nstr, nstr+N, str);
		printf("%s\n", str);
	}
}