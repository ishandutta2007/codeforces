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
    int n;
    cin >> n;
    VVI a(n);
    rep(i, n) {
        int c;
        cin >> c;
        a[i].resize(c);
        rep(j, c) cin >> a[i][j];
    }
    set<VI> banned;
    int m;
    cin >> m;
    rep(_, m) {
        VI v(n);
        rep(i, n) cin >> v[i], v[i]--;
        banned.insert(v);
    }
    set<VI> pushed;
    auto cmp = [&](const pair<int, VI>& x, const pair<int, VI>& y) {
        return x.first < y.first;
    };
    priority_queue<pair<int, VI>, vector<pair<int, VI>>, decltype(cmp)> q(cmp);
    auto push = [&](VI& build) {
        if (!pushed.count(build)) {
            pushed.insert(build);
            int sm = 0;
            rep(i, n) sm += a[i][build[i]];
            q.emplace(sm, build);
        }
    };
    VI init_vec(n);
    rep(i, n) init_vec[i] = (int)a[i].size() - 1;
    push(init_vec);
    while(true) {
        auto [sm, v] = q.top(); q.pop();
        if (!banned.count(v)) {
            rep(i, n) cout << v[i] + 1 << " \n"[i + 1 == n];
            break;
        }
        rep(i, n) {
            if (v[i]) {
                v[i]--;
                push(v);
                v[i]++;
            }
        }
    }
}