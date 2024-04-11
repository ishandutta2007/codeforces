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

int sqrt(int n) {
    int l = 0, r = 1000;
    while(r - l > 1) {
        int c = (l + r) / 2;
        if (c * c <= n) l = c;
        else r = c;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<P> ans;
        int to = sqrt(n);
        int cur_n = n;
        for(int now = n - 1; now > 1; now--) {
            if (now == 2) {
                while(cur_n > 1) {
                    ans.emplace_back(n, now);
                    cur_n = (cur_n + now - 1) / now;
                }
                break;
            } else if (now == to) {
                ans.emplace_back(n, now);
                cur_n = (cur_n + now - 1) / now;
                ans.emplace_back(now, n);
                to = sqrt(cur_n);
            } else {
                ans.emplace_back(now, n);
            }
        }
        cout << ans.size() << '\n';
        for(auto [a, b]: ans) {
            cout << a << ' ' << b << '\n';
        }
    }
}