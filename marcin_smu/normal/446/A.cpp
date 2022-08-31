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
#define MAX 100001
int n,a[MAX],t[MAX],t2[MAX];
main(){
	make(n);
	R(i,n)make(a[i]);
	t[0] = 1;
	int wyn = 1;
	F(i,1,n){
		if(a[i] > a[i-1])
			t[i] = t[i-1]+1;
		else
			t[i] = 1;
		if(t[i]+1 > wyn)wyn = t[i]+1;
	}
	t2[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		if(a[i] < a[i+1])
			t2[i] = t2[i+1]+1;
		else
			t2[i] = 1;
	}
	F(i,1,n-1){
		if(a[i-1] + 1 < a[i+1])
			wyn = max(wyn, t[i-1]+1+t2[i+1]);
	}
	printf("%d\n",min(wyn,n));
}