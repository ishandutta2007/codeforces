#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct DSU {
    int n;
    vec< int > p;

    DSU(): n(0)
    { }

    DSU(int _n): n(_n) {
        p.resize(n);
        for(int i = 0;i < n;i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        p[find(x)] = find(y);
    }
};

int solve(int n) {
    vec< pii > edge;
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            edge.push_back({i, j});
        }
    }
    sort(ALL(edge), [](pii p1, pii p2) {
        return (p1.first ^ p1.second) < (p2.first ^ p2.second);
    });
    int res = 0;
    DSU dsu(n);
    for(pii ed : edge) {
        if(dsu.find(ed.first) == dsu.find(ed.second)) {
        }else {
            dsu.merge(ed.first, ed.second);
            res += (ed.first ^ ed.second);
            cout << ed.first << " " << ed.second << "\n";
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n;

    cin >> n;

    ll res = 0;

    for(ll k = 2;k <= (2 * n);k <<= 1) {
        ll R = (2 * n - k) % (2 * k) ? (2 * n - k) / (2 * k) : (2 * n - k) / (2 * k) - 1;
        ll cnt = max(0ll, R + 1);
//        cout << k << " : " << cnt << " " << R << "\n";
        res += cnt * (k >> 1);
    }

    cout << res << "\n";

    return 0;
}