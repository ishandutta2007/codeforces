
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

typedef long double ftype;

struct pt {
    ftype x, y;
    pt(ftype x = 0, ftype y = 0) : x(x), y(y) {}
    ftype dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
    ftype norm() const {
        return x * x + y * y;
    }
    ftype len() const {
        return hypot(x, y);
    }
    ftype arg() const {
        return atan2(y, x);
    }
    pt operator+(const pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    pt operator*(const ftype &d) const {
        return pt(x * d, y * d);
    }
    pt rot() const {
        return pt(y, -x);
    }
};

const ftype EPS = 1e-12;

// pt pjline(pt a, pt b, pt p) {
//     b = b - a;
//     p = p - a;
//     return a + b * (p.dot(b) / b.dot(b));
// }
// vector<pt> linecircle(pt a, pt b, pt c, double r) {
//     pt p = pjline(a, b, c) - c;
//     if(p.norm() > r * r + EPS) return {};
//     pt v = p.rot() * sqrt(max(r * r / p.norm() - 1, 0.0));
//     return {c + p + v, c + p - v};
// }

vector<pt> circlecircle(pt a, pt b, ftype r, ftype R) {
    ftype d = (b - a).len();
    if(d > r + R || d + min(r, R) < max(r, R)) return {};
    pt p = (b - a) * (1 + (r * r - R * R) / (b - a).norm()) * 0.5;
    pt v = p.rot() * sqrtl(max(r * r / p.norm() - 1, (ftype) 0.0));
    return {a + p + v, a + p - v};
}

const int N = 2e5 + 5;
int tree[N];

void add(int k, int x) {
    while(k < N) {
        tree[k] += x;
        k += k & -k;
    }
}
int getsum(int k) {
    int sum = 0;
    while(k > 0) {
        sum += tree[k];
        k -= k & -k;
    }
    return sum;
}

ll solve(ftype r, const vector<pt> &ve) {
    int n = sz(ve);
    vector<pair<ftype, ftype>> events;
    vector<ftype> vals;
    rep(i, 0, n) {
        if(ve[i].norm() < r * r + EPS) continue;
        vector<pt> lol = circlecircle(ve[i] * 0.5, pt(), (ve[i] * 0.5).len(), r);
        assert(!lol.empty());
        ftype alpha = lol[0].arg();
        ftype beta = lol[1].arg();
        if(alpha > beta) swap(alpha, beta);
        events.emplace_back(alpha, beta);
        vals.push_back(alpha);
        vals.push_back(beta);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    auto get = [&](const ftype &f) {
        return lower_bound(all(vals), f) - vals.begin() + 1;
    };
    sort(all(events), [&](pair<ftype, ftype> &a, pair<ftype, ftype> &b) {
        return a.second > b.second;
    });
    fill(tree, tree + N, 0);
    ll ans = 1LL * n * (n - 1) / 2;
    for(auto &pa : events) {
        ftype L, R;
        tie(L, R) = pa;
        int l = get(L), r = get(R);
        ans -= getsum(r) - getsum(l);
        add(l, 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<pt> ve;
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        ve.emplace_back(x, y);
    }
    ftype L = 0, R = 1e5;
    while((R - L) > 1e-9 * max((ftype) 1.0, L)) {
        ftype m = (L + R) / 2;
        ll val = solve(m, ve);
        // cout << val << endl;
        if(val < k) {
            L = m;
        }else {
            R = m;
        }
    }
    cout << fixed << setprecision(8);
    cout << L << '\n';
}