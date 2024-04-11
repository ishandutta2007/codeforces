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
int n,mx,dx,my,dy;
main(){
	make(n);
	mx=100000;
	my=100000;
	dx=-1;
	dy=-1;
	LL p=0;
	while(n--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a<mx)mx=a;
		if(c>dx)dx=c;
		if(b<my)my=b;
		if(d>dy)dy=d;
		p+= (c-a) *LL(d-b);
	}
	if(p == (dx-mx) * LL(dx-mx) && (dx-mx)==(dy-my))
		printf("YES\n");
	else
		printf("NO\n");
}