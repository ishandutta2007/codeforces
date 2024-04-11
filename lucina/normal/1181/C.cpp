#include<bits/stdc++.h>
using namespace std;
int n,m,r[1005][1005],d[1005][1005],mi[1005][1005],ma[1005][1005];
char s[1005][1005];
int ans;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i][j]==s[i][j+1]){
                r[i][j]=r[i][j+1]+1;
            }
            else{
                r[i][j]=1;
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=n;i>=1;i--){
            if(s[i][j]==s[i+1][j]){
                d[i][j]=d[i+1][j]+1;
                mi[i][j]=min(mi[i+1][j],r[i][j]);
            }
            else{
                mi[i][j]=r[i][j];
                d[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(s[i][j]==s[i-1][j]){
                ma[i][j]=min(ma[i-1][j],r[i][j]);
            }
            else{
                ma[i][j]=r[i][j];
            }
        }
    }
    int a;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        a=d[i][j];
        if(a+i<=n&&(d[i+a][j]==a)&&i+a+a<=n&&d[i+a+a][j]>=a){
            ans+=min({mi[i][j],mi[i+a][j],ma[i+a+a+a-1][j]});
        }
    }
    printf("%d\n",ans);
}