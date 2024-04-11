#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=52,inf=1e9+7;
void KMP(char a[],int n,int kmp[],int nxt[][26]){
    kmp[1]=0;
    for(int i=2;i<=n;i++){
        int cur=kmp[i-1];
        while(cur&&a[cur+1]!=a[i]){
            cur=kmp[cur];
        }
        kmp[i]=(cur+(a[cur+1]==a[i]));
    }
    for(int i=0;i<=n;i++){
        for(char z='a';z<='z';z++){
            int cur=i;
            while(cur&&a[cur+1]!=z){
                cur=kmp[cur];
            }
            nxt[i][z-'a']=cur+(a[cur+1]==z);
        }
    }
    return;
}
int dp[N][M][M];
char c[N],s[M],t[M];
int kmps[M],kmpt[M],nxts[M][26],nxtt[M][26];
void upd(int &x,int y){
    x=max(x,y);return;
}

int main(){
    scanf("%s%s%s",c+1,s+1,t+1);
    int n=strlen(c+1);int m=strlen(s+1);int k=strlen(t+1);
    KMP(s,m,kmps,nxts);KMP(t,k,kmpt,nxtt);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
        for(int l=0;l<=k;l++)
        dp[i][j][l]=-inf;
        }
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            for(int l=0;l<=k;l++){
                for(char x='a';x<='z';x++){
                    if(c[i+1]=='*'||c[i+1]==x){
                        int ns=nxts[j][x-'a'];int nt=nxtt[l][x-'a'];
                        upd(dp[i+1][ns][nt],dp[i][j][l]+(ns==m)-(nt==k));
                    }
                }
            }
        }
    }
    int ans=-inf;
    for(int i=0;i<=m;i++)
    for(int j=0;j<=k;j++){
        upd(ans,dp[n][i][j]);
    }
    printf("%d\n",ans);
}