#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;
const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void _addsum(int &x, int y) {
    x = _sum(x, y);
}

inline void _addmul(int &x, int y) {
    x = _mul(x, y);
}

int n, q;
set< pii > segs[N];
int pu[4 * N];
pii delt[4 * N];
int sm[4 * N];

void make(int v, int tl, int tr, int type, int x) {
    pu[v] = 1;
    if(type == 1) { // add
        _addsum(delt[v].second, x);
        _addsum(sm[v], _mul(tr - tl + 1, x));
    }else { // mul
        _addmul(delt[v].first, x);
        _addmul(delt[v].second, x);
        _addmul(sm[v], x);
    }
}

void push(int v, int tl, int tm, int tr) {
    if(pu[v]) {
        make(v << 1, tl, tm, 2, delt[v].first);
        make(v << 1, tl, tm, 1, delt[v].second);
        make(v << 1 | 1, tm + 1, tr, 2, delt[v].first);
        make(v << 1 | 1, tm + 1, tr, 1, delt[v].second);
        delt[v] = make_pair(1, 0);
        pu[v] = 0;
    }
}

void mrg(int v) {
    sm[v] = _sum(sm[v << 1], sm[v << 1 | 1]);
}

void update(int v, int tl, int tr, int l, int r, int type, int x) {
    if(l <= tl && tr <= r) {
        make(v, tl, tr, type, x);
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if(l <= tm) update(v << 1, tl, tm, l, r, type, x);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, type, x);
        mrg(v);
    }
}

int get_sum(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return sm[v];
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        int res = 0;
        if(l <= tm) _addsum(res, get_sum(v << 1, tl, tm, l, r));
        if(r > tm) _addsum(res, get_sum(v << 1 | 1, tm + 1, tr, l, r));
        mrg(v);
        return res;
    }
}

inline bool is_intersect(int l1, int r1, int l2, int r2) {
    return max(l1, l2) <= min(r1, r2);
}

void insert(int l, int r, int x) {
    auto &a = segs[x];

    if(a.empty()) {
        a.insert({l, r});
        update(1, 1, n, l, r, 1, 1);
        return;
    }

    set< pii > inters;

    auto fnd = a.lower_bound(make_pair(l, r));

    { // move left
        auto it = fnd;
        if(it == a.end()) it--;
        while(is_intersect(it->first, it->second, l, r)) {
            inters.insert(*it);
            if(it != a.begin()) it--;
            else break;
        }
        if(it != a.begin() && it != a.end()) {
            it--;
            if(is_intersect(it->first, it->second, l, r)) {
                inters.insert(*it);
            }
        }
        if(it != a.begin() && it != a.end()) {
            it--;
            if(is_intersect(it->first, it->second, l, r)) {
                inters.insert(*it);
            }
        }
        if(it != a.begin() && it != a.end()) {
            it--;
            if(is_intersect(it->first, it->second, l, r)) {
                inters.insert(*it);
            }
        }
    }

    { // move right
        auto it = fnd;
        while(it != a.end() && is_intersect(it->first, it->second, l, r)) {
            inters.insert(*it);
            it++;
        }
        if(it != a.end()) {
            it++;
            if(it != a.end() && is_intersect(it->first, it->second, l, r)) {
                inters.insert(*it);
            }
        }
        if(it != a.end()) {
            it++;
            if(it != a.end() && is_intersect(it->first, it->second, l, r)) {
                inters.insert(*it);
            }
        }
        if(it != a.end()) {
            it++;
            if(it != a.end() && is_intersect(it->first, it->second, l, r)) {
                inters.insert(*it);
            }
        }
    }

    if(inters.empty()) {
        a.insert({l, r});
        update(1, 1, n, l, r, 1, 1);
        return;
    }

    for(pii pr : inters) {
        a.erase(pr);
    }

    vec< pii > arr(inters.begin(), inters.end());

    if(l < arr.front().first) {
        update(1, 1, n, l, arr.front().first - 1, 1, 1);
    }

    for(int i = 0;i + 1 < (int)arr.size();i++) {
        if(arr[i].second + 1 <= arr[i + 1].first - 1) {
            update(1, 1, n, arr[i].second + 1, arr[i + 1].first - 1, 1, 1);
        }
    }

    if(arr.back().second < r) {
        update(1, 1, n, arr.back().second + 1, r, 1, 1);
    }

    for(pii pr : arr) {
        int le = max(l, pr.first);
        int ri = min(r, pr.second);
        if(le <= ri) {
            update(1, 1, n, le, ri, 2, 2);
        }
    }

    a.insert({min(l, arr.front().first), max(arr.back().second, r)});
}

int query(int l, int r) {

//    for(int i = 1;i <= n;i++) {
//        cout << i << " : ";
//        for(pii pr : segs[i]) {
//            cout << pr.first << " .. " << pr.second << " | ";
//        }
//        cout << "\n";
//    }

    return get_sum(1, 1, n, l, r);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    for(int i = 0;i < 4 * N;i++) {
        delt[i] = {1, 0};
    }

    scanf("%d %d", &n, &q);

    for(int iter = 0;iter < q;iter++) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            insert(l, r, x);
        }else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(l, r));
        }
    }

    return 0;
}