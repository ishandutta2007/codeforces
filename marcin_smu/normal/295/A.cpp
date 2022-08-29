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
#define make(A) scanf("%d",&A);
#define makel(A) scanf("%I64d",&A);
#define pll(A) printf("%I64d ",A);
#define MAX 100001
int n,m,k,l[MAX],r[MAX],d[MAX];
LL a[MAX],b[MAX],in[MAX];
void dod1(int nr,LL il){
	for(;nr;nr-=(nr&-nr))
		a[nr]+=il;
}
LL sum1(int nr){
	LL wyn=0;
	for(;nr<=m;nr+=(nr&-nr))
	  wyn+=a[nr];
  return wyn;
}
void dod2(int nr,LL il){
	for(;nr;nr-=(nr&-nr))
		b[nr]+=il;
}
LL sum2(int nr){
	LL wyn=0;
	for(;nr<=n;nr+=(nr&-nr))
	  wyn+=b[nr];
  return wyn;
}
main(){
	make(n);
	make(m);
	make(k);
	R(i,n)make(in[i]);
	R(i,m){
		make(l[i]);
		make(r[i]);
		make(d[i]);
	}
	R(i,k){
	  int x, y;
	  make(x);
	  make(y);
	  dod1(x-1,-1);
	  dod1(y,1);
	}
	R(i,m){
		LL pom=sum1(i+1)*d[i];
		dod2(l[i]-1,-pom);
		dod2(r[i],pom);
	}
	R(i,n){
		pll(sum2(i+1)+in[i]);
	}
	printf("\n");
}