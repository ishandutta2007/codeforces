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
int n,il[5],t[5];
main(){
	make(n);
	R(i,n){
		int pom;
		make(pom);
		il[pom]++;
	}
	int all=0;
	R(i,5)all += il[i]*i;
	if(all < 3 || all == 5){
		printf("-1\n");
		return 0;
	}
	int wyn = all;
	R(i,n+1){
		if(i*3 > all || i*4 < all)continue;
		int il4 = all - i*3;
		int il3 = i - il4;
		int pom1 = 0, pom2 = 0;
		R(i,5)t[i] = il[i];
		FD(i,5){
			int a = min(t[i],il4);
			pom1 += a*(4-i);
			t[i] -= a;
			il4 -= a;
			
			a = min(t[i],il3);
			if(i==4)
				pom2 += a;
			else
				pom1 += a*(3-i);
			t[i] -= a;
			il3 -= a;
			
		}
		if(il3 == 0 && il4 == 0){
			int pom = max(pom1,pom2);
			if(pom<wyn)wyn = pom;
		}
	}
	printf("%d\n",wyn);
}