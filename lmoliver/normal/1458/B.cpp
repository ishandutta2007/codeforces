#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=105;
int dp[N][N*N];
int a[N],b[N];
int main(){
	int n=read();
	F(i,1,n){
		a[i]=read();
		b[i]=read();
	}
	int tot=0;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	F(i,1,n){
		R(j,i-1,0){
			F(k,0,tot)if(dp[j][k]>=0){
				int &v=dp[j+1][k+b[i]];
				v=max(v,dp[j][k]+a[i]);
			}
		}
		tot+=b[i];
	}
	F(i,1,n){
		int ans=0;
		F(j,0,tot){
			ans=max(ans,min(tot+j,dp[i][j]*2));
		}
		printf("%d.%d ",ans/2,ans%2*5);
	}
	printf("\n");
	//dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
	return 0;
}