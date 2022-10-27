#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int> a[maxn],p[maxn];
int n,u,v,b[maxn],ans,m,j;
bool ch;
vector<int> g;
unordered_map<int,int> dp[maxn];
void dfs(int nod,int pa){
    for(auto i:p[b[nod]])
    dp[nod][i]=1;
    for(auto i:a[nod]){
        if(i!=pa){
            dfs(i,nod);
            for(auto j:p[b[i]]){
                if(b[nod]%j==0){
                    ans=max(ans,dp[nod][j]+dp[i][j]);
                    dp[nod][j]=max(dp[nod][j],dp[i][j]+1);
                }
            }
        }
    }
    return ;
}

int main(){
    for(int i=2;i<=maxn;i++){
        if(p[i].size()==0){
            for(int j=i;j<=maxn;j+=i){
                p[j].push_back(i);
            }
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        ans=max(ans,b[i]>1?1:0);
        }
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans);


}