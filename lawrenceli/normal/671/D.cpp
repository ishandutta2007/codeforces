#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cassert>
#include <ios>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 300100;

int n, m;
vector<int> adj[maxn];
vector<pii> rep[maxn];

int dep[maxn];

void dfs(int v, int p = -1) {
    dep[v] = p == -1 ? 0 : dep[p] + 1;
    for (int i : adj[v])
        if (i != p) {
            dfs(i, v);
        }
}

struct cmp {
    bool operator() (const pll& p1, const pll& p2) const {
        if (dep[p1.A] != dep[p2.A]) return dep[p1.A] > dep[p2.A];
        if (p1.B != p2.B) return p1.B > p2.B;
        return p1.A < p2.A;
    }
};

struct data {
    set<pll, cmp>* s;
    ll o; //offset
};

void ins(data& d, pll p) {
    d.s->insert(p);

    auto i = d.s->find(p);
    while (i != d.s->begin()) {
        auto j = i;
        j--;
        if (j->B < i->B) break;
        d.s->erase(j);
    }

    auto j = i; j++;
    if (j == d.s->end()) return;
    if (j->B <= i->B) d.s->erase(i);
}

data merge(data& d1, data& d2) {
    if (d1.s->size() > d2.s->size()) swap(d1, d2);
    for (auto i = d1.s->begin(); i != d1.s->end(); i++)
        ins(d2, pll(i->A, i->B + d1.o - d2.o));
    return d2;
}

data dfs2(int v, int p = 0) {
    data d = data();
    d.s = new set<pll, cmp>;

    ll sum = 0;
    for (int i : adj[v])
        if (i != p) {
            data t = dfs2(i, v);
            if (t.s->empty()) {
                cout << "-1\n";
                exit(0);
            }

            sum += t.s->begin()->B + t.o;
            t.o = -t.s->begin()->B;
            d = merge(d, t);
        }

    for (pii x : rep[v])
        ins(d, pll(x.A, x.B - d.o));

    while (1) {
        if (d.s->empty()) break;
        auto i = d.s->begin();
        if (dep[i->A] < dep[v]) break;
        if (v == 1 && dep[i->A] == 0) break;
        d.s->erase(i);
    }

    d.o += sum;
/*
    cout << v << ' ' << sum << endl;
    for (auto i = d.s->begin(); i != d.s->end(); i++)
        cout << i->A << ' ' << i->B + d.o << endl;
    cout << endl;
*/
    return d;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        rep[a].push_back(pii(b, c));
    }

    dfs(1);
    dep[0] = -1;
    rep[1].push_back(pii(0, 0));
    data d = dfs2(1);

    assert(d.s->size() <= 1);
    if (d.s->empty()) cout << "-1\n";
    else cout << d.s->begin()->B + d.o << '\n';
}