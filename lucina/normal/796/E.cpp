#include<bits/stdc++.h>
using namespace std;
const short int maxn=1010,inf=8000;
short int n,dp[2][maxn][52][52];
bool r[maxn],s[maxn];
short int p,k;
///dp[i][j][a][b] the maximum number of correct answer
///from 1,....,i-th task such that j moves left available
///and have left effect remain a and right effect remain b
void sf(short int x){
    for(short int i=0;i<=p;i++){
        for(short int j=0;j<=k;j++){
            for(short int l=0;l<=k;l++){
                dp[x][i][j][l]=-inf;
            }
        }
    }
}
void upd(short int a,short int &b){
    b=max(a,b);return;
}

int32_t main(){
    scanf("%hu%hu%hu",&n,&p,&k);
    short int x,y,R,S;
    scanf("%hu",&R);
    for(short int i=1;i<=R;i++){
        scanf("%hu",&y);
        r[y]=true;
    }
    scanf("%d",&S);
    for(short int i=1;i<=S;i++){
        scanf("%hu",&y);
        s[y]=true;
    }
    if((p/2)*k>=n){
        short int shit=0;
        for(short int i=1;i<=n;i++){
            if(r[i]||s[i])++shit;
        }
        return !printf("%hu\n",shit);
    }
    x=0;
    sf(0);
    dp[0][p][0][0]=0;
    for(short int i=1;i<=n;i++){
        x^=1;
        sf(x);
        for(short int j=0;j<=p;j++){
            for(short int l=0;l<=k;l++){
                for(short int m=0;m<=k;m++){
                    if(l>0&&m>0){
                    upd(dp[x^1][j][l][m]+((r[i]==1||s[i]==1)?1:0),dp[x][j][l-1][m-1]);
                    }
                    if(l==0&&m>0){
                    upd(dp[x^1][j][l][m]+((s[i]==1)?1:0),dp[x][j][l][m-1]);
                    if(j>0){
                    upd(dp[x^1][j][l][m]+(((r[i]==1)||(s[i]==1))?1:0),dp[x][j-1][k-1][m-1]);
                    }
                    }
                    if(l>0&&m==0){
                    upd(dp[x^1][j][l][m]+((r[i]==1)?1:0),dp[x][j][l-1][m]);
                    if(j>0){
                    upd(dp[x^1][j][l][m]+(((s[i]==1)||(r[i]==1))?1:0),dp[x][j-1][l-1][k-1]);
                    }
                    }
                    if(l==0&&m==0){
                        upd(dp[x^1][j][l][m],dp[x][j][l][m]);
                        if(j>0){
                        upd(dp[x^1][j][l][m]+(r[i]==1?1:0),dp[x][j-1][k-1][m]);
                        upd(dp[x^1][j][l][m]+(s[i]==1?1:0),dp[x][j-1][l][k-1]);
                        }
                    }
                }
            }
        }
    }
    short int ans=0;
    for(short int i=0;i<=p;i++){
        for(short int j=0;j<=k;j++){
            for(short int l=0;l<=k;l++){
                upd(dp[x][i][j][l],ans);
        }
        }
    }
    printf("%hu\n",ans);

}