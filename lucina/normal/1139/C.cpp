
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
int n,k,u,v,p;
vector<int> a[maxn];
bool vis[maxn];
long long ans;
int dfs(int nod){
    int r=1;
    vis[nod]=true;
    for(int i:a[nod]){
        if(!vis[i])
        r+=(dfs(i));
    }
    return r;
}

int main(){
    scanf("%d%d",&n,&k);
    ans=n;
    for(int i=1;i<k;i++){
    ans*=n;
    ans%=mod;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&p);
        if(p==0){
        a[u].push_back(v);
        a[v].push_back(u);
    }
    }
    long long t;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            p=dfs(i);
            t=p;
            for(int j=1;j<k;j++){
                t*=p;
                if(t>mod)t%=mod;
            }
            ans-=t;
            if(ans<0)ans+=mod;
        }
    }

    printf("%lld\n",ans);
}