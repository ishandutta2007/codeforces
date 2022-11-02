#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 1<<18;

int n, m, k;
char s[maxn];

struct data {
    int num[10][10];
    char l, r;
} tree[2 * maxn];
char lazy[2 * maxn];

data merge(data d1, data d2) {
    data ret = data();
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            ret.num[i][j] = d1.num[i][j] + d2.num[i][j];

    ret.num[d1.r - 'a'][d2.l - 'a']++;
    ret.l = d1.l, ret.r = d2.r;
    return ret;
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        tree[cur].l = tree[cur].r = s[lt];
    } else {
        int mid = (lt + rt) / 2;
        init(2 * cur, lt, mid);
        init(2 * cur + 1, mid, rt);
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
    }
}

void push(int cur, int lt, int rt) {
    if (!lazy[cur]) return;

    memset(tree[cur].num, 0, sizeof(tree[cur].num));
    char c = lazy[cur];
    tree[cur].num[c - 'a'][c - 'a'] = rt - lt - 1;
    tree[cur].l = tree[cur].r = c;

    if (lt + 1 != rt) {
        lazy[2 * cur] = lazy[2 * cur + 1] = c;
    }
    lazy[cur] = 0;
}

void upd(int cur, int lt, int rt, int ql, int qr, char c) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = c;
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2 * cur, lt, mid, ql, qr, c);
        upd(2 * cur + 1, mid, rt, ql, qr, c);
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
    }
}

char qs[20];
int oc[20];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k >> s;
    init(1, 0, n);
    for (int i = 0; i < m; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int l, r;
            char c;
            cin >> l >> r >> c;
            upd(1, 0, n, l - 1, r, c);
        } else {
            cin >> qs;
            for (int j = 0; j < k; j++) oc[qs[j] - 'a'] = j;

            int ans = 1;
            data d = tree[1];
            for (int l = 0; l < 10; l++)
                for (int r = 0; r < 10; r++)
                    if (oc[l] >= oc[r])
                        ans += d.num[l][r];
            cout << ans << '\n';
        }
    }
}