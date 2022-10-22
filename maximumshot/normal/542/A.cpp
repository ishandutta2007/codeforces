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
    LL x, y;
    int id;
    Node *l, *r;

    LL max_value, value;
    int max_id;

    Node() {
        y = rand() % inf64;
        x = id = -1;
        l = r = 0;

        max_value = value = -inf64;
        max_id = -1;
    }
    
    Node(LL valuE, int Id, LL Max = -inf64, int Mid = -1) {
        x = valuE;
        id = Id;
        y = rand() % inf64;
        l = r = 0;

        max_value = value = Max;
        max_id = Mid;
    }

    ~Node() {
        if(l) delete l;
        if(r) delete r;
    }

    void show() {
        if(l) l->show();
        cout << x << ' ';
        if(r) r->show();
    }

    pair<LL, int> Gmax() {
        if(r) return r->Gmax();
        return mp(x, id);
    }
};

void update(Node *& v) {
    LL tmpmax_value, tmpmax_id;
    tmpmax_value = v->value;
    tmpmax_id    = v->id;

    if(v->l) {
        if(v->l->max_value > tmpmax_value) {
            tmpmax_value = v->l->max_value;
            tmpmax_id    = v->l->max_id;
        }
    }

    if(v->r) {
        if(v->r->max_value > tmpmax_value) {
            tmpmax_value = v->r->max_value;
            tmpmax_id    = v->r->max_id;
        }
    }

    v->max_value = tmpmax_value;
    v->max_id    = tmpmax_id;
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

    if(v->x <= x) {
        split(v->r, v->r, r, x);
        l = v;
    }else {
        split(v->l, l, v->l, x);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

pair<LL, int> get_max(Node *v) {
    if(!v) return mp(-inf64, -1);
    return v->Gmax();
}

const ostream & operator << (ostream & os, const pair< pair<LL, LL>, int> & a) {
    os << a.first.first << ' ' << a.first.second << ' ' << a.second << '\n';
    return os;
}

const ostream & operator << (ostream & os, const pair< pair< pair<LL, LL>, LL>, int> & a) {
    os << a.first.first.first << ' ' << a.first.first.second << ' ' << a.first.second << ' ' << a.second << '\n';
    return os;
}

//

int n, m;
vec< pair< pair<LL, LL>, int> > a;
vec< pair< pair< pair<LL, LL>, LL>, int> > b;
vec<LL> beginC;

vec<LL> preff, suff, seg;
vec<int> idpreff, idsuff, idseg;

//

void find_preff() {

    sort(ALL(a));
    sort(ALL(b));

    int ia = 0, ib = 0;

    Node *t, *nl, *nm, *nr;
    t = 0;

    while(ib < m) {
        if(ia < n && a[ia].first.first <= b[ib].first.first.first) {
            //cout << "1 : ";
            //cout << a[ia];

            nl = nm = nr = 0;

            int l = a[ia].first.first, r = a[ia].first.second;
            int id = a[ia].second;

            split(t, nl, nr, r);
            merge(nl, nl, new Node(r, id));
            merge(t, nl, nr);

            ia++;
        }else {
            //cout << "2 : ";
            //cout << b[ib];

            nl = nm = nr = 0;

            int l, r, id;

            l = b[ib].first.first.first;
            r = b[ib].first.first.second;
            id = b[ib].second;

            pair<LL, int> G = get_max(t);

            LL tmp_val = max((LL)l, min(G.first, (LL)r));

            /*if(nl) nl->show();
            cout << "| ";
            if(nr) nr->show();
            cout << '\n';
            cout << tmp_val << "\n----------\n";*/

            tmp_val -= l;
            preff[id] = tmp_val;
            idpreff[id] = (tmp_val > 0?G.second : -1);

            ib++;
        }
    }

    /*cout << '\n';
    for(int i(0);i < m;i++) {
        cout << preff[i] << ' ' << idpreff[i] << '\n'; 
    }*/
}

void find_suff() {
    vec< pair< pair<LL, LL>, int> > ta;
    vec< pair< pair< pair<LL, LL>, LL>, int> > tb;

    int ia = 0, ib = 0;

    Node *t, *nl, *nm, *nr;
    t = 0;

    ta = a;
    tb = b;

    for(int i(0);i < n;i++) {
        int l, r, id;
        l = ta[i].first.first;
        r = ta[i].first.second;
        id = ta[i].second;
        l *= -1, r *= -1;
        swap(l, r);
        ta[i] = mp(mp(l, r), id);
    }

    for(int i(0);i < m;i++) {
        int l, r, c, id;
        l = tb[i].first.first.first;
        r = tb[i].first.first.second;
        c = tb[i].first.second;
        l *= -1, r *= -1;
        swap(l, r);
        id = tb[i].second;
        tb[i] = mp(mp(mp(l, r), c), id);
    }

    sort(ALL(ta));
    sort(ALL(tb));

    ia = ib = 0;

    /*cout << '\n';
    for(auto i : ta) cout << i;
    cout << '\n';
    for(auto i : tb) cout << i;
    cout << '\n';*/

    while(ib < m) {
        if(ia < n && ta[ia].first.first <= tb[ib].first.first.first) {
            //cout << "1 : ";
            //cout << a[ia];

            nl = nm = nr = 0;

            int l = ta[ia].first.first, r = ta[ia].first.second;
            int id = ta[ia].second;

            split(t, nl, nr, r);
            merge(nl, nl, new Node(r, id));
            merge(t, nl, nr);

            ia++;
        }else {
            //cout << "2 : ";
            //cout << b[ib];

            nl = nm = nr = 0;

            int l, r, id;

            l = tb[ib].first.first.first;
            r = tb[ib].first.first.second;
            id = tb[ib].second;

            pair<LL, int> G = get_max(t);

            LL tmp_val = max((LL)l, min(G.first, (LL)r));

            /*if(nl) nl->show();
            cout << "| ";
            if(nr) nr->show();
            cout << '\n';
            cout << tmp_val << "\n----------\n";*/

            tmp_val -= l;
            suff[id] = tmp_val;
            idsuff[id] = (tmp_val > 0?G.second : -1);

            ib++;
        }
    }

    /*cout << '\n';

    for(int i(0);i < m;i++) {
        cout << suff[i] << ' ' << idsuff[i] << '\n';
    }

    cout << '\n';*/
}

void find_seg() {
    Node *t, *nl, *nm, *nr;
    t = 0;

    vec< pair< pair<LL, LL>, int> > ta = a;
    vec< pair< pair< pair<LL, LL>, LL>, int> > tb = b;

    sort(ALL(ta), [](const pair< pair<LL, LL>, int> & p1, const pair< pair<LL, LL>, int> & p2) {
        return (p1.first.second < p2.first.second);
    });

    sort(ALL(tb), [](const pair< pair< pair<LL, LL>, LL>, int> & p1, const pair< pair< pair<LL, LL>, LL>, int> & p2) {
        return (p1.first.first.second < p2.first.first.second);
    }); 

    /*cout << '\n';
    for(auto i : ta) cout << i;
    cout << '\n';
    for(auto i : tb) cout << i;
    cout << '\n';*/

    int ia, ib;
    ia = ib = 0;

    while(ib < m) {
        if(ia < n && ta[ia].first.second <= tb[ib].first.first.second) {
            
            int l, r, id;
            l = ta[ia].first.first;
            r = ta[ia].first.second;
            id = ta[ia].second;

            nl = nm = nr = 0;;
            split(t, nl, nr, l);
            merge(nl, nl, new Node(l, id, r - l, id));
            merge(t, nl, nr);

            ia++;
        }else {
            
            int l, r, id;
            l = tb[ib].first.first.first;
            r = tb[ib].first.first.second;
            id = tb[ib].second;

            nl = nm = nr = 0;
            split(t, nl, nr, l - 1);

            LL tmp_value = max(0ll, (nr?nr->max_value : 0));

            seg[id] = tmp_value;
            if(tmp_value > 0) {
                idseg[id] = nr->max_id;
            }

            merge(t, nl, nr);

            ib++;
        }
    }

    /*cout << '\n';

    for(int i(0);i < m;i++) {
        cout << seg[i] << ' ' << idseg[i] << '\n';
    }

    cout << '\n';*/
}

bool solve()
{
    scanf("%d %d", &n, &m);

    a.resize(n);
    b.resize(m);

    for(int l, r, i(0);i < n;i++) {
        scanf("%d %d", &l, &r);
        a[i] = mp(mp(l, r), i);
    }

    for(int l, r, c, i(0);i < m;i++) {
        scanf("%d %d %d", &l, &r, &c);
        b[i] = mp(mp(mp(l, r), c), i);
        beginC.push_back(c);
    }

    /*cout << '\n';
    for(auto i : a) cout << i;
    cout << '\n';
    for(auto i : b) cout << i;
    cout << '\n';*/

    preff.resize(m, 0);
    suff.resize(m, 0);
    seg.resize(m, 0);
    idpreff.resize(m, -1);
    idsuff.resize(m, -1);
    idseg.resize(m, -1);

    find_preff();
    find_suff();
    find_seg();

    LL ans = -inf64;
    int id_vid, id_tv;
    id_vid = id_tv = -1;

    for(int i(0);i < m;i++) {
        LL tmpmax_value, tmpmax_id;
        tmpmax_value = -inf64;
        tmpmax_id = -1;

        if(preff[i] > tmpmax_value) {
            tmpmax_value = preff[i];
            tmpmax_id    = idpreff[i];
        }

        if(suff[i] > tmpmax_value) {
            tmpmax_value = suff[i];
            tmpmax_id    = idsuff[i];
        }

        if(seg[i] > tmpmax_value) {
            tmpmax_value = seg[i];
            tmpmax_id    = idseg[i];
        }

        tmpmax_value *= (LL)beginC[i];

        if(tmpmax_value > ans) {
            ans = tmpmax_value;
            id_vid = tmpmax_id + 1;
            id_tv  = i + 1;
        }
    }

    cout << ans << '\n';

    if(ans > 0) {
        cout << id_vid << ' ' << id_tv << '\n';
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}