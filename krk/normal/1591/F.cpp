#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int a[Maxn];
vector <int> un;
ii st[Maxm];
bool fl[Maxm];
set <int> S;

void downOn(int v)
{
    swap(st[v].first, st[v].second);
    fl[v] = !fl[v];
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v);
        downOn(2 * v + 1);
        fl[v] = false;
    }
}

ii Union(const ii &a, const ii &b)
{
    return ii((a.first + b.first) % mod, (a.second + b.second) % mod);
}

ii Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Flip(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) downOn(v);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Flip(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Flip(2 * v + 1, m + 1, r, max(m + 1, a), b);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Insert(int v, int l, int r, int x, bool add, const ii &val)
{
    if (l == r)
        if (add) {
            st[v].first = (st[v].first + val.first) % mod;
            st[v].second = (st[v].second + val.second) % mod;
        } else st[v] = val;
    else {
        Down(v);
        int m = l + r >> 1;
        if (x <= m) Insert(2 * v, l, m, x, add, val);
        else Insert(2 * v + 1, m + 1, r, x, add, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    a[1] = lower_bound(un.begin(), un.end(), a[1]) - un.begin();
    Insert(1, 0, int(un.size()) - 1, a[1], true, ii(un[a[1]], 0));
    S.insert(a[1]);
    for (int i = 2; i <= n; i++) {
        a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        ii got = Get(1, 0, int(un.size()) - 1, 0, a[i]);
        got.first = ll(got.first) * un[a[i]] % mod;
        got.second = ll(got.second) * un[a[i]] % mod;
        Flip(1, 0, int(un.size()) - 1, 0, a[i]);
        while (!S.empty()) {
            auto it = S.end(); it--;
            if (*it <= a[i]) break;
            ii g = Get(1, 0, int(un.size()) - 1, *it, *it);
            Insert(1, 0, int(un.size()) - 1, *it, false, ii(0, 0));
            got.first = (ll(got.first) + ll(g.first) * un[a[i]] + ll(g.second) * Inv(un[*it]) % mod * un[a[i]]) % mod;
            got.second = (ll(got.second) + ll(g.second) * un[a[i]] + ll(g.first) * Inv(un[*it]) % mod * un[a[i]]) % mod;
            S.erase(it);
        }
        Insert(1, 0, int(un.size()) - 1, a[i], true, got);
        S.insert(a[i]);
    }
    int res = 0;
    auto it = S.end();
    while (it != S.begin()) {
        it--;
        ii g = Get(1, 0, int(un.size()) - 1, *it, *it);
        res = (res + g.first) % mod;
        res = (res - g.second + mod) % mod;
        S.erase(it++);
    }
    cout << res << endl;
    return 0;
}