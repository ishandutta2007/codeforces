#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
const int INF=1e4;
int n;
int p[N];
int c[2]={0};
int dp[N][N][N][2];
int main(){
	scanf("%d",&n);
	c[0]=n/2;
	c[1]=(n+1)/2;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]!=0){
			c[p[i]%2]--;
			p[i]%=2;
		}
		else{
			p[i]=-1;
		}
	}
	for(int i=n;i>=1;i--){
		for(int c0=0;c0<=n;c0++){
			for(int c1=0;c1<=n;c1++){
				for(int l=0;l<2;l++){
					int &ans=dp[i][c0][c1][l];
					ans=INF;
					if(p[i]!=-1){
						ans=dp[i+1][c0][c1][p[i]]+(i==1||p[i]==l?0:1);
					}
					else{
						if(c0>0){
							ans=min(ans,dp[i+1][c0-1][c1][0]+(i==1||l==0?0:1));
						}
						if(c1>0){
							ans=min(ans,dp[i+1][c0][c1-1][1]+(i==1||l==1?0:1));
						}
					}
				}
			}
		}
	}
	printf("%d\n",dp[1][c[0]][c[1]][0]);
	return 0;
}