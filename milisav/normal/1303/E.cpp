#include<bits/stdc++.h>
using namespace std;
int tc;
char s[500];
char t[500];
int dp[500];
int gp[500];
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%s",s);
        scanf("%s",t);
        int n=strlen(s);
        int m=strlen(t);
        bool pos=false;
        for(int l=0;l<=m;l++) {
            for(int i=0;i<=m;i++) dp[i]=-1;
            dp[0]=0;
            for(int i=0;i<n;i++) {
                for(int j=0;j<=l;j++) gp[j]=-1;
                for(int j=0;j<=l;j++) {
                    gp[j]=dp[j];
                    if(j>0 && s[i]==t[j-1] && dp[j-1]!=-1) gp[j]=max(gp[j],dp[j-1]);
                    if(l+dp[j]<m && s[i]==t[l+dp[j]] && dp[j]!=-1) gp[j]=max(gp[j],dp[j]+1);
                }
                for(int j=0;j<=l;j++) dp[j]=gp[j];
            }
            if(dp[l]+l==m) pos=true;
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}