#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

struct Node {
    Node* l;
    Node* r;
    ll sum;

    Node(): l(0), r(0), sum(0) { }

    Node(ll _sum): l(0), r(0), sum(_sum) { }

    Node(Node* _l, Node* _r): l(_l), r(_r) {
        sum = (_l ? _l->sum : 0ll) + (_r ? _r->sum : 0ll);
    }
};

Node* update(Node* v, int tl, int tr, int pos, ll val) {
    if(tl == tr) {
        return new Node((v ? v->sum : 0ll) + val);
    }else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            return new Node(
                update(v ? v->l : 0, tl, tm, pos, val),
                v ? v->r : 0
            );
        }else {
            return new Node(
                v ? v->l : 0,
                update(v ? v->r : 0, tm + 1, tr, pos, val)
            );
        }
    }
}

ll get_sum(Node* v, int tl, int tr, int l, int r) {
    if(!v || r < l) return 0ll;
    if(l <= tl && tr <= r) {
        return v->sum;
    }else {
        int tm = (tl + tr) / 2;
        ll res = 0;
        if(l <= tm) {
            res += get_sum(v ? v->l : 0, tl, tm, l, r);
        }
        if(r > tm) {
            res += get_sum(v ? v->r : 0, tm + 1, tr, l, r);
        }
        return res;
    }
}

const int L = 20;

char buffer[L];

inline void read_string(string& s) {
    scanf("%s", buffer);
    s = buffer;
}

const int Q = 1e5 + 5;

int q;
Node* xtree[Q];
Node* htree[Q];
unordered_map< string, int > id;
int tot = 0;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &q);

    string type;

    xtree[0] = 0;
    htree[0] = 0;

    for(int iter = 1;iter <= q;iter++) {
        read_string(type);
        if(type == "set") {
            string a;
            read_string(a);
            int x;
            scanf("%d", &x);
            if(!id.count(a)) {
                id[a] = ++tot;
            }
            int pos = id[a];
            ll cur_value = get_sum(htree[iter - 1], 1, q, pos, pos);
            ll add = ll(x) - cur_value;
            xtree[iter] = update(xtree[iter - 1], 0, inf, cur_value, -1);
            xtree[iter] = update(xtree[iter], 0, inf, x, +1);
            htree[iter] = update(htree[iter - 1], 1, q, pos, add);
        }else if(type == "remove") {
            string a;
            int x = 0;
            read_string(a);
            if(!id.count(a)) {
                id[a] = ++tot;
            }
            int pos = id[a];
            ll cur_value = get_sum(htree[iter - 1], 1, q, pos, pos);
            ll add = ll(x) - cur_value;
            xtree[iter] = update(xtree[iter - 1], 0, inf, cur_value, -1);
            xtree[iter] = update(xtree[iter], 0, inf, x, +1);
            htree[iter] = update(htree[iter - 1], 1, q, pos, add);
        }else if(type == "query") {
            string a;
            read_string(a);
            if(!id.count(a)) {
                id[a] = ++tot;
            }
            int pos = id[a];
            ll cur_value = get_sum(htree[iter - 1], 1, q, pos, pos);
            if(cur_value == 0) {
                puts("-1");
            }else {
                printf("%d\n", int(get_sum(xtree[iter - 1], 0, inf, 1, int(cur_value) - 1)));
            }
            fflush(stdout);
            xtree[iter] = xtree[iter - 1];
            htree[iter] = htree[iter - 1];
        }else if(type == "undo") {
            int d;
            scanf("%d", &d);
            xtree[iter] = xtree[iter - d - 1];
            htree[iter] = htree[iter - d - 1];
        }
    }

    return 0;
}