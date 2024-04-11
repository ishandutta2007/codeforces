#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,lf,dp[maxn];
bool f[maxn];
vector<int> a[maxn];
void dfs(int nod){
    if(a[nod].empty()){
        dp[nod]=1;
        lf++;
        return ;
    }
    for(int i:a[nod])
        dfs(i);
    if(f[nod]){
        dp[nod]=maxn;
        for(int i:a[nod])
            dp[nod]=min(dp[nod],dp[i]);
    }
    else{
        dp[nod]=0;
        for(int i:a[nod])
            dp[nod]+=dp[i];
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        a[x].push_back(i);
    }
    dfs(1);
    printf("%d",lf-dp[1]+1);

}