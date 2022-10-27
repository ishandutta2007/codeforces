#include<bits/stdc++.h>
using namespace std;
const int N=252,inf=1000000;
int dp[N][N][N],n,q,nxt[100005][26],x,y,z;
char s[100005];
vector<char> b[4];
int getpos(int u,int v){
    if(u>=n||nxt[u][v]>n)return inf;
    else return nxt[u][v];
}
int main(){
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    memset(nxt,0x3f,sizeof(nxt));
    for(int i=n;i>=1;i--){
        for(int j=0;j<26;j++){
            nxt[i-1][j]=min(nxt[i-1][j],nxt[i][j]);
        }
        nxt[i-1][s[i]-'a']=min(nxt[i-1][s[i]-'a'],i);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    char t[2];
    while(q--){
        scanf("%s",t);
        if(t[0]=='+'){
            scanf("%d%s",&x,t);
            b[x].push_back(t[0]);
            y=b[x].size();
           // cout<<"kuy "<<x<<" "<<y<<endl;
            if(x==1){
                    for(int i=0;i<=b[2].size();i++)
                    for(int j=0;j<=b[3].size();j++)
                    dp[y][i][j]=inf;
                   /* for(auto i:b[3])
                        cout<<i;
                        cout<<endl;*/
                for(int i=0;i<=b[2].size();i++){
                    for(int j=0;j<=b[3].size();j++){
                        dp[y][i][j]=min(dp[y][i][j],getpos(dp[y-1][i][j],t[0]-'a'));
                        if(i>0)
                        dp[y][i][j]=min(dp[y][i][j],getpos(dp[y][i-1][j],b[2][i-1]-'a'));
                        if(j>0)
                        dp[y][i][j]=min(dp[y][i][j],getpos(dp[y][i][j-1],b[3][j-1]-'a'));
                    }
                }
             //   cout<<"KUYYYY\n";

            }
            if(x==2){
                for(int i=0;i<=b[1].size();i++)
                    for(int j=0;j<=b[3].size();j++)
                    dp[i][y][j]=inf;
                for(int i=0;i<=b[1].size();i++){
                    for(int j=0;j<=b[3].size();j++){
                        dp[i][y][j]=min(dp[i][y][j],getpos(dp[i][y-1][j],t[0]-'a'));
                        if(i>0)
                        dp[i][y][j]=min(dp[i][y][j],getpos(dp[i-1][y][j],b[1][i-1]-'a'));
                        if(j>0)
                        dp[i][y][j]=min(dp[i][y][j],getpos(dp[i][y][j-1],b[3][j-1]-'a'));
                    }
                }
            }
            if(x==3){
                for(int i=0;i<=b[1].size();i++)
                    for(int j=0;j<=b[2].size();j++)
                    dp[i][j][y]=inf;
                for(int i=0;i<=b[1].size();i++){
                    for(int j=0;j<=b[2].size();j++){
                        dp[i][j][y]=min(dp[i][j][y],getpos(dp[i][j][y-1],t[0]-'a'));
                        if(i>0)
                        dp[i][j][y]=min(dp[i][j][y],getpos(dp[i-1][j][y],b[1][i-1]-'a'));
                        if(j>0)
                        dp[i][j][y]=min(dp[i][j][y],getpos(dp[i][j-1][y],b[2][j-1]-'a'));
                    }
                }
            }
        }
        else{
            scanf("%d",&x);
            b[x].pop_back();
        }
        x=b[1].size();y=b[2].size();z=b[3].size();
        printf(dp[x][y][z]<=n?"YES\n":"NO\n");
    }
}