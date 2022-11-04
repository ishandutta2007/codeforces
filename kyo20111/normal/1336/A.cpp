#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, p[200200], sz[200200], par[200200], cnt[200200];
vector<int> v[200200];
priority_queue<pair<int, int>> pq;
ll ans;
void dfs(int u, int p, int c){
    par[u] = p;
    sz[u] = c;
    cnt[u] = 1;
    for(int x : v[u]) if(x != p) dfs(x, u, c+1), cnt[u] += cnt[x];
    pq.push({c - cnt[u] + 1, u});
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        int a, b; scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);

    while(k--){
        int u = pq.top().second, c = pq.top().first;
        pq.pop();
        ans += c;
    }

    printf("%lld",ans);
}