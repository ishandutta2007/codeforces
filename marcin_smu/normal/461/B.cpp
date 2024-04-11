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
#define MAX 100100
const int P = 1e9 + 7;
int n,kol[MAX],wyn[MAX],wyn2[MAX];
vector<int> d[MAX];
void dfs(int nr,int oj){
	wyn[nr] = 1;
	wyn2[nr] = 0;
	R(i,d[nr].size())
		if(d[nr][i] != oj){
			dfs(d[nr][i], nr);
			wyn2[nr] = (LL)wyn2[nr] * (wyn[d[nr][i]]+wyn2[d[nr][i]]) % P;
			wyn2[nr] += (LL)wyn[nr] * wyn2[d[nr][i]] % P;
			wyn2[nr] %= P;
			wyn[nr] = (LL)wyn[nr] * (wyn[d[nr][i]]+wyn2[d[nr][i]]) % P;
			
		}
	if(kol[nr] == 1){
		wyn2[nr] = wyn[nr];
		wyn[nr] = 0;
	}
}
main(){
	make(n);
	R(i,n-1){
		int pom;make(pom);
		d[i+1].PB(pom);
		d[pom].PB(i+1);
	}
	R(i,n)make(kol[i]);
	R(i,n){
		if(kol[i] == 1){
			dfs(i,-1);
			printf("%d\n",wyn2[i]);
			return 0;
		}
	}
	puts("0");
}