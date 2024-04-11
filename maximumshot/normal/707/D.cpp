#include <bits/stdc++.h>

#include <time.h>
#include <random>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct Node {
    Node *l, *r;
    int sum;
    bitset< 1005 > bs;

    Node() {
        sum = 0;
        l = r = 0;
        bs.reset();
    }

    Node(int x) {
        l = r = 0;
        sum = x;
    }

    Node(Node *le, Node *ri) {
        l = le;
        r = ri;
        sum = (l?l->sum : 0) + (r?r->sum : 0);
    }

    Node(Node * v) {
        l = v->l;
        r = v->r;
        sum = v->sum;
        bs = v->bs;
    }
};

bitset< 1005 > mask;

Node * build(int tl, int tr) {
    if(tl == tr) return new Node();
    else {
        int tm = (tl + tr) >> 1;
        return new Node(
            build(tl, tm),
            build(tm + 1, tr)
        );
    }
}

Node * put(Node * v, int tl, int tr, int i, int j, int val) {
    if(tl == tr) {
        Node * res = new Node(v);
        res->sum -= res->bs[j];
        res->bs[j] = val;
        res->sum += res->bs[j];
        return res;
    }else {
        int tm = (tl + tr) >> 1;
        if(i <= tm) {
            return new Node(
                    put(v->l, tl, tm, i, j, val),
                    v->r
            );
        }else {
            return new Node{
                    v->l,
                    put(v->r, tm + 1, tr, i, j, val)
            };
        }
    }
}

int n, m, q;

Node * change(Node * v, int tl, int tr, int i) {
    if(tl == tr) {
        Node * res = new Node(v);
        res->sum = m - res->sum;
        res->bs ^= mask;
        return res;
    }else {
        int tm = (tl + tr) >> 1;
        if(i <= tm) {
            return new Node(
                    change(v->l, tl, tm, i),
                    v->r
            );
        }else {
            return new Node(
                    v->l,
                    change(v->r, tm + 1, tr, i)
            );
        }
    }
}

void show(Node * v, int tl, int tr) {
    if(tl == tr) {
        cout << tl << " : ";
        for(int i = 1;i <= m;i++)
            cout << v->bs[i];
        cout << " = " << v->sum << "\n";
    }else {
        int tm = (tl + tr) >> 1;
        show(v->l, tl, tm);
        show(v->r, tm + 1, tr);
    }
}

bool solve() {

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 1;i <= m;i++) mask[i] = 1;

    vec< Node* > tr;
    tr.push_back(build(1, n));

    for(int type, i, j, k, iter = 0;iter < q;iter++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d %d", &i, &j);
            tr.push_back(put(tr.back(), 1, n, i, j, 1));
        }else if(type == 2) {
            scanf("%d %d", &i, &j);
            tr.push_back(put(tr.back(), 1, n, i, j, 0));
        }else if(type == 3) {
            scanf("%d", &i);
            tr.push_back(change(tr.back(), 1, n, i));
        }else {
            scanf("%d", &k);
            tr.push_back(tr[k]);
        }
        //cout << "\n#\n";
        //show(tr.back(), 1, n);
        printf("%d\n", tr.back()->sum);
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}