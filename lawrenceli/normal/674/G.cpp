#include <bits/stdc++.h>

using namespace std;

struct data {
    int cnt[5], id[5];
    int k;

    void init(int _k) {
        k = _k;
        memset(cnt, 0, sizeof(cnt));
        memset(id, 0, sizeof(id));
    }

    void init(int _k, int i) {
        init(_k);
        cnt[0] = 1, id[0] = i;
    }

    void merge(const data& d) {
        for (int i = 0; i < k; i++)
            if (d.cnt[i] > 0) {
                assert(d.id[i] != 0);
                bool has_same = false;
                for (int j = 0; j < k; j++)
                    if (id[j] == d.id[i]) {
                        assert(d.id[i] != 0);
                        cnt[j] += d.cnt[i];
                        has_same = true;
                        break;
                    }

                if (!has_same) {
                    int mi = d.cnt[i];
                    for (int j = 0; j < k; j++)
                        if (cnt[j] < mi)
                            mi = cnt[j];

                    bool ins = false;
                    for (int j = 0; j < k; j++) {
                        cnt[j] -= mi;
                        if (!cnt[j]) {
                            if (!ins) {
                                cnt[j] = d.cnt[i] - mi;
                                if (!cnt[j]) id[j] = 0;
                                else id[j] = d.id[i];
                                ins = true;
                            } else id[j] = 0;
                        }
                    }
                }
            }
    }

    void fill(int i, int amo) {
        memset(cnt, 0, sizeof(cnt));
        memset(id, 0, sizeof(id));
        cnt[0] = amo; id[0] = i;
    }

};

struct Tree {
    static const int S = 1 << 18;
    int k;
    data t[2 * S];
    int l[2 * S];

    void init(int cur, int lt, int rt, int* ar) {
        if (lt + 1 == rt) t[cur].init(k, ar[lt]);
        else {
            int mid = (lt + rt) / 2;
            init(2 * cur, lt, mid, ar);
            init(2 * cur + 1, mid, rt, ar);
            t[cur] = t[2 * cur];
            t[cur].merge(t[2 * cur + 1]);
        }
    }

    void push(int cur, int lt, int rt) {
        if (!l[cur]) return;
        t[cur].fill(l[cur], rt - lt);
        if (lt + 1 < rt) {
            int mid = (lt + rt) / 2;
            l[2 * cur] = l[cur];
            l[2 * cur + 1] = l[cur];
        }
        l[cur] = 0;
    }

    void upd(int cur, int lt, int rt, int ql, int qr, int id) {
        push(cur, lt, rt);
        if (rt <= ql || lt >= qr) return;
        else if (lt >= ql && rt <= qr) {
            l[cur] = id;
            push(cur, lt, rt);
        } else {
            int mid = (lt + rt) / 2;
            upd(2 * cur, lt, mid, ql, qr, id);
            upd(2 * cur + 1, mid, rt, ql, qr, id);
            t[cur] = t[2 * cur];
            t[cur].merge(t[2 * cur + 1]);
        }
    }

    data qry(int cur, int lt, int rt, int ql, int qr) {
        push(cur, lt, rt);
        if (rt <= ql || lt >= qr) {
            data d = data();
            d.init(k);
            return d;
        } else if (lt >= ql && rt <= qr) {
            return t[cur];
        } else {
            int mid = (lt + rt) / 2;
            data ret = qry(2 * cur, lt, mid, ql, qr);
            ret.merge(qry(2 * cur + 1, mid, rt, ql, qr));
            return ret;
        }
    }

} tree;

const int maxn = 150100;

int n, m, p, k;
int ar[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &p);
    k = 100 / p;

    for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
    tree.k = k;
    tree.init(1, 0, n, ar);

    for (int i = 0; i < m; i++) {
        int qtype; scanf("%d", &qtype);
        if (qtype == 1) {
            int l, r, id;
            scanf("%d %d %d", &l, &r, &id);
            l--;
            tree.upd(1, 0, n, l, r, id);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            data d = tree.qry(1, 0, n, l, r);
            printf("%d ", k);
            for (int j = 0; j < k; j++) {
                if (d.id[j] != 0) printf("%d ", d.id[j]);
                else printf("%d ", ar[l]);
            }
            printf("\n");
        }
    }
}