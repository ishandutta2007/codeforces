#include<bits/stdc++.h>
using namespace std;
int const nax = 1e4 + 10;
using ll = long long;
ll const inf = 1e16;
int n, m, k;
vector <int> both;
vector <int> a;
vector <int> b;
vector <int> no;
vector < pair <int, int>> has;

struct node {
    int sub_size;
    long long sum;

    node () : sub_size() , sum () {}
    node (int sub_size, long long sum) : sub_size(sub_size), sum(sum) {}

    friend node merge (node lft, node rgh) {
        return node(lft.sub_size + rgh.sub_size, lft.sum + rgh.sum);
    }
};

bool is_leaf[nax];

struct segment_tree {

    static const int lim = 1e4;
    node sg[nax << 2];
    bool is_leaf[nax << 2];

    segment_tree () {
        memset(is_leaf, false, sizeof(is_leaf));
        for (int i = 0 ; i < (nax * 4) ; ++ i)
            sg[i] = node();
    }

    void build (int v, int l, int r) {
        if (l == r) {
            is_leaf[v] = true;
            return;
        }
        int mid = l + r >> 1;
        build(v << 1, l, mid);
        build(v << 1 ^ 1, mid + 1, r);
    }

    void add (int v, int x, int y, int pos, int sgn) {

        if (x == pos && y == pos) {
            sg[v].sub_size += sgn;
            sg[v].sum += pos * sgn;
            return ;
        }

        int mid = x + y >> 1;
        if (pos <= mid) add(v << 1, x, mid, pos, sgn);
        else add(v << 1 ^ 1, mid + 1, y, pos, sgn);
        sg[v] = merge(sg[v << 1], sg[v << 1 ^ 1]);
    }

    void sum_k (int v, int x, int y, long long &sum, int &res) {
        int lf = v << 1;
        int mid = x + y >> 1;
        if (is_leaf[v]) {
            int to_sub = min(res, sg[v].sub_size);
            res -= to_sub;
            sum += 1LL * x * to_sub;
            return ;
        }

        if (sg[lf].sub_size <= res) {
            sum += sg[lf].sum;
            res -= sg[lf].sub_size;
            return sum_k(v << 1 ^ 1, mid + 1, y, sum, res);
        }

        sum_k(v << 1, x, mid, sum, res);
    }

    void ins (int pos) {
        add(1, 1, lim, pos, 1);
    }

    void era (int pos) {
        add(1, 1, lim, pos, -1);
    }

    long long sum_k_smallest (int k) {
        long long sum = 0;
        sum_k(1, 1, lim, sum, k);
        return k > 0 ? inf : sum;
    }
};

segment_tree segtree;

vector <int> pref_sum (vector <int> &v) {
    if (v.empty()) return vector<int>();
    vector <int> res;
    res.resize(int(v.size()));
    res[0] = v[0];

    for (int i = 1 ; i < (int)v.size() ; ++ i)
        res[i] = res[i - 1] + v[i];
    return res;

}

int main () {

    segtree.build(1, 1, int(1e4));
    scanf("%d %d %d", &n, &m, &k);

    map <int, vector <int> > map_for_both, map_for_a, map_for_b, map_for_no;

    for (int i = 1 ; i <= n ; ++ i) {
        int t, la, lb;
        scanf("%d %d %d", &t, &la, &lb);
        if (la && lb) {
            both.push_back(t);
            map_for_both[t].push_back(i);
        } else if (la){
            a.push_back(t);
            map_for_a[t].push_back(i);
        } else if (lb) {
            b.push_back(t);
            map_for_b[t].push_back(i);
        } else {
            segtree.ins(t);
            map_for_no[t].push_back(i);
            has.push_back({t, 3});
        }
    }

    sort(both.begin(), both.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    vector <int> pref_both = pref_sum(both);
    vector <int> pref_a = pref_sum(a);
    vector <int> pref_b = pref_sum(b);

    bool ok = false;

    int pt_a = (int)a.size() - 1, pt_b = (int)b.size() - 1;

    for (int i : both) {
        segtree.ins(i);
    }

    int pos_pref_both = -1;
    int pos_pref_a = -1;
    int pos_pref_b = -1;
    int need_res = -1;

    ll ans = inf;

    for (int i = 0 ; i <= (int)both.size() ; ++ i) {
        ll c = i ? pref_both[i - 1] : 0;
        int need = max(0, k - i);

        while (pt_a >= need && pt_a >= 0) {
            segtree.ins(a[pt_a -- ]);
        }

        while (pt_b >= need && pt_b >= 0) {
            segtree.ins(b[pt_b -- ]);
        }

        if (min(pt_a, pt_b) + 1 >= need) {
            if (need)
            c += pref_a[need - 1] + pref_b[need - 1];
            int want = m - i - need * 2;
            if (want >= 0) {

                ll res = segtree.sum_k_smallest(want) + c;

                if (res < ans) {
                    ans = res;
                    pos_pref_both = i - 1;
                    pos_pref_a = need - 1;
                    pos_pref_b = need - 1;
                    need_res = want;
                }

            }
        }

        if (i < both.size()) {
            segtree.era(both[i]);
        }
    }

    if (ans == inf) return !printf("%lld\n", -1LL);
    printf("%lld\n", ans);


    vector <int> res;

    for (int j = 0 ; j <= pos_pref_both ; ++ j) {
        res.push_back(map_for_both[both[j]].back());
        map_for_both[both[j]].pop_back();
    }

    for (int j = 0 ; j <= pos_pref_a ; ++ j) {
        res.push_back(map_for_a[a[j]].back());
        map_for_a[a[j]].pop_back();

    }

    for (int j = 0 ; j <= pos_pref_b ; ++ j) {
        res.push_back(map_for_b[b[j]].back());
        map_for_b[b[j]].pop_back();
    }

    for (int j = pos_pref_both + 1 ; j < (int)both.size() ; ++ j) {
        has.emplace_back(both[j], 0);
    }

    for (int j = pos_pref_a + 1 ; j < (int)a.size() ; ++ j) {
        has.emplace_back(a[j], 1);
    }

    for (int j = pos_pref_b + 1 ; j < (int)b.size() ; ++ j) {
        has.emplace_back(b[j], 2);
    }

    sort(has.begin(), has.end());

    for (int i = 0 ; i < need_res ; ++ i) {
        int x = has[i].first;
        if (has[i].second == 0) {
            res.push_back(map_for_both[x].back());
            map_for_both[x].pop_back();
        }
        if (has[i].second == 1) {
            res.push_back(map_for_a[x].back());
            map_for_a[x].pop_back();
        }

        if (has[i].second == 2) {
            res.push_back(map_for_b[x].back());
            map_for_b[x].pop_back();
        }

        if (has[i].second == 3) {
            res.push_back(map_for_no[x].back());
            map_for_no[x].pop_back();
        }
    }

    for (int i : res) {
        printf("%d ", i);
    }
    printf("\n");



}