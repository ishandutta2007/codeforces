
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
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
};
struct city {
    pt p;
    bool b;
    int id;
};

struct tri {
    city a, b, c;
    bool ins(const pt &p) {
        return (b.p - a.p).cross(p - a.p) > 0 && (c.p - b.p).cross(p - b.p) > 0 && (a.p - c.p).cross(p - c.p) > 0;
    }
};

const int N = 1e3 + 5;
int n;
vector<city> v;
bool used[N];

vector<city> upperhull(const vector<city> &v, int n) {
    vector<city> u;
    for(int m, i = 0; i < n; i++) {
        while((m = u.size()) > 1) {
            pt p = u[m - 1].p, q = u[m - 2].p;
            if((p - q).cross(v[i].p - p) > 0) break;
            u.pop_back();
        }
        u.push_back(v[i]);
    }
    return u;
}
vector<city> hull(vector<city> &v, int n) {
    vector<city> u = upperhull(v, n);
    reverse(v.begin(), v.end());
    vector<city> l = upperhull(v, n);
    reverse(v.begin(), v.end());
    for(int i = 1; i + 1 < l.size(); i++)
        u.push_back(l[i]);
    return u;
}

vector<pii> ans;

void solve(tri T, vector<city> v) {
    v.erase(remove_if(all(v), [&](city c) {
        return used[c.id] || !T.ins(c.p);
    }), v.end());
    int cnt[2] = {0, 0};
    for(city c : {T.a, T.b, T.c}) {
        cnt[c.b]++;
    }
    bool b = (cnt[0] > cnt[1]);
    for(city &c : v) {
        if(c.b == b) {
            for(city d : {T.a, T.b, T.c}) {
                if(c.b == d.b) {
                    ans.emplace_back(c.id, d.id);
                    break;
                }
            }
            used[c.id] = true;
            solve({T.a, T.b, c}, v);
            solve({T.b, T.c, c}, v);
            solve({T.c, T.a, c}, v);
            return;
        }
    }
    city c1 = (T.a.b != b ? T.a : T.b.b != b ? T.b : T.c);
    for(city &c : v) {
        ans.emplace_back(c.id, c1.id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        pt p;
        bool b;
        cin >> p.x >> p.y >> b;
        v.push_back({p, b, i});
    }
    if(n == 1 || (n == 2 && v[0].b != v[1].b)) {
        cout << "0\n";
        return 0;
    }else if(n == 2) {
        cout << "1\n0 1\n";
        return 0;
    }
    sort(all(v), [&](city &a, city &b) {
        return make_pair(a.p.x, a.p.y) < make_pair(b.p.x, b.p.y);
    });
    vector<city> h = hull(v, n);
    vi ve;
    rep(i, 0, sz(h)) {
        if(h[i].b != h[(i + 1) % sz(h)].b) {
            ve.push_back(i);
        }else {
            ans.emplace_back(h[i].id, h[(i + 1) % sz(h)].id);
        }
    }
    if(sz(ve) > 2) {
        cout << "Impossible\n";
        return 0;
    }
    vector<tri> tris;
    for(city &c : h) {
        used[c.id] = true;
    }
    if(ve.empty()) {
        ans.pop_back();
        // find a point of the other color
        bool flag = false;
        for(city &c : v) {
            if(!used[c.id] && c.b != h[0].b) {
                used[c.id] = true;
                rep(i, 0, sz(h)) {
                    tris.push_back({h[i], h[(i + 1) % sz(h)], c});
                }
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << n - 1 << '\n';
            rep(i, 1, n) {
                cout << 0 << ' ' << i << '\n';
            }
            return 0;
        }
    }else {
        // triangulate hull in an orz way
        assert(sz(ve) == 2);
        for(int i = (ve[0] + 1) % sz(h); i != ve[1]; i = (i + 1) % sz(h)) {
            tris.push_back({h[ve[0]], h[i], h[(i + 1) % sz(h)]});
        }
        for(int i = (ve[1] + 1) % sz(h); i != ve[0]; i = (i + 1) % sz(h)) {
            tris.push_back({h[ve[1]], h[i], h[(i + 1) % sz(h)]});
        }
    }
    for(tri &T : tris) {
        solve(T, v);
    }
    cout << sz(ans) << '\n';
    for(pii &pa : ans) {
        cout << pa.first << ' ' << pa.second << '\n';
    }
}