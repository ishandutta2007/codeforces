#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

struct data {
    int a[5][5];

    void initinf() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                a[i][j] = inf;
    }

    void init() {
        initinf();
        for (int i = 0; i < 5; i++) a[i][i] = 0;
    }

    data merge(const data& d) {
        data ret = data();
        ret.initinf();
        for (int i = 0; i < 5; i++)
            for (int j = i; j < 5; j++)
                for (int k = j; k < 5; k++)
                    ret.a[i][k] = min(ret.a[i][k], a[i][j] + d.a[j][k]);
        return ret;
    }
};

const int maxn = 1 << 18;

int n, q;
char s[maxn];
data t[2 * maxn];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        t[cur].init();
        if (s[lt] == '2') {
            t[cur].a[0][0] = 1;
            t[cur].a[0][1] = 0;
        } else if (s[lt] == '0') {
            t[cur].a[1][1] = 1;
            t[cur].a[1][2] = 0;
        } else if (s[lt] == '1') {
            t[cur].a[2][2] = 1;
            t[cur].a[2][3] = 0;
        } else if (s[lt] == '6') {
            t[cur].a[3][3] = 1;
            t[cur].a[4][4] = 1;
        } else if (s[lt] == '7') {
            t[cur].a[3][3] = 1;
            t[cur].a[3][4] = 0;
        }
    } else {
        int mid = (lt + rt) / 2;
        init(2 * cur, lt, mid);
        init(2 * cur + 1, mid, rt);
        t[cur] = t[2 * cur].merge(t[2 * cur + 1]);
    }
}

data qry(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) {
        data ret = data();
        ret.init();
        return ret;
    } else if (lt >= ql && rt <= qr) return t[cur];
    else {
        int mid = (lt + rt) / 2;
        return qry(2 * cur, lt, mid, ql, qr).merge(qry(2 * cur + 1, mid, rt, ql, qr));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q >> s;
    init(1, 0, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int ans = qry(1, 0, n, a - 1, b).a[0][4];
        if (ans >= inf) cout << "-1\n";
        else cout << ans << '\n';
    }
}