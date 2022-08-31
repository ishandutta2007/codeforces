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
int nwd(int a,int b){
	while(b){
		int pom = b;
		b = a%b;
		a=pom;
	}
	return a;
}
int n,naj,q;
main(){
	make(n);
	make(naj);
	q=naj;
	R(i,n-1){
		int pom;
		make(pom);
		if(pom > naj)naj=pom;
		q=nwd(q,pom);
	}
	printf("%s\n",(naj/q-n)%2?"Alice":"Bob");
	
}