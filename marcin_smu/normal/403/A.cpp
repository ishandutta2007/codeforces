#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define MAX 50
int n,p,t[MAX][MAX];
void add(int i,int j){
	t[i][j]=1;
	t[j][i]=1;
}
void test(){
	make(n);
	make(p);
	R(i,n)R(j,n)t[i][j] = 0;
	R(i,n){
		add(i,(i+1)%n);
		add(i,(i+2)%n);
	}
	R(i,n)R(j,n){
		if(t[i][j]==0 && p>0 && i!=j){
			p--;
			add(i,j);
		}
		if(t[i][j]==1 && i<j)
			printf("%d %d\n",i+1,j+1);
	}
}
main(){
	int _;make(_);while(_--)test();
}