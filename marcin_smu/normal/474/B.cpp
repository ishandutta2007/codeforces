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
#define MAX 100001
int n,m,a[MAX];
main(){
	make(n);
	R(i,n){
		make(a[i]);
		if(i)a[i] += a[i-1];
	}
	make(m);
	while(m--){
		int pom;make(pom);
		int po = -1;
		int ko = n-1;
		while(po+1!=ko){
			int m = po + ko >> 1;
			if(a[m] < pom)
				po = m;
			else
				ko = m;
		}
		printf("%d\n",ko+1);
	}
}