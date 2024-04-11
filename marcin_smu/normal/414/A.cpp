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
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld ",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
#endif
int n,k;
main(){
	make(n);make(k);
	if(n==1){
		if(k == 0)
			puts("42");
		else 
			puts("-1");
	}else{
		if(n/2 > k){
			puts("-1");
		}else{
			k-=n/2-1;
			printf("%d %d",k,k*2);
			R(i,n-2)printf(" %d",k*2+i+1);
			puts("");
		}
	}
}