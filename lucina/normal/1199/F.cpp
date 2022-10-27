#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int dp[52][52][52][52],n,p[52][52];
char s[52];
int get(int x1,int y1,int x2,int y2){
    return p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];
}
int rec(int x1,int y1,int x2,int y2){
    if(dp[x1][y1][x2][y2]!=-1){
        return dp[x1][y1][x2][y2];
    }   
    if(get(x1,y1,x2,y2)==0)return dp[x1][y1][x2][y2]=0;
    int res=max(x2-x1+1,y2-y1+1);
    for(int i=x1;i+1<=x2;i++)
    res=min(res,rec(x1,y1,i,y2)+rec(i+1,y1,x2,y2));
    for(int i=y1;i+1<=y2;i++)
    res=min(res,rec(x1,y1,x2,i)+rec(x1,i+1,x2,y2));
    return dp[x1][y1][x2][y2]=res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=n;j++){
            p[i][j]=p[i][j-1]+p[i-1][j]-p[i-1][j-1]+(s[j]=='#');
        }
    }
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            for(int l=1;l<=n;l++){
                dp[i][j][k][l]=-1;
            }
        }
    }
    }
    printf("%d\n",rec(1,1,n,n));
}
/*
    Good Luck
        -Lysithea
*/