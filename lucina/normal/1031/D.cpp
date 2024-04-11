#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,k,dp[maxn][maxn];
char s[maxn][maxn];
bool vis[maxn][maxn];
queue<pair<int,int>> q1,q2;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
        int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>1&&j>1){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            }
            else if(i==1&&j>1)
                dp[i][j]=dp[i][j-1];
            else if(i>1&&j==1)
                dp[i][j]=dp[i-1][j];
            dp[i][j]+=(s[i][j]=='a'?0:1);
            if(dp[i][j]<=k){
                mx=max(mx,i+j);
            }
        }
    }
    for(int i=0;i<mx-1;i++)
        printf("a");
    if(mx==0)
    q1.push({1,1}),printf("%c",s[1][1]);
    for(int i=1;i<=n;i++){
        if(mx-i<=n&&mx-i>=1){
            if(dp[mx-i][i]<=k){
                q1.push({mx-i,i});
                vis[mx-i][i]=true;
            }
        }
    }
    if(q1.empty())
        return 0;
        char fuck='{';
        bool ch=false;
    for(int r=mx;r<2*n;r++){
        q2=q1;
        fuck='{';
        ch=false;
        while(!q1.empty()){
            if(q1.front().first+1<=n){
                if(s[q1.front().first+1][q1.front().second]<=fuck){
                    fuck=s[q1.front().first+1][q1.front().second];
                    ch=true;
                }
            }
            if(q1.front().second+1<=n){
                if(s[q1.front().first][q1.front().second+1]<=fuck){
                    fuck=s[q1.front().first][q1.front().second+1];
                    ch=true;
                }
            }
            q1.pop();
        }
        if(ch&&fuck!='{')
        printf("%c",fuck);
        while(!q2.empty()){
            if(q2.front().first+1<=n){
                if(!vis[q2.front().first+1][q2.front().second]&&s[q2.front().first+1][q2.front().second]==fuck)
                q1.push({q2.front().first+1,q2.front().second});
                vis[q2.front().first+1][q2.front().second]=true;
            }
            if(q2.front().second+1<=n){
                if(!vis[q2.front().first][q2.front().second+1]&&s[q2.front().first][q2.front().second+1]==fuck)
                q1.push({q2.front().first,q2.front().second+1});
                vis[q2.front().first][q2.front().second+1]=true;
            }
            q2.pop();
        }
    }
}