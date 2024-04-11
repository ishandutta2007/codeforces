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
#define MAX 100010
int n,m;
LL t[MAX],t2[MAX];
LL spr(int i,int j,int k){
	return t2[k]-t2[j] + min(abs(t2[j]-t[i]),abs(t2[k]-t[i]));
}
bool licz(LL il){
	int j=0;
	R(i,n){
		int k=j;
		while(spr(i,j,k) <= il && k<m) k++;
		j=k;
	}
	return j==m;
}
main(){
	make(n);make(m);
	R(i,n)makel(t[i]);
	R(i,m)makel(t2[i]);
	LL p=-1,k=1000ll * 1000 * 1000 * 30;
	while(p+1!=k){
		LL me=(p+k)/2;
		if(licz(me))
			k=me;
		else
			p=me;
	}
	pll(k);
}