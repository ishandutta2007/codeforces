#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,u,v,b[maxn];
vector<int> a[maxn];
long long dp[maxn],ans,sum,supersum;
void dfs(int nod,int pa,int lv){
    sum+=(long long)1*b[nod]*lv;
    for(auto i:a[nod]){
        if(i!=pa){
            dfs(i,nod,lv+1);
            dp[nod]+=dp[i];
        }
    }
    dp[nod]+=b[nod];
    return;
}

void superdfs(int nod,int pa,long long currentsum){
    long long fuck;
    if(nod!=1){
    fuck=currentsum+supersum-2*dp[nod];
    ans=max(ans,fuck);
    }
    else
        fuck=currentsum;
    for(auto i:a[nod]){
        if(i!=pa){
            superdfs(i,nod,fuck);
        }
    }
    return ;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        supersum+=b[i];
        }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0,0);
    ans=max(ans,sum);
    superdfs(1,0,sum);
    printf("%lld\n",ans);
}