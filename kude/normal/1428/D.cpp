#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    vector<int> ones, twos;
    vector<P> ans;
    rrep(i, n) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            ones.push_back(i);
            continue;
        }
        if (a[i] == 2) {
            twos.push_back(i);
            if (ones.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int j = ones.back(); ones.pop_back();
            ans.emplace_back(i, n-1-i);
            ans.emplace_back(j, n-1-i);
            continue;
        }
        // a[i] == 3
        if (!twos.empty()) {
            int j = twos.back(); twos.pop_back();
            ans.emplace_back(i, n-1-i);
            ans.emplace_back(j, n-1-i);
        } else if (!ones.empty()) {
            int j = ones.back(); ones.pop_back();
            ans.emplace_back(i, n-1-i);
            ans.emplace_back(j, n-1-i);
            ans.emplace_back(j, n-1-j);
        } else {
            cout << -1 << endl;
            return 0;
        }
        twos.push_back(i);
    }
    while(!ones.empty()) {
        int i = ones.back(); ones.pop_back();
        ans.emplace_back(i, n-1-i);
    }
    int sz = ans.size();
    cout << sz << '\n';
    rep(i, sz) cout << n - ans[i].second << ' ' << ans[i].first + 1 << '\n';
}