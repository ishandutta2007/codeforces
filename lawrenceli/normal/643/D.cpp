#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>
#include <ios>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 100100;

int n, q;
ll t[maxn], s[maxn];
int f[maxn], k[maxn];
set<pll> S, T[maxn];

ll ct1(int i) { return t[i] - (k[i] - 1) * (t[i] / k[i]); }
ll ct2(int i) { return t[i] / k[i]; }
ll val(int i) { return s[i] + ct2(f[i]); }
pll newp(int i) { return pll(val(i), i); }
pll newt(int i) { return pll(s[i], i); }

void ins(int i) {
    if (T[i].empty()) return;
    S.insert(newp(T[i].begin()->B));
    S.insert(newp(T[i].rbegin()->B));
}

void upd(int a, int b, int pl) {
    T[f[b]].erase(newt(b));
    T[f[f[b]]].erase(newt(f[b]));

    s[b] -= ct1(b);
    s[f[b]] -= ct2(b);
    k[b] += pl;
    s[b] += ct1(b);
    s[f[b]] += ct2(b);
    s[b] += pl * ct2(a);

    if (pl == -1) T[b].erase(newt(a));
    else T[b].insert(newt(a));

    T[f[b]].insert(newt(b));
    T[f[f[b]]].insert(newt(f[b]));

    S.insert(newp(b));
    S.insert(newp(f[b]));

    ins(b);
    ins(f[b]);
    ins(f[f[b]]);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
        k[f[i]]++;
        k[i] += 2;
    }

    for (int i = 0; i < n; i++) {
        s[i] += ct1(i);
        s[f[i]] += ct2(i);
    }

    for (int i = 0; i < n; i++) {
        S.insert(newp(i));
        T[f[i]].insert(newt(i));
    }

    for (int i = 0; i < q; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            upd(a, f[a], -1);
            f[a] = b;
            upd(a, b, 1);

            S.insert(newp(a));
        } else if (qtype == 2) {
            int a; cin >> a;
            a--;
            cout << val(a) << '\n';
        } else {
            while (1) {
                assert(!S.empty());
                pll p = *S.begin();
                if (val(p.B) != p.A) S.erase(p);
                else break;
            }

            while (1) {
                assert(!S.empty());
                pll p = *S.rbegin();
                if (val(p.B) != p.A) S.erase(p);
                else break;
            }

            cout << S.begin()->A << ' ' << S.rbegin()->A << '\n';
        }
    }
}