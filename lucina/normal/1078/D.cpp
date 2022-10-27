#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MX = nax << 1;
const int inf = 1e9;

struct fast_segtree {

    int n;
    int t[MX];
    function <int(int, int)> combine;

    fast_segtree (int n, function<int(int, int)> combine) : n(n), combine(combine) {}



    void pull (int v) {
        t[v >> 1] = combine(t[v], t[v ^ 1]);
    }

    void update (int v, int val) {
        for (t[v += n] = val ; v > 1 ; v >>= 1) {
            pull(v);
        }
    }

    int query (int l, int r) {

        int res = t[l + n];
        for (l += n, r += n ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) res = combine(res, t[l ++]);
            if (r & 1) res = combine(res, t[-- r]);
        }

        return res;
    }
};

int n;
int r[nax];

int f[nax][18], g[nax][18];

int main () {
    scanf("%d", &n);


    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d", r + i);
        r[i + n] = r[i];
        r[i + n + n] = r[i];
    }

    if (n == 1) {
        return !printf("0");
    }
    const int iter = 3 * n;

    for (int i = 0 ; i < iter ; ++ i) {
        f[i][0] = max(0, i - r[i]);
        g[i][0] = min(iter - 1, i + r[i]);
    }



    typedef function<int(int, int)> func;

    func mi = [&] (int i, int j)->int{
        return min(i, j);
    };

    func ma = [&] (int i, int j)->int{
        return max(i, j);
    };


    vector <fast_segtree> min_sg(18, fast_segtree(iter, mi));
    vector <fast_segtree> max_sg(18, fast_segtree(iter, ma));

    for (int i = 0 ; i < iter ; ++ i) {

        min_sg[0].update(i, f[i][0]);
        max_sg[0].update(i, g[i][0]);
    }

    for (int j = 1 ; j < 18 ; ++ j) {
        for (int i = 0 ; i < iter ; ++ i) {
            int span_left = f[i][j - 1];
            int span_right = g[i][j - 1];
            f[i][j] = min_sg[j - 1].query(span_left, span_right + 1);
            g[i][j] = max_sg[j - 1].query(span_left, span_right + 1);
            min_sg[j].update(i, f[i][j]);
            max_sg[j].update(i, g[i][j]);
        }
    }


    for (int i = n ; i < n + n ; ++ i) {

        int ans = 0;

        int cur_l = i, cur_r = i;

        for (int j = 17 ; j >= 0 ; -- j) {
            int lb = min_sg[j].query(cur_l, cur_r + 1);
            int rb = max_sg[j].query(cur_l, cur_r + 1);
            if (rb - lb + 1 < n) {
                ans += 1 << j;
                cur_l = lb;
                cur_r = rb;
            }
        }
        printf("%d ", ans + 1);
    }

}