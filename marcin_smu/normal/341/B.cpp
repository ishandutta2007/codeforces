#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
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
int n;
vector<int> wyn;
main(){
	make(n);
	int pom;
	make(pom);
	wyn.PB(pom);
	R(i,n-1){
		make(pom);
		if(pom > wyn[wyn.size()-1]){
			wyn.PB(pom);
			continue;
		}
		int po=-1,ko=wyn.size()-1;
		while(po+1 != ko){
			int m = (po + ko) /2;
			if(wyn[m] < pom)
				po = m;
			else
				ko = m;
		}
		wyn[ko] = pom;
	}
	printf("%d\n",wyn.size());
}