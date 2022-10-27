#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],u,v,cp;
long long dp[maxn],ans;
vector<int> b[maxn];

void dfs(int nod,int pa,bool z){
    dp[nod]=a[nod];
    for(int i:b[nod]){
        if(i!=pa){
            dfs(i,nod,z);
            dp[nod]+=max((long long)0,dp[i]);
        }
    }
    if(z)
        ans=max(ans,dp[nod]);
    else{
        if(dp[nod]==ans){
            cp++;
            dp[nod]=0;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        b[u].push_back(v);
        b[v].push_back(u);
    }
    ans=-1e18;
    dfs(1,0,1);
    dfs(1,0,0);
    printf("%lld %d\n",ans*(long long)cp,cp);
}