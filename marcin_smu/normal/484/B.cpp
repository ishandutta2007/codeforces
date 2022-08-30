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
#define MAX 2000100
int n,t[MAX],pm[MAX];
int wyn = 0;
int spr(int a){
	for(int i=2;i*a < MAX;i++){
// 		int po = 0,ko = n;
// 		while(po+1!=ko){
// 			int m = po+ko>>1;
// 			if(t[m] < i*a)
// 				po = m;
// 			else
// 				ko = m;
// 		}
		int pom = pm[i*a-1] - (i-1)*a; 
		if(pom > wyn)
			wyn = pom;
	}
}
main(){
	make(n);
	R(i,n){
		make(t[i]);
		pm[t[i]] = t[i];
	}
	R(i,MAX){
		if(i && pm[i] == 0)
			pm[i] = pm[i-1];
	}
	sort(t,t+n);
	R(i,n){
		if(!i || t[i]!=t[i-1]){
			spr(t[i]);
		}
	}
	printf("%d\n",wyn);
}