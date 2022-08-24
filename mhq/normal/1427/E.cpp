#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937 rnd(228);
vector<pair<char, pair<ll, ll > >> f;
void addPlus(ll x, ll y) {
    f.emplace_back('+', make_pair(x, y));
}
void addXor(ll x, ll y) {
    f.emplace_back('^', make_pair(x, y));
}
void gen(ll from, ll mult) {
    if (mult == 1) return;
    if (mult % 2 == 0) {
        gen(from, mult / 2);
        addPlus(from * mult / 2, from * mult / 2);
    }
    else {
        gen(from, mult - 1);
        addPlus(from * (mult - 1), from);
    }
}
ll do_gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = do_gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
void go(int x) {
    int p = 1;
    while ((1 << (p + 1)) <= x) p++;
    gen(x, (1LL << p));
    ll tx = x * (1LL << p);
    addXor(tx, x);
    tx ^= x;
    assert(__gcd(tx, (ll)x) == 1);
    ll f1 = 0;
    ll f2 = 0;
    do_gcd(tx, 2 * x, f1, f2);
    ll p1 = f1 * tx;
    ll p2 = -f2 * 2 * x;
    assert(abs(p1 - p2) == 1);
    if (p1 - p2 == -1) {
        p1 *= -1;
        p2 *= -1;
    }
    if (p1 < 0) {
        p1 += 2 * x * tx;
        p2 += 2 * x * tx;
    }
    assert(p1 - p2 == 1 && p1 % tx == 0 && (p2 % (2 * x) == 0) && p1 > 0 && p2 > 0);
    gen(tx, p1 / tx);
    gen(x, p2 / x);
    assert((p1 ^ p2) == 1LL);
    addXor(p1, p2);
    assert(f.size() <= 100000);
    cout << f.size() << '\n';
    for (auto& it : f) {
        cout << it.second.first << " " << it.first << " " << it.second.second << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int x;
    cin >> x;
    go(x);
    return 0;
}