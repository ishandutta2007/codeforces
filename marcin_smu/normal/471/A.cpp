#include<bits/stdc++.h>
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
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
int t[10];
main(){
	R(i,6){
		int pom;
		make(pom);
		t[pom]++;
	}
	bool cz4=0,cz2=0;
	R(i,10){
		if(t[i] == 4)cz4 = 1;
		if(t[i] == 2)cz2 = 1;
		if(t[i] == 5)cz4 = 1;
		if(t[i] == 6){
			cz4 = 1;
			cz2 = 1;
		}
	}
	if(!cz4){
		puts("Alien");
	}else{
		puts(cz2?"Elephant":"Bear");
	}
}