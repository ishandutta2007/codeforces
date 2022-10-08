
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector<pii> edges;
    vector<int> dsu(n + 1, -1);
    function<int(int)> trace = [&](int x) {
        return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
    };
    auto join = [&](int x, int y) {
        if((x = trace(x)) == (y = trace(y))) return;
        if(dsu[x] > dsu[y]) swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
    };
    vi ans;
    ll si = 1;
    rep(i, 1, m + 1) {
        int k;
        cin >> k;
        if(k == 1) {
            int x;
            cin >> x;
            if(trace(0) != trace(x)) {
                join(0, x);
                si = (2 * si) % M;
                ans.push_back(i);
            }
        }else {
            int u, v;
            cin >> u >> v;
            if(trace(u) != trace(v)) {
                join(u, v);
                si = (2 * si) % M;
                ans.push_back(i);
            }
        }
    }
    cout << si << ' ' << sz(ans) << '\n';
    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}