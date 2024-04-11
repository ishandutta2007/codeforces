#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <time.h>

//#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 7;
const double pi = acos(-1.0);

using namespace std;

int n, k, a;

struct Node {
    Node *l, *r;
    LL y;
    int le, ri, sum, cnt, value;

    Node() {
        l = r = 0;
        y = rand() % base;
        le = ri = -1;
        sum = cnt = value = 0;
    }

    Node(int L, int R) {
        l = r = 0;
        y = rand() % base;
        le = L;
        ri = R;
        cnt = 1;
        sum = value = (ri - le + 2) / (a + 1);
    }
};

void update(Node *& v) {
    int s = v->value;
    int c = 1;
    if(v->l) s += v->l->sum, c += v->l->cnt;
    if(v->r) s += v->r->sum, c += v->r->cnt;
    v->sum = s;
    v->cnt = c;
}

int get_sum(Node *v) {
    return (v?v->sum : 0);
}

int get_cnt(Node *v) {
    return (v?v->cnt : 0);
} 

void merge(Node *& v, Node *l, Node *r) {
    if(!l || !r) {
        v = (l?l : r);
        return;
    }

    if(l->y >= r->y) {
        merge(l->r, l->r, r);
        v = l;
    }else {
        merge(r->l, l, r->l);
        v = r;
    }

    if(v) update(v);
}

void splitByValue(Node *v, Node *& l, Node *& r, int x) {
    if(!v) {
        l = r = 0;
        return;
    } 

    if(v->le > x) {
        splitByValue(v->l, l, v->l, x);
        r = v;
    }else {
        splitByValue(v->r, v->r, r, x);
        l = v;
    }

    if(l) update(l);
    if(r) update(r); 
}

void splitByCnt(Node *v, Node *& l, Node *& r, int c) {
    if(!v) {
        l = r = 0;
        return;
    }

    if(get_cnt(v->l) + 1 <= c) {
        splitByCnt(v->r, v->r, r, c - get_cnt(v->l) - 1);
        l = v;
    }else {
        splitByCnt(v->l, l, v->l, c);
        r = v;
    }

    if(l) update(l); 
    if(r) update(r);
}

bool solve()
{
    scanf("%d %d %d", &n, &k, &a);
    Node *t = 0, *nl, *nm, *nr;

    t = new Node(1, n);

    int m, x;
    scanf("%d", &m);

    for(int h = 1;h <= m;h++) {
        scanf("%d", &x);
        splitByValue(t, nl, nr, x);
        splitByCnt(nl, nl, nm, get_cnt(nl) - 1);
        int le, ri;
        le = nm->le;
        ri = nm->ri;
        if(le <= x - 1) merge(nl, nl, new Node(le, x - 1));
        if(x + 1 <= ri) merge(nl, nl, new Node(x + 1, ri));
        merge(t, nl, nr);
        if(get_sum(t) < k) {
            cout << h << '\n';
            return true;
        }
    }

    cout << -1 << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}