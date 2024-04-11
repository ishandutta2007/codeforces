#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

const int MAX_MEM = 6e8;

size_t mpos = 0;
char mem[MAX_MEM];

inline void* operator new(size_t n) {
    char *res = mem + mpos;
    mpos += n;
    return res;
}

inline void operator delete (void *) {
}

int t[max_n];
int n;
vector<int> v[max_n];

struct node {
    node* l = 0, *r = 0;
    node() {
        l = r = 0;
    }
    node(node* other) {
        l = other->l;
        r = other->r;
        mx = other->mx;
        add = other->add;
    }
    int mx = 0;
    int add = 0;
};


void push(node* cur, int l, int r, bool to_copy = true) {
    cur->mx += cur->add;
    int mid = (l + r) / 2;
    bool nl = 0, nr = 0;
    if (l != r && cur->l == nullptr) {
        cur->l = new node();
        cur->l->mx = mid;
        nl = true;
    }
    if (l != r && cur->r == nullptr) {
        cur->r = new node();
        cur->r->mx = r;
        nr = true;
    }

    if (l != r && !nl) {
        cur->l = new node(cur->l);
    }
    if (l != r && !nr) {
        cur->r = new node(cur->r);
    }
    if (l != r) {
        cur->l->add += cur->add;
        cur->r->add += cur->add;
    }
    cur->add = 0;
}

int lb(node *cur, int l, int r, int val, int to_add) {
    if (cur == nullptr) {
        val -= to_add;
        if (val < l) return l;
        if (val > r) return r;
        return val;
    }
    to_add += cur->add;
    if (l == r) {
        return l;
    }
    int mid = (l + r ) / 2;
    int resl = cur->l == nullptr ? mid : cur->l->mx + cur->l->add;
    if (resl + to_add >= val) {
        return lb(cur->l, l, mid, val, to_add);
    } else {
        return lb(cur->r, mid + 1, r, val, to_add);
    }
}

int get_val(node* cur, int l, int r, int pos) {
    if (cur == nullptr) {
        return pos;
    }
    if (l == r) {
        return cur->mx + cur->add;
    }
    int mid = (l + r ) / 2;
    if (pos <= mid) {
        return cur->add + get_val(cur->l, l, mid, pos);
    } else {
        return cur->add + get_val(cur->r, mid + 1, r, pos);
    }
}

int add(node* cur, int l, int r, int ql, int qr, int val){
   // cout << "QQ " << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
    //push(cur, l, r);
    if (qr < l || ql > r) {
        return cur->mx + cur->add;
    }
    if (ql == l && qr == r) {
        cur->add += val;
        //push(cur, l, r, false);
        //cout << "RET " << endl;
        return cur->mx + cur->add;
    }
    push(cur, l, r);
    int mid = (l + r ) / 2;
    int r1 = add(cur->l, l, mid, ql, min(mid, qr), val);
    int r2 = add(cur->r, mid + 1, r, max(mid + 1, ql), qr, val);
    cur->mx = max(r1, r2);
    return cur->mx;
}

node* r[max_n];

bool debug =0;
mt19937 gen(228);
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) n = 200000;
    else cin >> n;
    for (int i = 0; i < n; ++i) {
        if (debug) t[i] = gen() % 1000000000;
        else cin >> t[i];
        //comp.PB(t[i]);
        //comp.PB(t[i] - 1);
        int k = 1;
        if (!debug) cin >> k;
        for (int j=  0; j < k; ++j) {
            int a = gen() % 1000000000;
            if (!debug) cin >> a;
            v[i].PB(a);
        }
    }
    //comp.PB(1e9 + 5);
    //sort(comp.begin(), comp.end());
    //comp.erase(unique(comp.begin(), comp.end()), comp.end());
    /*for (int i = 0; i < n; ++i) {
        t[i] = get_small(t[i]);
    }*/
    int m = 1e9 + 3e5;
    r[0] = new node();
    r[0]->mx = m - 1;
    /*if (debug) {
        for (int i : comp) {
            cout << i << ' ';
        }
        cout << endl;
    }*/
    //cout << "QQ" << endl;
    for (int d = 0; d < n; ++d) {
        int ct = t[d];
        int from = lb(r[d], 0, m - 1, ct + 1, 0);

        //cout << "QQ" <<  endl;
        r[d + 1] = new node(r[d]);
        //cout << "QQ" << endl;
        if (get_val(r[d], 0, m - 1, from) > ct) {
            //cout << "QQ1 " << from << ' ' << endl;
            add(r[d + 1], 0, m - 1, from, m - 1, -1);
        }

        //cout << "QQ2" << endl;
        //cout << "QQ" << endl;
        int to = lb(r[d], 0, m - 1, ct, 0);
        --to;
        //if (debug) cout << m << ' ' << from << ' ' << to << endl;
        if (to >= 0) {
            add(r[d + 1], 0, m - 1, 0, to, 1);
        }
    }
    /*for (int d = 0; d <= n; ++d) {
        for (int j = 0; j < m; ++j) {
            cout << get_val(r[d], 0, m - 1, j) << ' ';
        }
        cout << endl;
    }*/

    int last_ans = 0;
    for (int d = 0; d < n; ++d) {
        for (int x : v[d]) {
            x = (x + last_ans) % int(1e9 + 1);
            last_ans = get_val(r[d + 1], 0, m - 1, x);// - small;
            cout << last_ans << "\n";
        }
    }
    return 0;
}