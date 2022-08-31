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
#define make(A) scanf("%d",&A);
#define makel(A) scanf("%I64d",&A);
#define pll(A) printf("%I64d ",A);
#define MAX 501
int n,d[MAX][MAX],u[MAX];
LL wynik[MAX];
main(){
	make(n);
	R(i,n)R(j,n)
		make(d[i][j]);
	R(i,n){
	  make(u[i]);
	  u[i]--;
	}
	LL wyn=0;
	FD(i,n){
		int a=u[i];
		F(j,i+1,n)F(k,i+1,n){
			int b=u[j],c=u[k];
			if(d[a][b]>d[a][c]+d[c][b])
			d[a][b]=d[a][c]+d[c][b];
			if(d[b][a]>d[b][c]+d[c][a])
			d[b][a]=d[b][c]+d[c][a];
		}
		F(j,i+1,n)wyn+=d[a][u[j]]+d[u[j]][a];
		F(j,i+1,n)F(k,i+1,n){
			int b=u[j],c=u[k];
			if(d[b][c]>d[b][a]+d[a][c]){
				wyn-=d[b][c];
				d[b][c]=d[b][a]+d[a][c];
			  wyn+=d[b][c];
		  }
		}
		wynik[i]=wyn;
	}
	R(i,n)pll(wynik[i]);
}