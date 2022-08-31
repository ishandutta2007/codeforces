#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> f(n);
    for(int i = 0; i < n; i++){
        LL r;
        cin >> r;
        f[i] = __builtin_popcountll(r);
    }
    
    vector<int> par(n+1, 0);
    for(int i = 0; i < n; i++){
        par[i+1] = 1 & (par[i] + f[i]);
    }
    vector<int> psum0(n+2, 0);
    vector<int> psum1(n+2, 0);
    for(int i = 0; i <= n; i++){
        psum0[i+1] = psum0[i] + (par[i] == 0);
        psum1[i+1] = psum1[i] + (par[i] == 1);
    }
    
    vector<pair<int,int> > z;
    for(int i = 0; i < n; i++){
        z.push_back({f[i], i});
    }
    sort(z.begin(), z.end());
    set<int> a;
    a.insert(-1);
    a.insert(n);
    
    LL ans = 0;

    for(int i = 0; i < n; i++){
        int idx = z[i].second;
        int l = *prev(a.lower_bound(idx));
        int r = *a.lower_bound(idx);
        a.insert(z[i].second);
        LL f0 = (LL)(psum0[idx+1] - psum0[l+1]) * (LL)(psum0[r+1] - psum0[idx+1]);
        LL f1 = (LL)(psum1[idx+1] - psum1[l+1]) * (LL)(psum1[r+1] - psum1[idx+1]);
        ans += f0 + f1;
    }
    for(int i = 0; i <= n; i++){
        int total = 0;
        int maxv = 0;
        for(int j = i+1; j < i+80; j++){
            if(j > n) continue;
            maxv = max(maxv, f[j-1]);
            total += f[j-1];
            if(maxv > total - maxv && par[i] == par[j]){
                ans--;
            }
        }
    }
    cout << ans << '\n';
}