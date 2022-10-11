#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int M = 2000, N = 2000;

int m, n, q, u, l, r, cnt[M];
bitset<N> bi[M], que[N + 1];
set<pair<int, int>> se;
set<int> ava;

void add(set<pair<int, int>>::iterator it) {
    if (it == se.end() && it != se.begin()) {
        ava.erase(se.rbegin()->se);
    }
    if (it == se.begin() || it == se.end()) {
        return;
    }
    int u = prev(it)->se, v = it->se;
    if ((bi[u] & bi[v]).count() == cnt[u]) {
        ava.erase(u);
    } else {
        ava.insert(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> q;
    for (int i = 0; i < n; i++) {
        que[i + 1] = que[i];
        que[i + 1].set(i);
    }
    for (int i = 0; i < m; i++) {
        se.insert({cnt[i], i});
    }
    while (q--) {
        cin >> u >> l >> r;
        u--; l--; r--;
        add(se.erase(se.find({cnt[u], u})));
        bi[u] ^= que[r + 1] ^ que[l];
        cnt[u] = bi[u].count();
        auto it = se.insert({cnt[u], u}).fi;
        add(it);
        add(next(it));
        if (ava.empty()) {
            cout << "-1\n";
        } else {
            int hi = *ava.begin();
            int lo = se.upper_bound({cnt[hi], hi})->se;
            bitset<M> cur = bi[hi] ^ bi[lo];
            int le = (cur & bi[hi])._Find_first();
            int ri = (cur & bi[lo])._Find_first();
            if (le > ri) {
                swap(le, ri);
            }
            if (hi > lo) {
                swap(hi, lo);
            }
            cout << hi + 1 << " " << le + 1 << " " << lo + 1 << " " << ri + 1 << '\n';
        }
    }
}