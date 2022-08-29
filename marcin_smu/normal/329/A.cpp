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
int n,ilx,ily;
char z[MAX][MAX];
bool czx[MAX],czy[MAX];
main(){
	make(n);
	R(i,n){
		scanf(" %s",z[i]);
		R(j,n){
			if(z[i][j]=='.'){
				if(czy[j]==0){
					czy[j]=1;
					ily++;
				}
				if(czx[i]==0){
					czx[i]=1;
					ilx++;
				}
			}
		}
	}
	if(ilx==n){
		R(i,n)R(j,n){
			if(z[i][j]=='.'){
				printf("%d %d\n",i+1,j+1);
				break;
			}
		}
		return 0;
	}
	if(ily==n){
		R(j,n)R(i,n){
			if(z[i][j]=='.'){
				printf("%d %d\n",i+1,j+1);
				break;
			}
		}
		return 0;
	}
	printf("-1\n");
}