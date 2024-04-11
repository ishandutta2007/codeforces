
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

struct rat {
    ll p, q;
    rat(ll p, ll q = 1) : p(p), q(q) {
        if(q < 0) {
            p = -p;
            q = -q;
        }
        assert(q != 0);
    }
    bool operator<(const rat &o) const {
        return p * o.q < o.p * q;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi m(n), k(n);
    rep(i, 0, n) {
        cin >> m[i] >> k[i];
    }
    rat prob = 0;
    vi c;

    const int M = 2e5 + 5;
    vi p(M);
    vector<pii> ve(M);
    rep(t, 1, 20) {
        fill(all(p), 0);
        rep(i, 0, n) p[m[i]] += min(k[i], t);
        rep(i, 0, M) ve[i] = {p[i], i};
        partial_sort(ve.begin(), ve.begin() + t, ve.end(), greater<>());
        ll sum = 0;
        rep(i, 0, t) {
            sum += ve[i].first;
        }
        rat R(sum, t);
        if(prob < R) {
            prob = R;
            c.clear();
            rep(i, 0, t) c.push_back(ve[i].second);
        }
    }
    fill(all(p), 0);
    rep(i, 0, n) p[m[i]] += k[i];
    rep(i, 0, M) ve[i] = {p[i], i};
    sort(all(ve), greater<>());
    ll sum = 0;
    bool ok = false;
    int prefix = 0;
    rep(i, 0, M) {
        sum += ve[i].first;
        if(i + 1 >= 20) {
            rat R(sum, i + 1);
            if(prob < R) {
                prob = R;
                ok = true;
                prefix = i + 1;
            }
        }
    }
    if(ok) {
        c.clear();
        rep(i, 0, prefix) c.push_back(ve[i].second);
    }

    cout << sz(c) << '\n';
    for(int x : c) cout << x << ' ';
    cout << '\n';
}