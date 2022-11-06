#include <bits/stdc++.h>

#define szv(V) ((int)(V).size())
#define allv(V) (V).begin(), (V).end()
#define sortv(V) sort(allv(V))
#define uniquev(V) (V).erase(unique(allv(V)), (V).end())
#define compv(V) sortv(V), uniquev(V)
#define fs first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const ll inf = 4e18 + 5;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
template <class T> int sign(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign((b - a) * (c - b)); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; x %= mod; }

map<ll, int> mp;

int getIdx(ll x) {
    auto it = mp.find(x);
    if (it != mp.end()) return it->se;
    return -1;
}

struct unionfind {
    vector<int> par;
    int find(int x) {
        if (par[x] != x) return par[x] = find(par[x]);
        return x;
    }
    void merge(int x, int y) {
        par[find(y)] = find(x);
    }
} U[31];

int newP(ll x) {
    int idx = szv(mp);
    mp[x] = idx;
    for (int i = 0; i <= 30; i++) U[i].par.push_back(idx);
    return idx;
}

void query1(int l, int r, int x) {
    int L1 = getIdx(l * 2ll);
    int L2 = getIdx(l * 2ll + 1);
    int R1 = getIdx(r * 2ll + 2);
    int R2 = getIdx(r * 2ll + 3);
    if (L1 == -1) L1 = newP(l * 2ll);
    if (L2 == -1) L2 = newP(l * 2ll + 1);
    if (R1 == -1) R1 = newP(r * 2ll + 2);
    if (R2 == -1) R2 = newP(r * 2ll + 3);
    for (int i = 0; i <= 30; i++) {
        if ((x >> i) & 1) {
            U[i].merge(L1, R2);
            U[i].merge(L2, R1);
            continue;
        }
        U[i].merge(L1, R1);
        U[i].merge(L2, R2);
    }
}

int query2(int l, int r) {
    int ret = 0;
    int L = getIdx(l * 2ll);
    if (L == -1) return -1;
    int R1 = getIdx(r * 2ll + 2);
    int R2 = getIdx(r * 2ll + 3);
    for (int i = 0; i <= 30; i++) {
        int Lf = U[i].find(L);
        if (R1 != -1 && U[i].find(R1) == Lf) continue;
        if (R2 != -1 && U[i].find(R2) == Lf) {
            ret |= 1 << i;
            continue;
        }
        return -1;
    }
    return ret;
}

int q;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    int last = 0;
    while (q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) swap(l, r);
            int ret = query2(l, r);
            if (ret != -1 && ret != x) continue;
            query1(l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if (l > r) swap(l, r);
            int ret = query2(l, r);
            cout << ret << '\n';
            last = abs(ret);
        }
    }
    return 0;
}