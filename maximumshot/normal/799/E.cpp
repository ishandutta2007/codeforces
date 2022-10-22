#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline int nextRand() {
    return ((rand() << 16) | rand());
}

struct treap {
    struct Node {
        Node *l, *r;
        int prior;
        int cnt;
        int value;
        ll sum_value;
        Node() {
            l = 0;
            r = 0;
            prior = nextRand();
            cnt = 0;
            value = 0;
            sum_value = 0;
        }
        Node(int x) {
            l = 0;
            r = 0;
            prior = nextRand();
            cnt = 1;
            value = x;
            sum_value = x;
        }
    };

    void update(Node *& v) {
        v->sum_value = v->value;
        v->cnt = 1;
        if(v->l) {
            v->sum_value += v->l->sum_value;
            v->cnt += v->l->cnt;
        }
        if(v->r) {
            v->sum_value += v->r->sum_value;
            v->cnt += v->r->cnt;
        }
    }

    void merge(Node *& v, Node * l, Node * r) {
        if(!l || !r) {
            v = l ? l : r;
            return;
        }
        if(l->prior < r->prior) {
            merge(l->r, l->r, r);
            v = l;
        }else {
            merge(r->l, l, r->l);
            v = r;
        }
        if(v) update(v);
    }

    inline int get_cnt(Node * v) {
        return v ? v->cnt : 0;
    }

    void split_by_cnt(Node * v, Node *& l, Node *& r, int x) {
        if(!v) {
            l = r = 0;
            return;
        }
        if(get_cnt(v->l) + 1 <= x) {
            split_by_cnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
            l = v;
        }else {
            split_by_cnt(v->l, l, v->l, x);
            r = v;
        }
        if(l) update(l);
        if(r) update(r);
    }

    void split_by_value(Node * v, Node *& l, Node *& r, int x) {
        if(!v) {
            l = r = 0;
            return;
        }
        if(v->value <= x) {
            split_by_value(v->r, v->r, r, x);
            l = v;
        }else {
            split_by_value(v->l, l, v->l, x);
            r = v;
        }
        if(l) update(l);
        if(r) update(r);
    }

    Node * t;

    treap() {
        t = 0;
    }

    void insert(int value) {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_value(t, nl, nr, value);
        merge(nl, nl, new Node(value));
        merge(t, nl, nr);
    }

    void erase(int value) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_value(t, nl, nr, value);
        split_by_cnt(nl, nl, nm, get_cnt(nl) - 1);
        merge(t, nl, nr);
    }

    int size() {
        return get_cnt(t);
    }

    ll get_sum(int cnt) {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_cnt(t, nl, nr, cnt);
        ll res = nl ? nl->sum_value : 0ll;
        merge(t, nl, nr);
        return res;
    }
};

int const N = 2e5 + 5;

int n, m, k;
int cost[N];
bool ua[N];
bool ub[N];

vec< int > arrx;
vec< int > arry;
vec< int > arrz;

int main() {

    srand(time(NULL));

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &k);

    if(k > m) {
        puts("-1");
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &cost[i]);
    }

    {
        int sa;
        scanf("%d", &sa);
        for(int x, i = 0;i < sa;i++) {
            scanf("%d", &x);
            ua[x] = 1;
        }
    }

    {
        int sb;
        scanf("%d", &sb);
        for(int x, i = 0;i < sb;i++) {
            scanf("%d", &x);
            ub[x] = 1;
        }
    }

    treap tr;

    for(int i = 1;i <= n;i++) {
        if(ua[i] && ub[i]) {
            arry.push_back(cost[i]);
            tr.insert(cost[i]);
        }else if(ua[i]) {
            arrx.push_back(cost[i]);
        }else if(ub[i]) {
            arrz.push_back(cost[i]);
        }else {
            tr.insert(cost[i]);
        }
    }

    sort(ALL(arrx));
    sort(ALL(arry));
    sort(ALL(arrz));

    vec< ll > pref((int)arry.size());

    for(int i = 0;i < (int)arry.size();i++) {
        pref[i] = arry[i];
        if(i > 0) pref[i] += pref[i - 1];
    }

    ll nowx = 0;
    ll nowz = 0;
    ll nowy = 0;

    for(int val : arrx) nowx += val;
    for(int val : arrz) nowz += val;

    ll res = inf64;

    for(int cnt = 0;cnt <= (int)arry.size() && cnt <= k;cnt++) {
        if((int)arrx.size() < k - cnt || (int)arrz.size() < k - cnt) {
            if(cnt >= 0 && cnt < (int)arry.size()) {
                int add = arry[cnt];
                tr.erase(add);
                nowy += add;
            }
            continue;
        }
        while((int)arrx.size() > k - cnt) {
            int del = arrx.back();
            nowx -= del;
            tr.insert(del);
            arrx.pop_back();
        }
        while((int)arrz.size() > k - cnt) {
            int del = arrz.back();
            nowz -= del;
            tr.insert(del);
            arrz.pop_back();
        }
        if((int)arrx.size() + cnt >= k && (int)arrz.size() + cnt >= k) {
            if((int)arrx.size() + cnt + (int)arrz.size() <= m) {
                int ost = m - ((int)arrx.size() + cnt + (int)arrz.size());
                if(tr.size() >= ost) {
                    ll ost_sum = tr.get_sum(ost);
                    res = min(res, nowx + nowy + nowz + ost_sum);
                }
            }
        }
        if(cnt >= 0 && cnt < (int)arry.size()) {
            int add = arry[cnt];
            tr.erase(add);
            nowy += add;
        }
    }

    if(res == inf64) {
        cout << "-1\n";
    }else {
        cout << res << "\n";
    }

    return 0;
}