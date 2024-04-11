#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_q = 3 * max_n, inf = 1000000111;

struct query {
    int l, r, ind;
};

int m[max_n], ans[max_q];
vector<pair<int, int> > a;
query q[max_q];
vector<int> ngb[max_n];
int n, qnum;

struct segment_tree {
    int tree[max_n * 4];
    int mem[max_n * 4];
    segment_tree() {
        for(int i = 0; i < max_n * 4; ++i) {
            mem[i] = inf;
            tree[i] = inf;
        }
    }

    void push(int cur, int l, int r) {
        if (mem[cur] == inf) return;
        if (l == r) {
            tree[cur] = min(tree[cur], mem[cur]);
            mem[cur] = inf;
            return;
        }
        mem[cur * 2] = min(mem[cur * 2], mem[cur]);
        mem[cur * 2 + 1] = min(mem[cur * 2 + 1], mem[cur]);
        tree[cur] = min(tree[cur], mem[cur]);
        mem[cur] = inf;
    }

    int get(int cur, int l, int r, int ind) {
        push(cur, l, r);
        if (l == r) {
            return tree[cur];
        }

        int mid = (l + r) / 2;
        if (ind <= mid) {
            return get(cur * 2, l, mid, ind);
        } else {
            return get(cur * 2 + 1, mid + 1, r, ind);
        }
    }

    void set_min(int cur, int l, int r, int sl, int sr, int val) {
        push(cur, l, r);
        if (l == sl && r == sr) {
            mem[cur] = val;
            push(cur, l, r);
            return;
        }

        if (l > sr || r < sl) return;

        int mid = (l + r) / 2;

        set_min(cur * 2, l, mid, sl, min(sr, mid), val);
        set_min(cur * 2 + 1, mid + 1, r, max(sl, mid + 1), sr, val);
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
    }
} st;

// Can answer queries "first(minimal) element >= given from l to r inclusively"
struct casc_segment_tree {
    vector<int> tree[max_n * 4];
    vector<pair<int, int> > ch[max_n * 4];

    void merge_children(int cur)
    {
        vector<int> &l = tree[cur * 2], &r = tree[cur * 2 + 1], &v = tree[cur];
        vector<pair<int, int> > &p = ch[cur];
        int il = 0, ir = 0;
        while(true) {
            if (il == l.size() && ir == r.size()) break;
            if (ir == r.size() || il < l.size() && l[il] <= r[ir]) {
                v.pb(l[il]);
                p.pb(mp(il, ir));
                ++il;
            } else {
                v.pb(r[ir]);
                p.pb(mp(il, ir));
                ++ir;
            }
        }

    }

    void build(int cur, int l, int r) {
        if (l == r) {
            tree[cur].pb(a[l].S);
            return;
        }

        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        merge_children(cur);
    }

    int get(int cur, int l, int r, int ql, int qr, int ind)
    {
        if (ind == tree[cur].size()) {
            return inf;
        }
        if (l == ql && r == qr) {
            return tree[cur][ind];
        }

        if (l > qr || r < ql) {
            return inf;
        }

        int mid = (l + r) / 2;
        return min(get(cur * 2, l, mid, ql, min(qr, mid), ch[cur][ind].F),
                   get(cur * 2 + 1, mid + 1, r, max(ql, mid + 1), qr, ch[cur][ind].S));
    }

    int get_first(int value, int l, int r) {
        int ind = lower_bound(tree[1].begin(), tree[1].end(), value) - tree[1].begin();
        if (ind == tree[1].size()) {
            return inf;
        }
        return get(1, 0, n - 1, l, r, ind);
    }
} cst;

// all inclusive; returns index
int get_next(int from_ind, int from, int to) {
    vector<pair<int, int> >:: iterator st, fin;
    st = lower_bound(a.begin(), a.end(), mp(from, -10));
    fin = lower_bound(a.begin(), a.end(), mp(to + 1, -10));
    if (fin == a.begin()) return inf;
    fin--;
    int l = st - a.begin(), r = fin - a.begin();
    if (r < l) return inf;
    return cst.get_first(from_ind, l, r);

}

void find_neighbours() {
    for (int i = 0; i < n; ++i) {
        int ind = get_next(i + 1, m[i], inf);
        while(ind < n) {
            ngb[i].pb(ind);
            if (m[i] == m[ind]) break;
            ind = get_next(ind + 1, m[i], (m[i] + m[ind]) / 2);
        }
    }
}

void answer_queries() {
    int curq = qnum - 1;
    for (int lb = n - 1; lb >= 0; --lb) {
        for (int to : ngb[lb]) {
            st.set_min(1, 0, n - 1, to, n - 1, m[to] - m[lb]);
        }
        while(curq >= 0 && q[curq].l == lb) {
            ans[q[curq].ind] = min(ans[q[curq].ind], st.get(1, 0, n - 1, q[curq].r));
            curq--;
        }
    }
}

void solve() {
    sort(a.begin(), a.end());
    cst.build(1, 0, n - 1);
    find_neighbours();
    answer_queries();
}

void clr() {
    a.clear();
    for (int i = 0; i < n; ++i) {
        ngb[i].clear();
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
        a.pb(mp(m[i], i));
    }
    scanf("%d", &qnum);
    int l, r;
    for (int i = 0; i < qnum; ++i) {
        ans[i] = inf;
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].l--, q[i].r--;
        q[i].ind = i;
    }
    sort(q, q + qnum, [](const query &q1, const query &q2) {return q1.l < q2.l;});
    solve();

    //--------------------------------------REVERSE

    clr();
    for (int i = 0; i < n; ++i) {
        a.pb(mp(m[n - i - 1], i));
    }
    reverse(m, m + n);
    for (int i = 0; i < qnum; ++i) {
        q[i].l = n - q[i].l - 1;
        q[i].r = n - q[i].r - 1;
        swap(q[i].l, q[i].r);
    }

    sort(q, q + qnum, [](const query &q1, const query &q2) {return q1.l < q2.l;});
    st = segment_tree();
    cst = casc_segment_tree();
    solve();

    for (int i = 0; i < qnum; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}