#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        VI a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        vector<ll> s(n + 1);
        rep(i, n) s[i + 1] += s[i] + a[i];
        vector<pair<int, int>> st{{0, n}};
        unordered_set<ll> found;
        while(!st.empty()) {
            auto [l, r] = st.back(); st.pop_back();
            found.insert(s[r] - s[l]);
            int mn = a[l], mx = a[r - 1], mid = (mn + mx) / 2;
            int i_mid = upper_bound(a.begin() + l, a.begin() + r, mid) - a.begin();
            if (l < i_mid && i_mid != r) st.emplace_back(l, i_mid);
            if (i_mid < r && i_mid != l) st.emplace_back(i_mid, r);
        }
        rep(i, q) {
            ll t;
            cin >> t;
            cout << (found.find(t) != found.end() ? "Yes" : "No") << '\n';
        }
    }
}