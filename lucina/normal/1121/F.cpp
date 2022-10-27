#include<bits/stdc++.h>
using namespace std;
int n,a,b,dp[5010][5010],f[5010],pos;
char s[5010];
int main(){
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        if(s[i]==s[j])
        dp[i][j]=dp[i-1][j-1]+1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a;
        pos=n+1;
        for(int j=1;j<i;j++){
            pos=min(pos,i-min(i-j,dp[i][j]));
        }
        for(int j=pos;j<i;j++){
            f[i]=min(f[i],b+f[j]);
        }
    }
    printf("%d\n",f[n]);

}