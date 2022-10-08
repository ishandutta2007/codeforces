
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

const int N = 55;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    vector<pii> ve;
    rep(x, 1, n + 1) {
        int idx = x;
        while(a[idx] != x) idx++;
        if(idx == x) continue;
        int L = x, R = idx;
        ve.emplace_back(L, R);
        reverse(a + L, a + R + 1);
    }
    vector<vi> ops;
    bool b = false;
    for(auto &pa : ve) {
        int L, R;
        tie(L, R) = pa;
        if(L == 1 && R == n) {
            b = !b;
            continue;
        };
        vi v;
        rep(i, 1, L) v.push_back(1);
        v.push_back(R - L + 1);
        rep(i, R + 1, n + 1) v.push_back(1);
        if(b) reverse(all(v));
        ops.push_back(v);
        b = !b;
    }
    if(b) {
        vi v(n, 1);
        ops.push_back(v);
    }
    cout << sz(ops) << '\n';
    for(auto &v : ops) {
        cout << sz(v) << ' ';
        for(int x : v) cout << x << ' ';
        cout << '\n';
    }
}