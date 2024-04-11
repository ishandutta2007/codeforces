//
// Created by Nitit Jongsawatsataporn on 7/4/2022 AD.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<int,int>;
using piii = pair<pii,int>;
const int N = 1<<18;

ll bit[2*N];
ll b[2*N];

void add(int idx, int val) {
    for (bit[idx += N] = val; idx > 1; idx >>= 1) bit[idx>>1] = bit[idx] + bit[idx^1];
}
void add2(int idx, int val) {
    for (b[idx += N] = val; idx > 1; idx >>= 1) b[idx>>1] = b[idx] + b[idx^1];
}

ll sum(int l, int r) { //sum in [l,r)
    ll ans = 0;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += bit[l++];
        if (r&1) ans += bit[--r];
    }
    return ans;
}
ll sum2(int l, int r) { //sum in [l,r)
    ll ans = 0;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += b[l++];
        if (r&1) ans += b[--r];
    }
    return ans;
}

int main() {
    int n; cin>>n;
    int a[n],v[n];
    piii s[n];
    pii f[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        f[i] = {a[i],i};
    }
    sort(f,f+n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[f[i].second] = i;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        s[i] = {{v[i],a[i]},i};
    }
    sort(s,s+n);
    ll ans = 0;
    for(int i=0;i<n;i++) {
        int nd = s[i].second;
        int val = s[i].first.first;
        add(mp[nd],a[nd]);
        add2(mp[nd],1);
        ans += sum2(0,mp[nd])*a[nd] - sum(0,mp[nd]);
        //cout<<i<<' '<<nd<<' '<<mp[nd]<<' '<<a[nd]<<' '<<sum(0,mp[nd])<<' '<<sum2(0,mp[nd])<<' '<<ans<<endl;
    }
    cout<<ans;
    return 0;
}