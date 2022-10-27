#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
char s[maxn];
int n,dp[11][11];
int nxt[12][12][12];
/// nxt[i][j][x][y]
/// the minimum movement require to
/// moved for a counter i,j with x to y
int tst(int x,int y,int z){
    int mi=2000;
    if(x==0){
        if((z%y)==0){
            mi=z/y-1;
        }
    }
    else if(y==0){
        if((z%x)==0){
            mi=z/x-1;
        }
    }
    else{
    for(int k=0;k<=z;k+=x){
        if(((z-k)%y)==0){
            mi=min(mi,(k/x)+((z-k)/y)-1);
        }
    }
    }
    return mi;
}

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int x=0;x<10;x++){
                int cur=x;
                if(i==0&&j==0){
                    if(cur!=0){
                        nxt[i][j][x]=-1;
                    }
                    else nxt[i][j][x]=0;
                    continue;
                }
                if(i==0||j==0){
                    if(cur==0){
                        nxt[i][j][x]=0;
                        continue;
                    }
                }
                if(cur==0)cur+=10;
                int mi=2000;
                for(int shit=0;shit<=15;shit++){
                    mi=min(mi,tst(i,j,cur));
                    cur+=10;
                }
                if(mi==2000){
                    nxt[i][j][x]=-1;
                }
                else{
                    nxt[i][j][x]=mi;
                }
            }
        }
    }
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            long long ans=0;
            bool ch=true;
            for(int k=0;k<n-1;k++){
                int cur=s[k+1]-s[k];
                if(cur<0)cur+=10;
                if(nxt[i][j][cur]!=-1){
                    ans+=nxt[i][j][cur];
                }
                else{
                    ch=false;
                    break;
                }
            }
            printf("%lld ",ch?ans:-1LL);
        }
        printf("\n");
    }
}
/*
    Good Luck
        -Lucina
*/