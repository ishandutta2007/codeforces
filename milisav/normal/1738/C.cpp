#include<bits/stdc++.h>
#define maxn 200
using namespace std;
int dp[maxn][maxn][2][2];
int t;
int n;
int a[maxn];
void precalc() {
    dp[0][0][0][0]=dp[0][0][1][0]=1;
    /*for(int i=1;i<maxn;i++) {
        dp[i][0][0][0]=dp[i][0][1][0]=1;
        dp[0][i][0][0]=dp[0][i][1][0]=((i/2)%2);
    }*/
    dp[0][0][0][1]=dp[0][0][1][1]=0;
    /*for(int i=1;i<maxn;i++) {
        dp[i][0][0][1]=dp[i][0][1][1]=0;
        dp[0][i][0][1]=dp[0][i][1][1]=1-((i/2)%2);
    }*/
    for(int i=0;i<maxn;i++) {
        for(int j=0;j<maxn;j++) {
            if(i==0 && j==0) continue;
            for(int l=0;l<2;l++) {
                for(int k=0;k<2;k++) {
                    if(k==0) dp[i][j][k][l]=max(i==0?0:dp[i-1][j][1-k][l],j==0?0:dp[i][j-1][1-k][1-l]);
                    else dp[i][j][k][l]=min(i==0?1:dp[i-1][j][1-k][l],j==0?1:dp[i][j-1][1-k][l]);
                }
            }
        }
    }
}
int main() {
    precalc();
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int e=0,o=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            if(a[i]%2==0) e++;
            else o++;
        }
        if(dp[e][o][0][0]==0) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}