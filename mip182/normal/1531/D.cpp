#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e12;
const int MAXN = 1e5 + 100;
const ll INF = 1e5;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
pll t[4 * MAXN];
ll p[4 * MAXN];
int cur = 1;

void push(int v, int vl, int vr) {
    if (p[v] == 0)
        return;
    t[v].fi += p[v];
    if (vl != vr) {
        p[2 * v + 1] += p[v];
        p[2 * v + 2] += p[v];
    }
    p[v] = 0;
}

void build(int v, int vl, int vr) {
    p[v] = 0;
    if (vl == vr) {
        t[v] = {0, vl};
        return;
    }
    int mid = ((vl + vr) >> 1);
    build(2 * v + 1, vl, mid);
    build(2 * v + 2, mid + 1, vr);
    t[v] = t[2 * v + 2];
}

void update(int v, int vl, int vr, int l, int r, ll x) {
    push(v, vl, vr);
    if (vr < l || vl > r)
        return;
    if (l <= vl && vr <= r) {
        p[v] += x;
        push(v, vl, vr);
        return;
    }
    int mid = ((vl + vr) >> 1);
    update(2 * v + 1, vl, mid, l, r, x);
    update(2 * v + 2, mid + 1, vr, l, r, x);
    if (t[2 * v + 2].fi >= t[2 * v + 1].fi)
        t[v] = t[2 * v + 2];
    else
        t[v] = t[2 * v + 1];
}

pll query(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (vl > r || vr < l)
        return {-INFLL * 1000000, -INF};
    if (l <= vl && vr <= r) {
        return t[v];
    }
    int mid = ((vl + vr) >> 1);
    pll a = query(2 * v + 1, vl, mid, l, r);
    pll b = query(2 * v + 2, mid + 1, vr, l, r);
    if (a.fi > b.fi)
        return a;
    else
        return b;
}

void solve() {
    int n;
    cin >> n;
    n += 3;
    build(0, 0, n - 1);
    vector<string> what(n, "ha");
    set<int> lock, unlock;
    vector<int> val(n);
    int was_type = 2, was_pos = 0;
    update(0, 0, n - 1, 0, 0, -INFLL);
    unlock.insert(0);
    update(0, 0, n - 1, 1, 1, cur++);
    val[1] = 1;
    what[1] = "blue";
    lock.insert(n);
    for (int i = 2; i <= n - 1; i++) {
        string s;
        if (i < n - 1)
            cin >> s;
        else
            s = "unlock";
        if (s == "lock") {
            update(0, 0, n - 1, i, i, -INFLL);
            lock.insert(i);
            if (was_type == 2)
                was_type = 1, was_pos = i;
        } else if (s == "unlock") {
            update(0, 0, n - 1, i, i, -INFLL);
            unlock.insert(i);
            if (was_type == 1) {
                update(0, 0, n - 1, was_pos, i - 1, -INFLL);
            }
            was_type = 2;
            was_pos = i;
        } else {
            what[i] = s;
            val[i] = cur;
            update(0, 0, n - 1, i, i, cur++);
        }
    }
    auto get_ans = [&]() {
        int x = query(0, 0, n - 1, 0, n - 1).se;
        cout << what[x] << '\n';
    };
    get_ans();
    int q;
    cin >> q;
    while (q--) {
//        cout << "AFTER";
//        for (int i = 0; i < n; i++)
//            cout << query(0, 0, n - 1, i, i).fi << " ";
//        cout << '\n';
        int i;
        string s;
        cin >> i >> s;
        i++;
        if (lock.find(i) != lock.end()) {
            val[i] = cur++;
//            cout << "query " << query(0, 0, n - 1, i, i).fi << " " << INFLL + val[i] << '\n';
            update(0, 0, n - 1, i, i, INFLL + val[i]);
//            cout << "query " << query(0, 0, n - 1, i, i).fi << " " << INFLL + val[i] << '\n';
            update(0, 0, n - 1, i + 1, n - 1, INF);
            auto to = unlock.lower_bound(i);
            to = prev(to);
            int x = *to;
            auto too = lock.lower_bound(x);
            int y = *too;
            if (y == i) {
                int need = min((int) *lock.upper_bound(i), (int) *unlock.upper_bound(i)) - 1;
                update(0, 0, n - 1, i, need, INFLL);
            }
            lock.erase(i);
        } else if (unlock.find(i) != unlock.end()) {
            val[i] = cur++;
            update(0, 0, n - 1, i + 1, n - 1, INF);
            update(0, 0, n - 1, i, i, INFLL + val[i]);
            auto to = lock.lower_bound(i);
            if (to != lock.begin()) {
                to = prev(to);
                int x = *to;
                auto too = unlock.lower_bound(x);
                int y = *too;
                if (y == i) {
                    int need = min((int) *lock.upper_bound(i), (int) *unlock.upper_bound(i)) - 1;
                    update(0, 0, n - 1, i, need, -INFLL);
                }
            }
            unlock.erase(i);
        }
//        cout << "BEFORE\n";
//        for (int ii = 0; ii < n; ii++)
//            cout << query(0, 0, n - 1, ii, ii).fi << " ";
//        cout << '\n';
        if (s == "lock") {
            lock.insert(i);
            update(0, 0, n - 1, i, i, -INFLL - val[i]);
            auto to = unlock.lower_bound(i);
            to = prev(to);
            int x = *to;
            auto too = lock.lower_bound(x);
            int y = *too;
            if (y == i) {
                int need = min((int) *lock.upper_bound(i), (int) *unlock.upper_bound(i)) - 1;
                update(0, 0, n - 1, i, need, -INFLL);
            }
        } else if (s == "unlock") {
            unlock.insert(i);
            update(0, 0, n - 1, i, i, -INFLL - val[i]);
            auto to = lock.lower_bound(i);
            if (to != lock.begin()) {
                to = prev(to);
                int x = *to;
                auto too = unlock.lower_bound(x);
                int y = *too;
                if (y == i) {
                    int need = min((int) *lock.upper_bound(i), (int) *unlock.upper_bound(i)) - 1;
                    update(0, 0, n - 1, i, need, INFLL);
                }
            }
        } else
            what[i] = s;
        get_ans();
    }
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}