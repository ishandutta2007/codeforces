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
#define MAX 1001
int n,m,t[MAX][MAX],k,p;
LL tw[MAX*MAX];
priority_queue<LL> wie,kol;
main(){
	make(n);make(m);make(k);make(p);
	R(i,n)R(j,m)
		make(t[i][j]);
	R(i,n){
		LL sum = 0;
		R(j,m)sum += t[i][j];
		wie.push(sum);
	}
	R(j,m){
		LL sum = 0;
		R(i,n)sum += t[i][j];
		kol.push(sum);
	}
	LL sum = 0;
	R(i,k){
		tw[i] = wie.top();
		sum += tw[i];
		wie.pop();
		wie.push(tw[i] - m*p);
	}
	LL wyn = sum;
	R(i,k){
		LL pom = kol.top();
		kol.pop();
		kol.push(pom - n*p);
		sum += pom;
		sum -= tw[k-i-1];
		LL wyn2 = sum - LL(p) * (i+1) * (k-i-1); 
		if(wyn < wyn2)wyn = wyn2;
	}
	pll(wyn);
	puts("");
}