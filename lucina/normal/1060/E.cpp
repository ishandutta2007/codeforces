#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,u,v,dp[maxn],d[2];
long long f[maxn],ans,sum;
vector<int> a[maxn];
//ans+=(f[]+dp[])*dp[]
//ans+= (f[]+dp[])*dp[]
void dfs(int nod,int pa,int x){
    d[x]++;
    for(int i:a[nod]){
        if(i!=pa){
            dfs(i,nod,x^1);
            dp[nod]+=dp[i];
            f[nod]+=(f[i]+dp[i]);
        }
    }
    for(int i:a[nod]){
        if(i!=pa){
            ans+=(f[nod]-f[i]-dp[i])*dp[i];
        }
    }
    ans+=f[nod];
    dp[nod]++;
    return;
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0,0);
    printf("%lld\n",(ans+(1ll*d[0]*d[1]))/2);
}