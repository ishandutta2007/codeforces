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

int n;

VI query(int r) {
    cout << "? " << r + 1 << endl;
    VI ret(n);
    rep(i, n) cin >> ret[i], ret[i];
    return ret;
}
void answer(vector<P> ans) {
    cout << "!\n";
    for(auto [x, y]: ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
    cout << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    auto depth = query(0);
    vector<P> ans;
    rep(i, n) if (depth[i] == 1) ans.emplace_back(0, i);
    int ecnt = 0, ocnt = 0;
    rep(i, n) if (depth[i] != 0) {
        if (depth[i] % 2) ocnt++;
        else ecnt++;
    }
    bool f = ecnt > ocnt;
    for(int i = 1; i < n; i++) if (depth[i] != 0 && depth[i] % 2 == f) {
        auto ret = query(i);
        for(int j = 1; j < n; j++) if (ret[j] == 1) {
            ans.emplace_back(i, j);
        }
    }
    answer(ans);
}