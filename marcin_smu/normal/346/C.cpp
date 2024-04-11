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
#define MAX 1001000
int n,x[MAX],a,b,r,d[MAX],naj;
void rob(int nr){
	while(r!=nr){
		int pom = r-d[r];
		if(pom >= 0 && pom < naj)naj=pom;
		r--;
	}
}
main(){
	make(n);
	R(i,n)make(x[i]);
	sort(x,x+n);
	make(a);make(b);
	r=a-b;
	naj = r-1;
	R(i,n){
		if(i==0 || x[i-1] != x[i]){
			int pom = b%x[i];
			if(pom!=0)pom =  x[i] - pom;
			while(pom <= r){
				if(pom - x[i] >= 0) d[pom] = x[i];
				pom+=x[i];
			}
			pom -= x[i];
			if(pom >= 0){
				if(naj > pom)naj = pom;
			}
		}
	}
	int wyn=0;
	while(r!=0){
		rob(naj);
		if(naj==r)naj = r-1;
		wyn++;
	}
	printf("%d\n",wyn);
}