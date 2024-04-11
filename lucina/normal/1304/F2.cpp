#include<bits/stdc++.h>
using namespace std;
int const nax = 2e4 + 2;

int n, m , k;

struct Segtree {
    static const int Mx = 4 * nax;

    int sg[Mx] = {}, tag[Mx] = {};


    inline void pull (int v) {
        sg[v] = max(sg[v * 2], sg[v * 2 + 1]);
    }

    void rebuild (int v = 1, int l = 1, int r = m) {

        memset(sg, 0, sizeof(sg));
        memset(tag, 0, sizeof(tag));
    }

    inline void push (int v) {
        if (v * 2 + 1 < Mx && tag[v]) {
            sg[v * 2] +=  tag[v];
            sg[v * 2 + 1] += tag[v];
            tag[v * 2] +=  tag[v];
            tag[v * 2 + 1] += tag[v];
        }
        tag[v] = 0;
    }

    inline void update (int v, int x, int y, int l, int r , int val) {
        push(v);
        if (l > r) return ;

        if (l == x && r == y) {
            sg[v] += val; tag[v] += val;
            return push(v);
        }

        int mid = x + y >> 1;
        update(v * 2, x , mid, l, min(r, mid), val);
        update(v * 2 + 1, mid + 1, y, max(l, mid + 1), r, val);
        pull(v);
    }

    void update (int l, int r, int val) {
        update(1, 1, m, l, r, val);
    }

};

int a[52][nax];

int dp[52][nax];

int main () {

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1 ; i <= n; ++ i) {

        for (int j = 1; j <= m; ++ j) {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i][j - 1];
        }
    }


    for (int i = 1 ; i <= m ; ++ i) {
        int to = min(m, i + k - 1);
        dp[1][i] = a[1][to] - a[1][i - 1];
    }

    Segtree seg;


    for (int i = 2 ; i <= n ; ++ i) {
        seg.rebuild();


        for (int j = 1 ; j <= m ; ++ j) {
            int to = min(j + k - 1, m);
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], seg.sg[1]) + a[i][to] - a[i][j - 1]);


            int from = max(1, j - k + 1);
            seg.update(j, j, dp[i - 1][j]);
            seg.update(from, j, a[i][j] - a[i][j - 1]);


        }

        seg.rebuild();


       for (int j = m - k + 1 ; j >= 1 ; -- j) {

            int to = min(m, j + k - 1);
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], seg.sg[1]) +  a[i][to] - a[i][j - 1]);


            seg.update(j, j, dp[i - 1][j]);
            int last = min(m - k + 1, j + k - 1);
            seg.update(j, last, a[i][j + k - 1] - a[i][j + k - 2]);
        }
    }


    printf("%d\n", *max_element(dp[n] + 1, dp[n] + 1 + m));

}
/*
    Good Luck
        -Lucina
*/