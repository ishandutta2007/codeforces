#include <bits/stdc++.h>

using namespace std;
#define ll long long
int t, n;
ll k;

void solve() {
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    map<int, int> cnt;
    ll boulders = 0;
    for (int i = 0; i < n; i++) {
        if (cnt.find(h[i])==cnt.end() && (i==0 || h[i]<cnt.begin()->first)) {
            cnt[h[i]]=i;
        }
        while (cnt.begin()->first < h[i]) {
            auto it = cnt.begin();
            bool b = false;
            int goal = h[i];
            if (cnt.size()>1) {
                it++;
                if (it->first <= h[i]) {b=true; goal=it->first;}
                it--;
            }
            if (boulders + (ll)(i - it->second)*(ll)(goal - it->first)>=k) {
                ll temp = k - boulders;
                int ans = i - (temp-1)%(i - it->second);
                cout << ans << '\n';
                return;
            }
            boulders += (ll)(i - it->second)*(ll)(goal - it->first);
            if (b) {
                cnt.erase(it);
            } else {
                cnt[h[i]]=it->second;
                cnt.erase(it);
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}