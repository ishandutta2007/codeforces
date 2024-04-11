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
#define MAX 2001
const int P=1000*1000*1000+7;
int n,m;
LL d[MAX][MAX];
main(){
	make(n);make(m);
	F(j,2,m+1)d[0][j]=1;//m-j+1;
	F(i,1,n){
		LL sum=0;
		d[i][1]=1;
	  F(j,2,m+1){
			sum+=d[i-1][j];
			if(sum>P)sum-=P;
			d[i][j]=d[i][j-1]+sum;
			if(d[i][j]>P)
			d[i][j]-=P;
	  }
	}
	LL wyn=0;
	R(i,n)F(j,2,m+1){
		if(i!=n-1)
	  	wyn+=d[i][j]*(d[n-i-1][j]-d[n-i-2][j])%P*(m-j+1)%P;
	  else
	  	wyn+=d[i][j]*d[n-i-1][j]%P*(m-j+1)%P;
	  if(wyn>P)wyn-=P;
	}
	printf("%d\n",int(wyn));
}