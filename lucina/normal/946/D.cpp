#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,k,dp[510][510],l,ans,c,d,f[510][510],base,tot;
vector<int> pos[510];
char s[510];

int main(){

    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        c=0;
        for(int j=1;j<=m;j++)
            c+=s[j]-'0';
        if(c==0)continue;
        l++;
        for(int j=1;j<=m;j++){
            if(s[j]=='1')
                pos[l].push_back(j);
        }
        ans+=(pos[l].back()-pos[l][0]+1);
    }
    n=l;
    for(int i=1;i<=n;i++){
        d=pos[i].size();
        dp[i][0]=0;
        for(int j=1;j<d;j++){
            dp[i][j]=inf;
            for(int l=0;l<=d-j;l++){
                dp[i][j]=min(dp[i][j],(pos[i][j+l-1]-pos[i][l]+1));
            }
        }
        dp[i][d]=pos[i].back()-pos[i][0]+1;
    }

    for(int i=1;i<=501;i++)
        for(int j=0;j<=501;j++)
        f[i][j]=inf;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int l=0;l<=j;l++){
                f[i][j]=min(f[i][j],f[i-1][j-l]+dp[i][pos[i].size()-l]);
            }
        }
    }
    printf("%d\n",f[n][k]);
}