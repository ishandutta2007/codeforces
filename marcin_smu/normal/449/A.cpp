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
int n,m,k;
LL wyn = -1;
void spr(int a){
	LL b = k-a;
	if(a<1 || a>n || b<1 || b > m)return;
	LL pom = (n/a) * LL(m/b);
	if(pom > wyn)wyn = pom;
}
main(){
	make(n);make(m);make(k);
	k+=2;
	spr(1);spr(n);
	spr(k-m);spr(k-1);
	pll(wyn);
}