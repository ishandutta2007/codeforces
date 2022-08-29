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
#define MAX 100001
int n,f[MAX],nast[MAX];
int find(int i){
	return f[i]==i?i:f[i]=find(f[i]);
}
void uni(int a,int b){
	f[find(a)]=find(b);
}
main(){
	make(n);
	if(n&1){
		printf("-1\n");
		return 0;
	}
	R(i,n)f[i]=i;
	R(i,n/2){
		nast[i] = i*2%n;
		uni(i,i*2%n);
		nast[n/2+i] = (i*2+1)%n;
		uni(n/2+i,(i*2+1)%n);
	}
	R(i,n/2){
		if(find(i)!=find(n/2+i)){
			nast[i] = (i*2+1)%n;
			nast[n/2+i] = i*2%n;
			uni(i,n/2+i);
		}
	}
	printf("0 ");
	int ak=0;
	do{
		ak=nast[ak];
		printf("%d ",ak);
	}while(ak!=0);
	printf("\n");
}