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
//#define pll(A) printf("%I64d\n",A)
//#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld\n",A)
#define MAX 100001
int n,x[MAX],y[MAX],p[MAX],cz1[MAX],cz2[MAX],typ[MAX],p1[MAX],p2[MAX];
bool qx(int a,int b){
	return x[a]<x[b];
}
bool qy(int a,int b){
	return y[a]<y[b];
}
LL wyn=0;
main(){
	make(n);
	R(i,n){
		make(x[i]);
		make(y[i]);
		p1[i]=i;
		p2[i]=i;
	}
	sort(p1,p1+n,qx);
	sort(p2,p2+n,qy);
	int czt1=0,czt2=0;
	R(i,n-1){
		wyn +=  LL(x[p1[i+1]] - x[p1[i]]) * 2 * min(i+1,n-i-1);
		wyn +=  LL(y[p2[i+1]] - y[p2[i]]) * 2 * min(i+1,n-i-1);
	}
	if(n&1 && p1[n/2] != p2[n/2]){
		pll(wyn);
		return 0;
	}
	R(i,n/2){
		cz1[p1[i]]=1;
		cz1[p2[i]]=1;
		cz2[p1[n-i-1]]=1;
		cz2[p2[n-i-1]]=1;
	}
	R(i,n){
		if((n&1)==0 || i!=p1[n/2])
		if(cz1[i]&&cz2[i]){
			typ[i]=1;
			czt1=1;
		}else{
			typ[i]=2;
			czt2=1;
		}
	}
	if(czt1==0 || czt2==0){
		pll(wyn);
		return 0;
	}
	sort(x,x+n);
	sort(y,y+n);
	if(n&1){
		pll(wyn - 2* min(
			min(x[n/2] - x[n/2-1],y[n/2] - y[n/2-1]),
			min(x[n/2+1] - x[n/2],y[n/2+1] - y[n/2])
		));
		return 0;
	}
	pll(wyn - 2* min(x[n/2] - x[n/2-1],y[n/2] - y[n/2-1]));
}