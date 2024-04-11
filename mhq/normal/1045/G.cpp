#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(42);

struct Treap {
    Treap *l, *r;
    int x, y;
    int sz;

    Treap(int x)
        : l(nullptr), r(nullptr), x(x), y(rnd()), sz(1) {
    }

    Treap() {}
};
typedef Treap *pTreap;

Treap treaps[1000000];
pTreap curTreap = treaps;

inline pTreap newTreap(int x) {
    pTreap res = curTreap++;
    *res = Treap(x);
    return res;
}

inline int getSz(pTreap t) {
    return t ? t->sz : 0;
}

inline void update(pTreap t) {
    if (t) {
        t->sz = getSz(t->l) + 1 + getSz(t->r);
    }
}

inline void split(pTreap t, pTreap &l, pTreap &r, int x) {
    if (!t) {
        l = r = nullptr;
    } else {
        if (t->x >= x) {
            split(t->l, l, t->l, x);
            r = t;
        } else {
            split(t->r, t->r, r, x);
            l = t;
        }
        update(l); update(r);
    }
}

inline void merge(pTreap &t, pTreap l, pTreap r) {
    if (!l || !r) {
        t = l ? l : r;
    } else {
        if (l->y > r->y) {
            merge(l->r, l->r, r);
            t = l;
        } else {
            merge(r->l, l, r->l);
            t = r;
        }
        update(t);
    }
}

inline void insert(pTreap &t, int x) {
    pTreap l, r; split(t, l, r, x);
    merge(l, l, newTreap(x));
    merge(t, l, r);
}

inline void erase(pTreap &t, int x) {
    if (t) {
        if (t->x == x) {
            merge(t, t->l, t->r);
        } else {
            erase(x < t->x ? t->l : t->r, x);
        }
        update(t);
    }
}

inline int ranged(pTreap &t, int al, int ar) {
    pTreap l, m, r; split(t, l, m, al);
    split(m, m, r, ar+1);
    int res = getSz(m);
    merge(m, m, r); merge(t, l, m);
    return res;
}

struct Robot {
    int x, r, q;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    map<int, pTreap> robotsByIq;
    vector<Robot> v(n);
    vector< tuple<int, int, int> > events;
    for (int i = 0; i < n; i++) {
        Robot ro; cin >> ro.x >> ro.r >> ro.q;
        events.emplace_back(ro.x - ro.r, -1, i);
        events.emplace_back(ro.x, 0, i);
        events.emplace_back(ro.x + ro.r, +1, i);
        v[i] = ro;
    }
    sort(events.begin(), events.end());
    long long ans = 0;
    for (auto evt : events) {
        int qid = get<1>(evt), idx = get<2>(evt);
        Robot ro = v[idx];
        if (qid < 0) {
            insert(robotsByIq[ro.q], ro.x);
        } else if (qid == 0) {
            for (int i = ro.q-k; i <= ro.q+k; i++) {
                if (robotsByIq.count(i)) {
                    ans += ranged(robotsByIq[i], ro.x - ro.r, ro.x + ro.r);
                }
            }
            ans--;
        } else {
            erase(robotsByIq[ro.q], ro.x);
        }
    }
    assert(ans%2 == 0);
    cout << ans/2 << endl;
    return 0;
}