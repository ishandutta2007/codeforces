#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()
int n, k, a[200200];
priority_queue<pair<int,int>> pq;
priority_queue<int> pq2;
ll ans = 1, ans2, mod = 998244353;

int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        pq.push({a[i], i});
    }

    for(int i=1;i<=k;i++){
        pq2.push(pq.top().second);
        ans2 += pq.top().first;
        pq.pop();
    }

    int v = pq2.top(); pq2.pop();
    while(!pq2.empty()){
        int u = pq2.top();
        ans = (ans * (v - u)) % mod;
        v = u;
        pq2.pop();
    }

    printf("%lld %lld",ans2,ans);
}