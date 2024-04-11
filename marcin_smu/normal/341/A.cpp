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
#define MAX 100001
int n,t[MAX];
LL nwd(LL a,LL b){
	while(b){
		LL pom=b;
		b=a%b;
		a=pom;
	}
	return a;
}
main(){
	make(n);
	R(i,n)make(t[i]);
	sort(t,t+n);
	LL wyn=0;
	R(i,n){
		int pom =0;
		pom += (i+1)- (n-i-1);
		pom += i - (n-i-1);
		wyn += pom * LL(t[i]);
	}
	LL pom = nwd(wyn,n);
	pll(wyn/pom);
	pll(n/pom);
}