#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
typedef long long ll;
int n, mod;
const int maxN = (int)1e5 + 10;
int my_pows[65][65];
void norm(pair < ll, ll >& t, ll a, ll b) {
    ll shift = (-t.first) / b;
    t.first += shift * b;
    t.second -= shift * a;
}
// for coprimes
pair < ll, ll > euclid(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    if (a == 0) return make_pair(0, 1);
    if (a < b) {
        auto t1 = euclid(b, a);
        swap(t1.first, t1.second);
        norm(t1, a, b);
        return t1;
    }
    auto t = euclid(a % b, b);
    // (a - (a / b) * b) * t.first + b * t.second = 1
    // a * t.first + b * (t.second - (a / b) * t.first) = 1;
    //
    pair < ll, ll > s = make_pair(t.first, t.second - (a / b) * t.first);
    norm(s, a, b);
    return s;
}
ll find_inv(ll a, ll b) {
    auto t = euclid(a, b);
    // a * x + b * y = 1 -> a * x = 1 mod b
    if (t.first < 0) {
        ll shift = (-t.first) / b;
        t.first += shift * b;
    }
    if (t.first > 0) {
        ll shift = t.first / b;
        t.first -= shift * b;
    }
    while (t.first < 0) {
        t.first += b;
    }
    while (t.first >= b) {
        t.first -= b;
    }
    return t.first;
}
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
const ll INF = (ll)1e18;
ll safe_mult(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > (INF / b)) return INF;
    return a * b;
}
ll lcm(ll a, ll b) {
    return safe_mult(a, b / gcd(a, b));
}
vector < pair < ll, ll > > get_fact(ll x) {
    vector < pair < ll, ll > > cur;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
            int exp = 0;
            while (x % i == 0) {
                x /= i;
                exp++;
            }
            cur.emplace_back(i, exp);
        }
    }
    if (x > 1) cur.emplace_back(x, 1);
    return cur;
}
ll get(ll a1, ll m1, ll a2, ll m2) {
    if (m1 < m2) {
        swap(m1, m2);
        swap(a1, a2);
    }
    if (m2 == 1) {
        return a1;
    }
    // m1 * x + a1 = m2 * y + a2
    // m1 * x + a1 - a2
    ll res = (((a2 - a1) % m2 + m2) % m2);
    ll inv_m1 = find_inv(m1, m2);
    //assert(safe_mult(inv_m1, res) < INF);
    // x = inv_m1 * res
    ll x = (inv_m1 * res) % m2;
    return (x * m1 + a1);
}
ll crt(vector < pair < ll, ll > > vals) {
    ll cur_mod = 1;
    ll cur_res = 0;
    for (auto t : vals) {
        cur_res = get(t.first, t.second, cur_res, cur_mod);
        cur_mod *= t.second;
    }
    return cur_res;
}
const int lim = sqrt(2 * (int)1e9);
int mult(int a, int b, int mod) {
    if (mod <= lim) return (a * b) % mod;
    return (1LL * a * b) % mod;
}
int sum(int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int pw(int a, int b, int mod) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1, mod), mod);
    int res = pw(a, b / 2, mod);
    return mult(res, res, mod);
}
vector < int > my_mods;




vector < int > t[4 * maxN];
vector < pair < int, int > > lazy[4 * maxN];
vector < pair < ll, ll > > pr;
vector < pair < int, int > > construct(int x) {
    vector < pair < int, int > > cur(pr.size(), make_pair(0, 0));
    int cop = x;
    for (int i = 0; i < pr.size(); i++) {
        int exp = 0;
        int all_pw = 1;
        while (cop % pr[i].first == 0) {
            cop /= pr[i].first;
            all_pw *= pr[i].first;
            exp++;
        }
        cur[i] = make_pair(exp, (x / all_pw) % my_mods[i]);
    }
    return cur;
}
vector < pair < int, int > > unite(vector < pair < int, int > >& a, vector < pair < int, int > >& b) {
    vector < pair < int, int > > cur(a.size(), make_pair(0, 0));
    for (int i = 0; i < a.size(); i++) {
        cur[i].first = a[i].first + b[i].first;
        cur[i].second = mult(a[i].second, b[i].second, my_mods[i]);
    }
    return cur;
}
void try_upd(int v, int tl, int tr) {
    if (tl != tr) return ;
    for (int i = 0; i < t[v].size(); i++) {
        if (lazy[v][i].first >= pr[i].second) {
            t[v][i] = 0;
        } else {
            t[v][i] = mult(lazy[v][i].second, my_pows[i][lazy[v][i].first], my_mods[i]);
        }
    }
}
void push(int v, int tl, int tr) {
    if (tl == tr) {
        return ;
    }
    bool ok = true;
    for (int i = 0; i < lazy[v].size(); i++) {
        if (lazy[v][i] != make_pair(0, 1)) {
            ok = false;
            break;
        }
    }
    if (ok) return ;
    for (int i = 0; i < t[v].size(); i++) {
        if (lazy[v][i].first >= pr[i].second) {
            t[v][i] = 0;
        }
        else {
            t[v][i] = mult(t[v][i], mult(lazy[v][i].second, my_pows[i][lazy[v][i].first], my_mods[i]), my_mods[i]);
        }
    }
    if (tl < tr) {
        lazy[2 * v] = unite(lazy[2 * v], lazy[v]);
        try_upd(2 * v, tl, (tl + tr) / 2);
    }
    if (tl < tr) {
        lazy[2 * v + 1] = unite(lazy[2 * v + 1], lazy[v]);
        try_upd(2 * v + 1, (tl + tr) / 2 + 1, tr);
    }
    lazy[v] = vector < pair < int, int > >(pr.size(), make_pair(0, 1));
}
vector < int > get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (tl == l && tr == r) {
        if (tl == tr) {
            for (int i = 0; i < t[v].size(); i++) {
                if (lazy[v][i].first >= pr[i].second) {
                    t[v][i] = 0;
                } else {
                    t[v][i] = mult(lazy[v][i].second, my_pows[i][lazy[v][i].first], my_mods[i]);
                }
            }
        }
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(v + v, tl, tm, l, r);
    else if (l > tm) return get(v + v + 1, tm + 1, tr, l, r);
    else {
        auto t1 = get(v + v, tl, tm, l, tm);
        auto t2 = get(v + v + 1, tm + 1, tr, tm + 1, r);
        for (int i = 0; i < t1.size(); i++) {
            t1[i] = sum(t1[i], t2[i], my_mods[i]);
        }
        return t1;
    }
}
void upd(int v, int tl, int tr, int l, int r, vector < pair < int, int > >& coef) {
    if (tl == l && tr == r) {
        lazy[v] = unite(lazy[v], coef);
        push(v, tl, tr);
        if (tl == tr) {
            for (int i = 0; i < t[v].size(); i++) {
                if (lazy[v][i].first >= pr[i].second) {
                    t[v][i] = 0;
                } else {
                    t[v][i] = mult(lazy[v][i].second, my_pows[i][lazy[v][i].first], my_mods[i]);
                }
            }
        }
        return ;
    }
    push(v, tl, tr);
    if (l > r) return ;
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, min(r, tm), coef);
    upd(v + v + 1, tm + 1, tr, max(tm + 1, l), r, coef);
    for (int i = 0; i < t[v].size(); i++) {
        t[v][i] = sum(t[v + v][i], t[v + v + 1][i], my_mods[i]);
    }
}
int a[maxN];
void build(int v, int tl, int tr) {
    lazy[v].resize(pr.size(), make_pair(0, 1));
    if (tl == tr) {
        lazy[v] = construct(a[tl]);
        t[v].resize(pr.size());
        for (int i = 0; i < t[v].size(); i++) {
            t[v][i] = a[tl] % my_mods[i];
        }
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v].resize(t[v + v].size());
    for (int i = 0; i < t[v].size(); i++) {
        t[v][i] = sum(t[v + v][i], t[v + v + 1][i], my_mods[i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pr = get_fact(mod);
    my_mods.resize(pr.size());
    for (int i = 0; i < pr.size(); i++) {
        my_mods[i] = 1;
        for (int j = 0; j < pr[i].second; j++) {
            my_mods[i] *= pr[i].first;
        }
    }
    for (int i = 0; i < pr.size(); i++) {
        for (int j = 0; j < pr[i].second; j++) {
            my_pows[i][j] = pw(pr[i].first, j, my_mods[i]);
        }
    }
    build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            auto tt = construct(x);
            upd(1, 1, n, l, r, tt);
        }
        else if (tp == 2) {
            int p, x;
            cin >> p >> x;
            auto tt = construct(x);
            for (int i = 0; i < tt.size(); i++) {
                tt[i].first = -tt[i].first;
                tt[i].second = find_inv(tt[i].second, my_mods[i]);
            }
            upd(1, 1, n, p, p, tt);
        }
        else {
            int l, r;
            cin >> l >> r;
            auto tt = get(1, 1, n, l, r);
            vector < pair < ll, ll > > for_crt;
            for (int i = 0; i < tt.size(); i++) {
                for_crt.emplace_back(tt[i], my_mods[i]);
            }
            cout << crt(for_crt) << '\n';
        }
    }
}