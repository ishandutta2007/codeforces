#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
int dp[5001][5001];
int n,m,pa[5001*5001],u,v,z;
int t;
int hashh(pair<int,int> w){
    return n*w.first+w.second;
}
bool vis[5001];
vector<pair<int,int>> a[5003];
void dfs(int nod){
    if(vis[nod])return;
    vis[nod]=true;
    for(auto i:a[nod]){
        dfs(i.first);
        for(int j=0;j<n;j++){
            if(dp[nod][j+1]>dp[i.first][j]+i.second){
                dp[nod][j+1]=dp[i.first][j]+i.second;
                pa[hashh(make_pair(nod,j+1))]=hashh(make_pair(i.first,j));
            }
        }
        }
    return ;
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<5001;i++)
        for(int j=0;j<5001;j++)
        dp[i][j]=inf;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&z);
        a[v].push_back(make_pair(u,z));
    }
    dp[1][1]=0ll;
    vis[1]=true;
    dfs(n);
    int ans=0;
    for(int j=n;j>=1;j--){
        if(dp[n][j]<=t){
            ans=max(ans,j);
        break;
        }
    }
    int x;
    vector<int> la;
    x=hashh({n,ans});
    while(x){
        la.push_back(x/n-(x%n==0));
        x=pa[x];
    }
    reverse(la.begin(),la.end());
    printf("%d\n",la.size());
    la[0]=1;
    for(int i:la){
        printf("%d ",i);
    }
    printf("\n");
}