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
    int n, m;
    cin >> n >> m;
    VI cnt(n);
    int now = n;
    auto add = [&](int i) {
        if (cnt[i] == 0) now--;
        cnt[i]++;
    };
    auto remove = [&](int i) {
        cnt[i]--;
        if (cnt[i] == 0) now++;
    };
    rep(_, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        add(min(a, b));
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            add(min(u, v));
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            remove(min(u, v));
        } else {
            cout << now << '\n';
        }
    }
}