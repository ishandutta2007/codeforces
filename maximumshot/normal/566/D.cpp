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
#include <list>
#include <cstring>

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
const double pi = acos(-1.0);

using namespace std;

struct Node {
    LL y;
    Node *l, *r;
    int boss, left, right, cnt;
    Node() {
        l = r = 0;
        y = rand() % base;
        boss = -1;
        left = right = -1;
        cnt = 0;
    }
    Node(int Boss, int L, int R) {
        y = rand() % base;
        l = r = 0;
        boss = Boss;
        left = L;
        right = R;
        cnt = 1;
    }
};

void update(Node *& v) {    
    int c = 1;
    if(v->l) c += v->l->cnt;
    if(v->r) c += v->r->cnt;
    v->cnt = c;
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

int get_cnt(Node *v) {
    return (v?v->cnt : 0);
}

void splitByCnt(Node *v, Node *& l, Node *& r, int x) {
    if(!v) {
        l = r = 0;
        return;
    }

    if(get_cnt(v->l) + 1 <= x) {
        splitByCnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
        l = v;
    }else {
        splitByCnt(v->l, l, v->l, x);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

void splitByValue(Node *v, Node *& l, Node *& r, int id) {
    if(!v) {
        l = r = 0;
        return;
    }

    if(v->left <= id) {
        splitByValue(v->r, v->r, r, id);
        l = v;
    }else {
        splitByValue(v->l, l, v->l, id);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

vec< int > par, size;

int find(int x) {
    return (par[x] == x?x : par[x] = find(par[x]));
}

void merge(int x, int y) {
    int px, py;
    px = find(x);
    py = find(y);
    if(size[px] == size[py]) {
        par[py] = px;
        size[px]++;
    }else {
        if(size[px] < size[py]) swap(px, py);
        par[py] = px;
    }
}

void Do(Node *v, vec< Node* > & Mas) {
    if(v->l) Do(v->l, Mas);
    Mas.push_back(v);
    if(v->r) Do(v->r, Mas);
}

bool solve()
{      
    int n, q;

    scanf("%d %d", &n, &q);

    par.resize(n + 1);
    size.resize(n + 1);

    Node *t, *nl, *nm, *nr, *qm;
    t = 0;

    for(int i = 1;i <= n;i++) {
        par[i] = i;
        size[i] = 1;
        merge(t, t, new Node(i, i, i));
    }

    int type, x, y;

    while(q--) {
        nl = nm = nr = 0;
        scanf("%d %d %d", &type, &x, &y);
        if(type == 3) {
            puts(find(x) == find(y)?"YES" : "NO");
        }else {
            if(type == 1) {
                merge(x, y);
            }else {
                nl = nm = nr = qm = 0;
                splitByValue(t, nl, nr, x);
                splitByCnt(nl, nl, nm, get_cnt(nl) - 1);
                splitByValue(nr, qm, nr, y);
                merge(nm, nm, qm);
                vec< Node* > T;
                Do(nm, T);
                int L, R;
                L = T.front()->left;
                R = T.back()->right;
                for(int j = 0;j < (int)T.size() - 1;j++) {
                    merge(T[j]->boss, T[j + 1]->boss);
                }
                merge(nl, nl, new Node(find(T[0]->boss), L, R));
                merge(t, nl, nr);
            }
        }
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}