#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
typedef int LL;
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
#define MAX 1010
#define RO(a,aa) for(int a=aa;a;a-=(a&-a))
#define RX(a,aa) for(int a=aa;a<MAX;a+=(a&-a))
LL dp1[MAX][MAX],dp2[MAX][MAX],dp3[MAX][MAX],dp4[MAX][MAX],war;
void add1(int xx,int yy){RO(x,xx)RO(y,yy)dp1[x][y]^=war;}
void add2(int xx,int yy){RO(x,xx)RX(y,yy)dp2[x][y]^=war;}
void add3(int xx,int yy){RX(x,xx)RO(y,yy)dp3[x][y]^=war;}
void add4(int xx,int yy){RX(x,xx)RX(y,yy)dp4[x][y]^=war;}
LL sum1(int xx,int yy){LL wyn=0;RX(x,xx)RX(y,yy)wyn^=dp1[x][y];return wyn;}
LL sum2(int xx,int yy){LL wyn=0;RX(x,xx)RO(y,yy)wyn^=dp2[x][y];return wyn;}
LL sum3(int xx,int yy){LL wyn=0;RO(x,xx)RX(y,yy)wyn^=dp3[x][y];return wyn;}
LL sum4(int xx,int yy){LL wyn=0;RO(x,xx)RO(y,yy)wyn^=dp4[x][y];return wyn;}
void addd(int x,int y){
	add1(x,y);
	if(y&1)add2(x,y);
	if(x&1)add3(x,y);
	if(y&x&1)add4(x,y);
}
LL summ(int x,int y){
	LL wyn=0;
	if(x&y&1)wyn^=sum1(x+1,y+1);
	if(x&1)wyn^=sum2(x+1,y);
	if(y&1)wyn^=sum3(x,y+1);
	wyn^=sum4(x,y);
	return wyn;
}
void add(int x1,int y1,int x2,int y2){addd(x2,y2);addd(x2,y1);addd(x1,y2);addd(x1,y1);}
LL sum(int x1,int y1,int x2,int y2){return summ(x2,y2)^summ(x1,y2)^summ(x2,y1)^summ(x1,y1);}
int q;
int main(){
	scanf("%*d%d",&q);
	while(q--){
		int z,a,b,c,d;
		scanf("%d%d%d%d%d",&z,&a,&b,&c,&d);
		if(z==1)
			printf("%d\n",sum(a,b,c+1,d+1));
		else{
			makel(war);
			add(a,b,c+1,d+1);
		}
	}
}