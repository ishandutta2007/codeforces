#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[101], chk[101], cnt[2], dp[101][101][101][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) chk[a[i]] = 1;
	for(int i=1;i<=n;i++) if(!chk[i]) cnt[i%2]++;
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) dp[i][j][k][0] = dp[i][j][k][1] = 1e9;
	dp[0][cnt[0]][cnt[1]][0] = dp[0][cnt[0]][cnt[1]][1] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=cnt[0];j++){
			for(int k=0;k<=cnt[1];k++){
				if(a[i]){
					dp[i][j][k][a[i]%2] = min(dp[i-1][j][k][1-a[i]%2]+1, dp[i-1][j][k][a[i]%2]);
				}else{
					dp[i][j][k][0] = min(dp[i-1][j+1][k][0], dp[i-1][j+1][k][1]+1);
					dp[i][j][k][1] = min(dp[i-1][j][k+1][0]+1, dp[i-1][j][k+1][1]);
				}
			}
		}
	}
	printf("%d",min(dp[n][0][0][0],dp[n][0][0][1]));
}