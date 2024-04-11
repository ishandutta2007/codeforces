#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, mid = 1e5;
ll a[100100], b[100100], p[200200], ans;
priority_queue<tuple<ll, int, int>> pq;


int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return false;
    p[a] = b;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m >> n;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];


    for(int i=1;i<=m;i++) p[i + mid] = i + mid;
    for(int i=1;i<=n;i++) p[i] = i;

    for(int i=1;i<=m;i++){
        int A; cin >> A;
        for(int j=1;j<=A;j++){
            int B; cin >> B;
            pq.push({a[i] + b[B], i + mid, B});
            ans += a[i] + b[B];
        }
    }

    while(!pq.empty()){
        auto [c, a, b] = pq.top(); pq.pop();
        if(merge(a, b)) ans -= c;
    }

    cout << ans;
}