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
#define MAX 110
char z[MAX],z2[MAX],v[MAX],out[MAX];
int n,n2,n3,dp[MAX][MAX][MAX],pop[MAX][MAX][MAX],kmp[MAX],xx[MAX];
void ma(int &a,int b){a=max(a,b);}
main(){
	scanf(" %s %s %s",z,z2,v);
	int t=0;
	for(int i=1;v[i];i++){
		while(t!=0 && v[i]!=v[t]) t = kmp[t-1];
		if(v[i]==v[t])t++;
		kmp[i] = t;
	}
	for(int i=0;z[i];i++){
		for(int k=0;v[k];k++){
			int pom = k;
			while(pom !=0 && z[i]!=v[pom]) pom = kmp[pom-1];
			if(z[i] == v[pom] )pom++;
			xx[k] = pom;
			//printf("%d\n",pom);
		}
		for(int j=0;z2[j];j++){
			for(int k=0;v[k];k++){
				if(dp[i][j+1][k] >= dp[i+1][j+1][k]){
					dp[i+1][j+1][k] = dp[i][j+1][k];
					pop[i+1][j+1][k] = -1;
				}
				if(dp[i+1][j][k] >= dp[i+1][j+1][k]){
					dp[i+1][j+1][k] = dp[i+1][j][k];
					pop[i+1][j+1][k] = -2;
				}
				if(z[i]==z2[j]){
					if(v[xx[k]]){
				//		printf("xD %d %d %d %d\n",i,j,k,xx[k]);
						if(dp[i+1][j+1][xx[k]] < dp[i][j][k]+1){
							dp[i+1][j+1][xx[k]] = dp[i][j][k]+1;
				//			printf("%d!!!!\n",dp[i+1][j+1][xx[k]]);
							pop[i+1][j+1][xx[k]] = k;
						}
					}
				}
			}
		}
	}
	int wyn=-1;
	int n=0;while(z[n])n++;
	int n2=0;while(z2[n2])n2++;
	int kk=-1;
//	R(i,n+1)R(j,n2+1)for(int k=0;v[k];k++){
//		printf("%d %d %d (%d)\n",i,j,k,dp[i][j][k]);
//	}
	for(int k=0;v[k];k++){
		R(i,n+1){
			if(wyn < dp[i][n2][k]){
				wyn = dp[i][n2][k];
				kk=k;
			}
		}
		R(j,n2){
			if(wyn < dp[n][j][k]){
				wyn = dp[n][j][k];
				kk=k;
			}
		}
	}
	if(wyn == 0){
		printf("0\n");
		return 0;
	}
	out[wyn]=0;
	int i=n,j=n2,k=kk;
	while(i!=0&& j!=0){
		if(pop[i][j][k]<0){
			if(pop[i][j][k]==-1)
				i--;
			else
				j--;
		}else{
			wyn--;
			k = pop[i][j][k];
			i--;
			j--;
			out[wyn] = z[i];
		}
	}
	printf("%s\n",out);
}