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
    return (rand() << 16) | rand();
}

struct TreapVector {
    struct Node {
        Node *l;
        Node *r;
        int sum_cnt;
        int key1;
        int key2;
        int prior;
        int push_value;
        int KEY;
        int MIN_KEY;
        int MAX_KEY;
        Node() {
            l = 0;
            r = 0;
            sum_cnt = 0;
            key1 = 0;
            key2 = 0;
            prior = nextRand();
            push_value = 0;
            KEY = 0;
            MIN_KEY = 0;
            MAX_KEY = 0;
        }
        Node(int _key1, int _key2) {
            l = 0;
            r = 0;
            sum_cnt = 1;
            key1 = _key1;
            key2 = _key2;
            prior = nextRand();
            push_value = 0;
            KEY = 2 * key1 - key2;
            MIN_KEY = KEY;
            MAX_KEY = KEY;
        }
    };

    inline void update(Node *& v) {
        v->sum_cnt = 1;
        v->MIN_KEY = v->KEY;
        v->MAX_KEY = v->KEY;
        if(v->l) {
            v->MIN_KEY = min(v->MIN_KEY, v->l->MIN_KEY);
            v->MAX_KEY = max(v->MAX_KEY, v->l->MAX_KEY);
            v->sum_cnt += v->l->sum_cnt;
        }
        if(v->r) {
            v->MIN_KEY = min(v->MIN_KEY, v->r->MIN_KEY);
            v->MAX_KEY = max(v->MAX_KEY, v->r->MAX_KEY);
            v->sum_cnt += v->r->sum_cnt;
        }
    }

    void push(Node *& v) {
        if(v->push_value != 0) {
            if(v->l) {
                v->l->push_value += v->push_value;
                v->l->key2 += v->push_value;

                v->l->KEY -= v->push_value;
                v->l->MIN_KEY -= v->push_value;
                v->l->MAX_KEY -= v->push_value;
            }
            if(v->r) {
                v->r->push_value += v->push_value;
                v->r->key2 += v->push_value;

                v->r->KEY -= v->push_value;
                v->r->MIN_KEY -= v->push_value;
                v->r->MAX_KEY -= v->push_value;
            }
            v->push_value = 0;
        }
    }

    void inc(Node *& v) {
        v->push_value++;
        v->key2++;

        v->KEY--;
        v->MIN_KEY--;
        v->MAX_KEY--;
    }

    void merge(Node *& v, Node * l, Node * r) {
        if(l) push(l);
        if(r) push(r);
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

    void split_by_key1(Node * v, Node *& l, Node *& r, int x) {
        if(!v) {
            l = r = 0;
            return;
        }
        push(v);
        if(v->key1 <= x) {
            split_by_key1(v->r, v->r, r, x);
            l = v;
        }else {
            split_by_key1(v->l, l, v->l, x);
            r = v;
        }
        if(l) update(l);
        if(r) update(r);
    }

    void split_by_key2(Node * v, Node *& l, Node *& r, int x) {
        if(!v) {
            l = r = 0;
            return;
        }
        push(v);
        if(v->key2 <= x) {
            split_by_key2(v->r, v->r, r, x);
            l = v;
        }else {
            split_by_key2(v->l, l, v->l, x);
            r = v;
        }
        if(l) update(l);
        if(r) update(r);
    }

    inline int get_cnt(Node * v) const {
        return v ? v->sum_cnt : 0;
    }

    void split_by_cnt(Node * v, Node *& l, Node *& r, int x) {
        if(!v) {
            l = r = 0;
            return;
        }
        push(v);
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

    Node * t;

    void dfs(Node * v, int pos, int ptr, int & res) {
        if(!v) return;
        push(v);
        dfs(v->l, pos, ptr, res);
//        int j = v->key2 - v->key1;
//        int perm_j = v->key1 + ptr;
//        int sz = get_cnt(t) + ptr;
//        cout << j << " x = " << perm_j << " sz = " << sz << "\n";
//        res = min(res, min(perm_j, j - ptr + 1) + sz - 1 - j);
        cout << 2 * v->key1 - v->key2 << " "
             << 2 * v->key1 - v->key2 + 2 * ptr + get_cnt(t) - 1 << " "
             << get_cnt(t) << " with ptr = " << ptr << "\n";

        if(2 * v->key1 - v->key2 <= 1 - 2 * ptr) {
            res = min(res, 2 * v->key1 - v->key2 + 2 * ptr + get_cnt(t) - 1);
        }else {
            res = min(res, get_cnt(t));
        }
        dfs(v->r, pos, ptr, res);
    }

    int get_value(int ptr) {
        int res = inf;
        dfs(t, 0, ptr, res);
        return res;
    }

    void go(Node * v) {
        if(!v) return;
        push(v);
        go(v->l);
        cout << "{" << v->key1 << " " << v->key2 << "} ";
        go(v->r);
    }

    void show() {
        go(t);
    }

    TreapVector() : t(0) { }

    void insert(int key1, int key2) {
//        cout << "t insert " << key1 << " " << key2 << "\n";
        Node *nl, *nr;
        nl = nr = 0;
        split_by_key2(t, nl, nr, key2);
//        go(nl); cout << " | "; go(nr); cout << " = ";
        merge(nl, nl, new Node(key1, key2));
//        go(nl); cout << " + "; go(nr); cout << " = ";
        merge(t, nl, nr);
//        go(t); cout << "\n";
    }

    inline int size() const {
        return get_cnt(t);
    }

    bool empty() const {
        return get_cnt(t) == 0;
    }

    pii back() {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_cnt(t, nl, nr, get_cnt(t) - 1);
        pii res = make_pair(nr->key1, nr->key2);
        merge(t, nl, nr);
        return res;
    }

    pii front() {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_cnt(t, nl, nr, 1);
        pii res = make_pair(nl->key1, nl->key2);
        merge(t, nl, nr);
        return res;
    }

    void pop_back() {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_cnt(t, nl, nr, get_cnt(t) - 1);
        t = nl;
    }

    void pop_front() {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_cnt(t, nl, nr, 1);
        t = nr;
    }

    int count_leq1(int x) {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_key1(t, nl, nr, x);
        int res = get_cnt(nl);
        merge(t, nl, nr);
        return res;
    }

    int count_leq2(int x) {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_key2(t, nl, nr, x);
        int res = get_cnt(nl);
        merge(t, nl, nr);
        return res;
    }

    void inc(int x) { // key1 > x then key2++
        Node *nl, *nr;
        nl = nr = 0;
        split_by_key1(t, nl, nr, x);
        if(nr) inc(nr);
        merge(t, nl, nr);
    }

    void push_back(int key1, int key2) {
        merge(t, t, new Node(key1, key2));
    }

    void push_front(int key1, int key2) {
        merge(t, new Node(key1, key2), t);
    }

    int get_min(int ptr) {
        if(!t) return inf;
        int mn = t->MIN_KEY;
        int mx = t->MAX_KEY;
        int res = inf;
        if(mn <= 1 - 2 * ptr) {
            res = min(res, mn + 2 * ptr + get_cnt(t) - 1);
        }
        if(mx > 1 - 2 * ptr) {
            res = min(res, get_cnt(t));
        }
        return res;
    }
};

int const N = 5e5 + 5;

int n;
int a[N];
int fast[N];

void Fast() {
    TreapVector L, R;

    for(int i = 1;i <= n;i++) {
//        cout << i << " show\n";
        int pos = L.count_leq1(a[i]) + R.count_leq1(a[i]);
//        cout << "pos : " << pos << "\n";
        L.inc(a[i]);
        R.inc(a[i]);
        if(!L.empty() && L.back().first > a[i]) {
            L.insert(a[i], a[i] + pos);
        }else {
            R.insert(a[i], a[i] + pos);
        }
        while(!L.empty()) {
            pii tmp = L.back();
            if(tmp.second < 0) break;
            L.pop_back();
            R.push_front(tmp.first, tmp.second);
        }
        while(!R.empty()) {
            pii tmp = R.front();
            if(tmp.second >= 0) break;
            R.pop_front();
            L.push_back(tmp.first, tmp.second);
        }
        int cur = -L.size();
        int diff = R.get_min(L.size());
        if(diff == inf) diff = 0;
//        cout << "ptr = " << L.size() << "\n";
//        cout << "L : "; L.show(); cout << " size = " << L.size() << "\n";
//        cout << "R : "; R.show(); cout << " size = " << R.size() << "\n";
//        cout << "diff = " << diff << " cur = " << cur << "\n";
        fast[i] = diff + cur;
    }
}

void read() {
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
}

void print() {
    for(int i = 1;i <= n;i++) {
        printf("%d\n", fast[i]);
    }
}

int main() {

    srand(time(NULL));

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    read();
    Fast();
    print();

    return 0;
}