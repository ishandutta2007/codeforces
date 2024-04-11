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
int n;
int il[MAX];
int p[MAX];
vector<int> d[MAX];
vector<PI> wyn;
main(){
	make(n);
	F(i,2,n+1){
		if(p[i] == 0){
			for(int j=1;j*i<=n;j++){
				if(p[i*j] == 0){
					p[i*j] = i;
					il[i]++;
				}
			}
		}
	}
	F(i,3,n+1){
		if((il[i]&1))
			if(2*i <= n)p[2*i] = i;
	}
	F(i,2,n+1)d[p[i]].PB(i);
	R(i,n+1){
		R(j,d[i].size()/2)
			wyn.PB(MP(d[i][2*j],d[i][2*j+1]));
	}
	printf("%d\n",wyn.size());
	R(i,wyn.size())
		printf("%d %d\n",wyn[i].FI,wyn[i].SE);
}