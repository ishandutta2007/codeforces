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
#define MAX 501
int n,m,k,il;
char z[MAX][MAX];
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
void dfs(int i,int j){
	if(i>=0 && i<n && j>=0 && j<m){
		if(z[i][j] == 'X' && il){
			il--;
			z[i][j]='.';
			R(k,4)dfs(i+xx[k],j+yy[k]);
		}
	}
}
main(){
	make(n);make(m);make(k);
	R(i,n){
		scanf("%s",z[i]);
		R(j,m){
			if(z[i][j]=='.'){
				il++;
				z[i][j]='X';
			}
		}
	}
	il -= k;
	R(i,n)R(j,m){
		if(z[i][j] == 'X'){
			dfs(i,j);
			R(k,n)
				printf("%s\n",z[k]);
			return 0;
		}
	}
}