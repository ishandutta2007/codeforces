#include<cstdio> /// faster scanf
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int B = 1e6 + 10;

struct seg {
    int where;
    int l, r;
    void read () {
        scanf("%d %d %d", &where, &l, &r);
        ++ where, ++ l, ++ r;
    }
};

struct fenwick {
    int bit[B];
    fenwick () {
        memset(bit, 0, sizeof(bit));
    }

    void update (int pos, int val) {
        for (; pos < B ; pos += pos & -pos)
            bit[pos] += val;
    }

    int get (int pos) {
        int res = 0;
        for (; pos > 0 ; pos -= pos & -pos)
            res += bit[pos];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int n, m;
// seg hor[nax];
seg ver[nax];
vector <pair <int, int>> sc[B];
vector <seg> keep[B];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        seg hor;
        hor.read();
        keep[hor.where].push_back(hor);
    }

    const int M = 1e6 + 1;

    for (int i = 1 ; i <= m;  ++ i)
        ver[i].read();
    ++ m;
    ver[m] = {M, 1, M};
    ++ m;
    ver[m] = {1, 1, M};


    int64_t ans = 1;
    for (int i = 1 ; i <= m ; ++ i) {
        auto [x, l, r] = ver[i];
        sc[l].emplace_back(x, 1);
        sc[r + 1].emplace_back(x, -1);
        if (l == 1 && r == M && i <= m - 2) ++ ans;
    }

    fenwick f;
    for (int i = 0 ; i < B ; ++ i) {
        for (auto [x, t]: sc[i]) {
            f.update(x, t);
        }

        for (auto [y, l, r] : keep[i]) {
            ans += f.get(l, r) - 1;
        }
    }

    printf("%lld\n", ans);


}