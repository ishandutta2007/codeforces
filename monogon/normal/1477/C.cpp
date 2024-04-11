
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    ll dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> p(n);
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
    }
    vi perm(n);
    rep(i, 0, n) {
        perm[i] = i;
    }
    bool ok = true;
    while(ok) {
        ok = false;
        rep(i, 0, n - 2) {
            if((p[i + 1] - p[i]).dot(p[i + 2] - p[i + 1]) >= 0) {
                swap(p[i + 1], p[i + 2]);
                swap(perm[i + 1], perm[i + 2]);
                ok = true;
            }
        }
    }
    rep(i, 0, n) {
        cout << perm[i] + 1 << ' ';
    }
    cout << '\n';
}