
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

const int N = 1e5 + 5;
int n;
pt a, b;
pt p[N];
int tree[4 * N];

ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = x;
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) {
        upd(2 * i + 1, l, m, k, x);
    }else {
        upd(2 * i + 2, m + 1, r, k, x);
    }
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string sa, sb;
    cin >> sa >> sb;
    for(char &c : sa) {
        if(c == '/') c = ' ';
    }
    for(char &c : sb) {
        if(c == '/') c = ' ';
    }
    stringstream ss;
    ss << sa << ' ' << sb;
    ss >> a.x >> a.y >> b.x >> b.y;
    vector<pt> v;
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
        p[i].x = -p[i].x;
        pt P(p[i].dot(a), -p[i].dot(b));
        if(P.x > 0 && P.y > 0) {
            v.push_back(P);
        }
    }
    sort(all(v), [&](pt &p1, pt &p2) {
        return make_pair(p1.x, -p1.y) < make_pair(p2.x, -p2.y);
    });
    vector<ll> vy;
    rep(i, 0, sz(v)) {
        vy.push_back(v[i].y);
    }
    sort(all(vy));
    vy.erase(unique(all(vy)), vy.end());
    int ans = 0;
    rep(i, 0, sz(v)) {
        int y = lower_bound(all(vy), v[i].y) - vy.begin();
        int val = query(0, 0, n, 0, y - 1) + 1;
        ans = max(ans, val);
        upd(0, 0, n, y, val);
    }
    cout << ans << '\n';
}