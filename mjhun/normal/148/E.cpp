#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int len[128];
int psum[128][128];
int mt[128][128];
int sh[128][128];
int dp[10005][105];

int main(){
	int n,m,i,j,k,s,r;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",len+i);
		for(j=1;j<=len[i];++j){
			scanf("%d",&(sh[i][j]));
		}
	}
	for(i=1;i<=n;++i){
		s=0;
		for(j=1;j<=len[i];++j){
			s+=sh[i][j];
			psum[i][j]=s;
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=len[i];++j){
			r=-1;
			for(k=0;k<=j;++k){
				r=max(r,psum[i][k]+psum[i][len[i]]-psum[i][len[i]-j+k]);
			}
			mt[i][j]=r;
		}
	}
	//COMENTAR:
	for(i=0;i<=m;++i){
		dp[i][0]=0;
	}
	for(j=0;j<=n;++j){
		dp[0][j]=0;
	}
	
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j){
			r=dp[i][j-1];
			for(k=1;k<=len[j]&&k<=i;++k){
				r=max(r,mt[j][k]+dp[i-k][j-1]);
			}
			dp[i][j]=r;
		}
	}
	
	printf("%d\n",dp[m][n]);
	
	return 0;
}