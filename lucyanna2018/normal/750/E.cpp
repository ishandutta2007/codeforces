#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define inf 1000000000
int n,q;
char s[222222];
int dp[200002][18][15];
int dd[15],dd2[15];
const int dx[5]={0,5,9,12,14};
const int di[4]={'2','0','1','7'};
void upd(int&x,int y){
	if(x>y)x=y;
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++){
		for(int j=0; j<15; j++)
			dp[i][0][j] = inf;

		for(int j=0; j<4; j++){
			if(s[i] == di[j]){
				dp[i][0][dx[j]+1] = 0;
				dp[i][0][dx[j]] = 1;
			}else
				dp[i][0][dx[j]] = 0;
		}
		if(s[i] == '6'){
			dp[i][0][dx[3]] = 1;
			dp[i][0][dx[4]] = 1;
		}else
			dp[i][0][dx[4]] = 0;
	}

	for(int k=1; (1<<k) <= n; k++)
		for(int i=1; i+(1<<k)-1 <= n; i++){
			for(int j=0; j<15; j++)
				dp[i][k][j] = inf;
			for(int A = 0; A < 5; A++)
				for(int B = A; B < 5; B++)
					for(int C = B; C < 5; C++)
						upd(dp[i][k][dx[A]+C-A],
						dp[i][k-1][dx[A]+B-A] + dp[i+(1<<(k-1))][k-1][dx[B]+C-B]);
		}

	while(q--){
		int l,r,k;
		scanf("%d%d",&l,&r);
		for(int j=0; j<15; j++)
			dd[j] = inf;
		dd[0] = 0;
		for(k=0; l+(1<<k)-1 <= r; k++);
		for(--k; k>=0; k--)if(l+(1<<k)-1 <= r){
			for(int j=0; j<15; j++)
				dd2[j] = inf;
			for(int A = 0; A < 5; A++)
				for(int B = A; B < 5; B++)
					for(int C = B; C < 5; C++)
						upd(dd2[dx[A]+C-A],
						dd[dx[A]+B-A] + dp[l][k][dx[B]+C-B]);
			l += (1<<k);
			for(int j=0; j<15; j++)
				dd[j] = dd2[j];
		}
		int res = dd[4];
		if(res == inf)puts("-1");else
			printf("%d\n",res);
	}
	return 0;
}