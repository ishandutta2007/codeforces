#include<bits/stdc++.h>
using namespace std;
const int N=16;
int dp[N][1<<N],n,m,mn[N][N],mn2[N][N],b[N][10005],ans;

/*we can permute row as we want
write the number in s1 s2 .... s_nm
iterate from first column to last column
|s[i]-s[i+1]|>=k
find maximum k
*/
int calc(int mask,int v){
    if(dp[v][mask]!=-1)return dp[v][mask];
    dp[v][mask]=0;
    for(int i=0;i<n;i++){
        if(v!=i&&(mask&(1<<i))){
            dp[v][mask]=max(dp[v][mask],min(mn[i][v],calc(mask^(1<<v),i)));
        }
    }
    return dp[v][mask];
}
int main(){
    memset(mn,0x3f,sizeof(mn));
    memset(mn2,0x3f,sizeof(mn2));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&b[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                for(int k=0;k<m;k++)
                    mn[i][j]=min(mn[i][j],abs(b[i][k]-b[j][k]));
                for(int k=0;k<m-1;k++)
                    mn2[i][j]=min(mn2[i][j],abs(b[i][k]-b[j][k+1]));
        }
    }
    /*for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        printf("%d%c",mn[i][j],j==n-1?'\n':' ');*/
    for(int i=0;i<n;i++){
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<n;j++){
            dp[j][1<<j]=(j==i?(int)1e9:0);
        }
        for(int j=0;j<n;j++){
            ans=max(ans,min(mn2[j][i],calc((1<<n)-1,j)));
        }
    }
    printf("%d\n",ans);
}