#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int> a[maxn];
int n,sz[maxn];
long long sum,ans;
void dfs_sz(int nod,int pa){
    sz[nod]=1;
    for(int i:a[nod]){
        if(i!=pa){
            dfs_sz(i,nod);
        sz[nod]+=sz[i];
    }
    }
    return;
}
void dfs(int nod,int pa,long long cur){
    ans=max(ans,cur);
    for(int i:a[nod]){
        if(i!=pa){
            dfs(i,nod,cur+n-(2*sz[i]));
        }
    }
    return;
}


int main(){
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs_sz(1,0);
    for(int i=1;i<=n;i++)
        sum+=(sz[i]);
    dfs(1,0,sum);
    printf("%lld\n",ans);
}