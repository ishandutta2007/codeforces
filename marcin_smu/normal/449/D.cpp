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
#define MAX 1400001
int n;
const int m = 20;
const int P = 1e9+7;
int p2[MAX],t[MAX];
main(){
	make(n);
	p2[0] = 1;
	R(i,n)p2[i+1] = (p2[i]*2)%P;
	R(i,n){
		int pom;
		make(pom);
		t[((1<<m)-1) ^ pom]++;
	}
	R(i,m)R(j,(1<<m))if(j&(1<<i))t[j]+=t[j-(1<<i)];
//	int wyn = p2[n];
	int wyn = 0;
	R(i,(1<<m)){
		bool zn = (__builtin_popcount(i))&1;
		wyn += (zn?-1:1) * p2[t[i]];
		wyn%=P;
	}
	printf("%d\n",(wyn%P+P)%P);
}