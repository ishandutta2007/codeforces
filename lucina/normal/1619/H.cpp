#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int B = 64;
int n, nq;
int p[nax];
int inv_p[nax];
int go[nax]; /// remember next B times
/**
    remember the pointer to
    next B;
    We only need to do
    B update in each merge or split operation

*/





void recalc(int idx) {
    int fst = idx;
    for (int i = 0 ; i < B ; ++ i)
        fst = p[fst];
    for (int i = 0, cur = idx ; i < B ; ++ i) {
        go[cur] = fst;
        fst = p[fst];
        cur = p[cur];
    }
}
void recalc2(int idx) {
    int fst = idx;
    for (int i = 0 ; i < B ; ++ i)
        fst = inv_p[fst];
    for (int i = 0 ; i < B ; ++ i) {
        go[fst] = idx;
        fst = p[fst];
        idx = p[idx];
    }
}

void swp() {
    int x, y;
    cin >> x >> y;

    int u = inv_p[p[x]], v = inv_p[p[y]];
    swap(p[x], p[y]);

    inv_p[p[x]] = x; inv_p[p[y]] = y;
    recalc(x); recalc(y);
    recalc2(u); recalc2(v);
}

void jump() {
    int x, k;
    cin >> x >> k;
    while (k >= B) {
        x = go[x];
        k -= B;
    }
    for (int i = 0 ; i < k ; ++ i) {
        x = p[x];
    }
    cout << x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> nq;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> p[i];
        inv_p[p[i]] = i;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        int cur = i;
        for (int j = 0 ; j < B ; ++ j)
            cur = p[cur];
        go[i] = cur;
    }

    while (nq --) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            swp();
        } else {
            jump();
        }
    }
}