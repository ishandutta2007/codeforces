#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,x,y,ace[4];
long long dp[2][11],b[4];
bool cmp(int x,int y){
    return x>y;
}

int main(){
    scanf("%d",&n);
    memset(dp[0],-1LL,sizeof(dp[0]));
    dp[0][0]=0LL;
    int st;       
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
         st=i&1;
        memset(dp[st],-1LL,sizeof(dp[st]));
        scanf("%d",&k);
        vector<int> c[4];
        c[2].push_back(-1),c[3].push_back(-1);
        for(int j=1;j<=k;j++){
            scanf("%d%d",&x,&y);
            if(x>1)
            c[x][0]=max(c[x][0],y);
            else{
                q.push(y);
                if(q.size()>3)q.pop();
            }
        }
        while(!q.empty())c[1].push_back(q.top()),q.pop();
        if(c[2][0]==-1)c[2].pop_back();if(c[3][0]==-1)c[3].pop_back();
        reverse(c[1].begin(),c[1].end());
        memset(b,-1,sizeof(b));
        memset(ace,-1,sizeof(ace));
        for(int j=1;j<=3;j++)if(c[j].size()>0)b[1]=max(b[1],0LL+c[j][0]),ace[1]=max(ace[1],c[j][0]);
        if(c[1].size()>2)b[3]=max(b[3],0LL+c[1][0]+c[1][1]+c[1][2]),ace[3]=c[1][0];
        if(c[1].size()>1)b[2]=max(b[2],0LL+c[1][0]+c[1][1]),ace[2]=c[1][0];
        if(c[1].size()&&c[2].size()){
        long long z=c[1][0]+c[2][0];
        if(z>=b[2])
            b[2]=z,ace[2]=max({ace[2],c[2][0],c[1][0]});
        }
        for(int j=1;j<=3;j++){
        if(b[j]!=-1){
            for(int i=0;i<10;i++){
                if(dp[st^1][i]!=-1){
                    if(i+j<10)dp[st][i+j]=max(dp[st][i+j],dp[st^1][i]+b[j]);
                    else dp[st][(i+j)%10]=max(dp[st][(i+j)%10],dp[st^1][i]+b[j]+ace[j]);
                }
            }
        }
        }
        for(int i=0;i<10;i++)
            dp[st][i]=max(dp[st][i],dp[st^1][i]);
    }
    long long ans=0;
    for(int i=0;i<10;i++)
        ans=max(ans,dp[st][i]);
    printf("%lld\n",ans);
}