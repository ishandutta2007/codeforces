#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<pair<ll,int>> pq;
int n,m,cur;
ll ans[1001001];

void find(int mx, int a, ll b, int j){
    while(!pq.empty() && (pq.top().second + (m - a) < j || pq.top().first <= b)){
        int u = min(mx, pq.top().second + (m - a)), u2 = pq.top().second;
        ll v = pq.top().first;
        pq.pop();

        if(u <= cur) continue;
        if(cur < u2 - 1) find(u2-1, a, b, j);

        ans[cur+1] += v;
        ans[u+1] -= v;
        cur = u;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        pq.push({0, 0});
        cur = 0;
        int a; scanf("%d",&a);

        for(int j=1;j<=a;j++){
            ll b; scanf("%lld",&b);
            find(j-1, a, b, j);
            pq.push({b, j});
        }
        if(a < m) pq.push({0,a+1});
        find(m, a, 1e9+1, 1e9);
    }
    for(int i=1;i<=m;i++) printf("%lld ",ans[i]+=ans[i-1]);
}