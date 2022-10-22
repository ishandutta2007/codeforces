#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int , int > pii;

void upd(vec< int > & fen, int pos, int val) {
    for(int cur = pos;cur < (int)fen.size();cur |= (cur + 1))
        fen[cur] ^= val;
}

int get(const vec< int > & fen, int pos) {
    int res = 0;
    for(int cur = pos;cur > 0;cur = (cur & (cur + 1)) - 1)
        res ^= fen[cur];
    return res;
}

int get(const vec< int > & fen, int l, int r) {
    return get(fen, r) ^ get(fen, l - 1);
}

bool solve() {

    int n;

    scanf("%d", &n);

    vec< int > a(n + 1), tot(n + 1), crd;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        tot[i] = tot[i - 1] ^ a[i];
        crd.push_back(a[i]);
    }

    sort(ALL(crd));
    int sz;
    crd.resize(sz = unique(ALL(crd)) - crd.begin());

    int m;
    scanf("%d", &m);

    vec< vec< pii > > q(n + 1);
    vec< int > res(m);

    for(int l, r, i = 0;i < m;i++) {
        scanf("%d %d", &l, &r);
        q[r].push_back({l, i});
    }

    vec< int > fen(n + 1), last(sz);

    for(int l, id, p, r = 1;r <= n;r++) {
        p = lower_bound(ALL(crd), a[r]) - crd.begin();
        if(last[p]) upd(fen, last[p], a[r]);
        upd(fen, last[p] = r, a[r]);
        for(auto iter : q[r]) {
            tie(l, id) = iter;
            res[id] = tot[r] ^ tot[l - 1] ^ get(fen, l, r);
        }
    }

    for(int i = 0;i < m;i++) printf("%d\n", res[i]);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}