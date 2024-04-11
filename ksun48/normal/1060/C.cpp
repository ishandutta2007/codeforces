#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<LL> a(n);
    vector<LL> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<LL> besta(n+1, 1LL << 50LL);
    vector<LL> bestb(m+1, 1LL << 50LL);
    vector<LL> pa(n+1, 0);
    pa[0] = 0;
    for(int i = 0; i < n; i++){
        pa[i+1] = pa[i] + a[i];
    }
    vector<LL> pb(m+1, 0);
    pb[0] = 0;
    for(int i = 0; i < m; i++){
        pb[i+1] = pb[i] + b[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            besta[j-i] = min(besta[j-i], pa[j] - pa[i]);
        }
    }
    for(int i = 0; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            bestb[j-i] = min(bestb[j-i], pb[j] - pb[i]);
        }
    }
    LL x;
    cin >> x;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x / besta[i] >= bestb[j]) ans = max(ans, i * j);
        }
    }
    cout << ans << '\n';
}