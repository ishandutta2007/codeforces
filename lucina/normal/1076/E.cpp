#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,u,v,w;
vector<int> a[maxn];
vector<pair<int,int>> q[maxn];
long long s[maxn],ans[maxn];
void dfs(int nod,int pa,int d,long long sum){
    for(pair<int,int> i:q[nod]){
        s[d]+=i.second;v=d+i.first;
        if(v+1<n)s[v+1]-=i.second;
    }
    sum+=s[d];
    ans[nod]=sum;
    for(int i:a[nod]){
        if(i!=pa){
            dfs(i,nod,d+1,sum);
        }
    }
    for(pair<int,int> i:q[nod]){
        u=d; v=d+i.first;
        s[u]-=i.second;
        if(v+1<n)s[v+1]+=i.second;
    }
    return ;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        q[u].push_back(make_pair(v,w));
    }
    dfs(1,0,0,0ll);
    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
}