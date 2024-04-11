#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,dp1[maxn][maxn],dp2[maxn][maxn],dp[maxn][maxn],f1[maxn][maxn],f2[maxn][maxn];
char s[maxn][maxn];
vector<pair<int,int>>a;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++){
            if(s[i][j-1]=='*'&&s[i][j]=='*'){
                dp1[i][j]=dp1[i][j-1]+1;
            }
        }
        for(int j=m;j>=1;j--){
            if(s[i][j+1]=='*'&&s[i][j]=='*')
                dp[i][j]=dp[i][j+1]+1;
        }
        for(int j=1;j<=m;j++){
            dp1[i][j]=min(dp1[i][j],dp[i][j]);
        }
    }
    for(int i=0;i<1005;i++)
        for(int j=0;j<1005;j++)
        dp[i][j]=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(s[i-1][j]=='*'&&s[i][j]=='*')
                dp2[i][j]=dp2[i-1][j]+1;
        }
        for(int i=n;i>=1;i--){
            if(s[i+1][j]=='*'&&s[i][j]=='*')
                dp[i][j]=dp[i+1][j]+1;
        }
        for(int i=1;i<=n;i++){
            dp2[i][j]=min(dp2[i][j],dp[i][j]);
        }
    }
    for(int i=0;i<1005;i++)
        for(int j=0;j<1005;j++)
        dp[i][j]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp1[i][j],dp2[i][j]);
            if(dp[i][j]){
                    ans++;
                    a.push_back({i,j});
                f1[i-dp[i][j]][j]++;
                f1[i+dp[i][j]+1][j]--;
                f2[i][j-dp[i][j]]++;
                f2[i][j+dp[i][j]+1]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            f2[i][j]+=f2[i][j-1];
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            f1[i][j]+=f1[i-1][j];
        }
    }
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*'){
                if(f1[i][j]<=0&&f2[i][j]<=0){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    printf("%d\n",ans);
    for(auto j:a)
    printf("%d %d %d\n",j.first,j.second,dp[j.first][j.second]);
}