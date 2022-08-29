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
#define make(A) scanf("%d",&A)
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
vector<LL> wyn;
LL n;
bool licz(int i,LL m){
	return m*(m-1)/2 + ((1ll<<i)-1)* m < n;
}
bool licz2(int i,LL m){
	return m*(m-1)/2 + ((1ll<<i)-1)* m == n;
}
main(){
	makel(n);
	for(int i=0;i<62;i++){
		LL p=0;
		LL k= (i==0 ? LL(sqrt(n*3.)) : min(LL(sqrt(n*3.)), n/((1ll<<i)-1)) );
		while(p+1<k){
			LL m = (p+k)/2;
			if(licz(i,m))
				p=m;
			else
				k=m;
		}
		if(licz2(i,k)&& (k&1)){
			wyn.PB(k*(1ll<<i));
		}
	}
	if(wyn.size()==0)
		printf("-1\n");
	else
		R(i,wyn.size())
		pll(wyn[i]);
}