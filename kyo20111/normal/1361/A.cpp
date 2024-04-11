#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, a[500500], c[500500], chk[500500];
vector<int> v[500500],ans;
priority_queue<tuple<int,int,int>> pq;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a, b; scanf("%d %d",&a,&b);
        v[a].push_back(b), v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) scanf("%d",a+i);
 
    for(int i=1;i<=n;i++) pq.push({-a[i],-1,i}), c[i]=-1;
 
    while(!pq.empty()){
        auto [b,k,u] = pq.top(); pq.pop();
        if(c[u] != k) continue;
        if(k != b) return !printf("-1");
        chk[u] = 1;
        ans.push_back(u);
        for(auto x : v[u]) if(!chk[x] && c[x]==b) pq.push({-a[x],--c[x],x});
    }
    for(auto x : ans) printf("%d ",x);
}