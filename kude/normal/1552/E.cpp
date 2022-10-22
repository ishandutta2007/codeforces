#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    VI c(n * k);
    rep(i, n * k) cin >> c[i], c[i]--;
    vector<int> pre(n, -1);
    vector<P> ans(n);
    vector<char> done(n);
    VI cnt(n * k);
    int mx = (n + k - 2) / (k - 1);
    rep(i, n * k) {
        int x = c[i];
        if (done[x]) continue;
        if (pre[x] == -1) {
            pre[x] = i;
            continue;
        }
        bool ok = true;
        for(int j = pre[x]; j < i; j++) if (cnt[j] >= mx) {
            ok = false;
            break;
        }
        if (!ok) {
            pre[x] = i;
            continue;
        }
        ans[x] = {pre[x], i};
        done[x] = true;
        for(int j = pre[x]; j <= i; j++) cnt[j]++;
    }
    rep(i, n) {
        auto [l, r] = ans[i];
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}