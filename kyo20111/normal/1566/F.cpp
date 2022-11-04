#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
int n, m;
pair<int, int> p[200200];
ll dp[200200][2], a[200200], mn[200200];

void solve(){
    cin >> n >> m;

    set<int> st;
    for(int i=1;i<=n;i++) cin >> a[i], st.insert(a[i]);
    for(int i=1;i<=m;i++) cin >> p[i].first >> p[i].second;
    sort(p+1, p+1+m);

    vector<pair<ll, ll>> v;

    for(int i=1;i<=m;i++){
        auto it = st.lower_bound(p[i].first);
        if(it != st.end() && *it <= p[i].second) continue;
        v.push_back(p[i]);
    }

    if(v.empty()){
        cout << 0;
        return;
    }

    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) dp[i][j] = INF;

    int k = 0;
    ll e = INF;
    while(k < v.size() && v[k].second < a[1]) e = min(e, v[k].second), k++;

    if(k){
        dp[1][1] = a[1] - e;
        dp[1][0] = dp[1][1] * 2;
    }else{
        dp[1][0] = dp[1][1] = 0;
    }
    
    for(int i=2;i<=n;i++){
        int l = k;
        while(l < v.size() && v[l].second < a[i]) l++;

        if(l == k){
            dp[i][0] = dp[i][1] = min(dp[i-1][1], dp[i-1][0]);
            continue;
        }

        mn[l] = INF;
        for(int j=l-1;j>=k;j--) mn[j] = min(mn[j+1], v[j].second);

        ll R = v[l-1].first;
        ll L = mn[k];

        dp[i][1] = dp[i-1][1] + (a[i] - L);
        dp[i][0] = min(dp[i-1][1] + min(a[i] - L, R - a[i-1]) * 2, dp[i-1][0] + (R - a[i-1]));
        dp[i][1] = min(dp[i][1], dp[i][0]);

        if(k+1 == l){
            k = l;
            continue;
        }

        for(int j=k+1;j<l;j++){ // k ~ j-1, j ~ l-1
            ll L = v[j-1].first, R = mn[j];

            ll val = min(dp[i-1][0] + (L - a[i-1]), dp[i-1][1] + (L - a[i-1]) * 2);
            dp[i][1] = min(dp[i][1], val + (a[i] - R));
            dp[i][0] = min(dp[i][0], val + (a[i] - R) * 2);
        }

        dp[i][1] = min(dp[i][1], dp[i][0]);
        k = l;
    }

    if(k == v.size()){
        cout << min(dp[n][0], dp[n][1]);
        return;
    }

    ll L = v.back().first;

    cout << min(dp[n][0] + (L - a[n]), dp[n][1] + (L - a[n]) * 2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}