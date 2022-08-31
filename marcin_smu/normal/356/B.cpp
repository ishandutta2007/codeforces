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
#define MAX 1000010
LL n,m;
char t1[MAX],t2[MAX];
LL nwd(LL a,LL b){
	while(b){
		LL pom = b;
		b = a%b;
		a = pom;
	}
	return a;
}
int il[MAX][50];
main(){
	makel(n);
	makel(m);
	scanf(" %s %s",t1,t2);
	int d1=0,d2=0;
	while(t1[d1])d1++;
	while(t2[d2])d2++;
	int pom = nwd(d1,d2);
	R(i,d1)il[i%pom][t1[i]-'a'] ++;
	LL wyn=0;
	R(i,d2)
		wyn+=il[i%pom][t2[i]-'a'];
	wyn *= nwd(n,m);
	pll(n*d1 - wyn);
}