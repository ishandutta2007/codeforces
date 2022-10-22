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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf * 1000ll + 17;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

struct Node {
    LD x, y, cnt;
    Node *l, *r;
    
    Node() {
        x = cnt = 0;
        y = rand() % inf;
        l = r = 0;
    }

    Node(LD val) {
        x = val;
        y = rand() % inf;
        cnt = 1;
        l = r = 0;
    }

    void show() {
        if(l) l->show();
        cout << x << ' ';
        if(r) r->show();
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

void split(Node *v, Node *& l, Node *& r, LL x) {
    if(!v) {
        l = r = 0;
        return;
    }

    if(v->x < x) {
        split(v->r, v->r, r, x);
        l = v;
    }else {
        split(v->l, l, v->l, x);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

bool solve()
{
    int n;
    scanf("%d", &n);

    vec< pair<int, int> > a;

    map<int, int> m;

    for(int x, y, i(0);i < n;i++) {
        scanf("%d %d", &x, &y);
        if(m.count(x) == 0) m[x] = x;
        if(m.count(y) == 0) m[y] = y;
        swap(m[x], m[y]);
    }

    vec<int> mas;

    for(map<int, int>::iterator i = m.begin();i != m.end();i++) {
        mas.push_back(i->second);
    }

    set< pair<int, int> > s;

    LL ans = 0;
    
    Node *t, *nl, *nm, *nr, *T, *Tnl, *Tnr, *Tnm;
    t = 0; // val
    T = 0; // pos

    vec< pair<int, int> > p;

    for(map<int, int>::iterator i = m.begin();i != m.end();i++) {
        p.push_back(*i);
    }

    for(int i(0);i < (int)p.size();i++) {
        int val, pos;
        pos = p[i].first;
        val = p[i].second;

        //cout << pos << ' ' << val << " : ";

        nl = nm = nr = 0;
        split(t, nl, nr, val + 1);
        //cout << (nr?nr->cnt : 0) << '\n';
        ans += (nr?nr->cnt : 0);
        merge(nl, nl, new Node(val));
        merge(t, nl, nr);
        
        Tnl = Tnr = Tnm = 0;

        // [val + 1 .. pos - 1]

        if(val + 1 <= pos - 1) {
            split(T, Tnl, Tnr, val + 1);
            int empty = pos - 1 - val - (Tnr?Tnr->cnt : 0);
            merge(T, Tnl, Tnr);
            ans += empty;
            Tnl = Tnr = Tnm = 0;
        }
    
        split(T, Tnl, Tnr, pos);
        merge(Tnl, Tnl, new Node(pos));
        merge(T, Tnl, Tnr);
    }

    t = 0;
    T = 0;

    for(int i((int)p.size() - 1);i >= 0;i--) {
        int val, pos;
        pos = p[i].first;
        val = p[i].second;
        
        // [pos + 1 .. val - 1]

        Tnl = Tnr = Tnm = 0;

        if(pos + 1 <= val  - 1) {
            split(T, Tnl, Tnr, val);
            int empty = val - 1 - pos - (Tnl?Tnl->cnt : 0);
            merge(T, Tnl, Tnr);
            ans += empty;
            Tnl = Tnr = Tnm = 0;
        }

        split(T, Tnl, Tnr, pos);
        merge(Tnl, Tnl, new Node(pos));
        merge(T, Tnl, Tnr);
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}