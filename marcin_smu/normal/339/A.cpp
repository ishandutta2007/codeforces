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
#define MAX 101
char z[MAX];
int il[4];
main(){
	scanf(" %s",z);
	int n=0;
	while(z[n]){
		if(z[n]!='+')
			il[z[n]-'0']++;
		n++;
	}
	int i=0;
	R(j,4){
		while(il[j]--){
			z[i*2]=j+'0';
			i++;
		}
	}
	printf("%s\n",z);
	
}