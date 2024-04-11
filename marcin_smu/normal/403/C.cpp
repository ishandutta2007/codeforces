#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
#define MAX 2010
int n;
bool cz[2][MAX];
vector<int> d[2][MAX];
int gl;
int dfs(int nr){
	if(cz[gl][nr])return 0;
	cz[gl][nr] = 1;
	int ret = 1;
	R(i,d[gl][nr].size())
		ret += dfs(d[gl][nr][i]);
	return ret;
}
main(){
	make(n);
	R(i,n)R(j,n){
		int pom;make(pom);
		if(i!=j && pom > 0){
			d[0][i].PB(j);
			d[1][j].PB(i);
		}
	}
	R(i,2){
		gl = i;
		if(dfs(0)!=n){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}