#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <time.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

struct Node {
    Node *l, *r;
    ll y;
    ll key, value, mx_value;

    Node() {
        l = r = 0;
        y = rand();
        key = value = mx_value = -inf64;
    }

    Node(ll _key, ll _value) {
        l = r = 0;
        y = rand();
        key = _key;
        value = mx_value = _value;
    }
};

void update(Node *& v) {
    ll mx = v->value;
    if(v->l) mx = max(mx, v->l->mx_value);
    if(v->r) mx = max(mx, v->r->mx_value);
    v->mx_value = mx;
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

void split(Node *v, Node *& l, Node *& r, ll key) {
    if(!v) {
        l = r = 0;
        return;
    }

    if(v->key <= key) {
        split(v->r, v->r, r, key);
        l = v;
    }else {
        split(v->l, l, v->l, key);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

bool solve() {

    int n, x1, x2;

    scanf("%d %d %d", &n, &x1, &x2);

    vec< pair< int, int> > a(n + 1);
    // {k, b}

    for(int k, b, i = 1;i <= n;i++) {
        scanf("%d %d", &k, &b);
        a[i] = mp(k, b);
    }

    sort(a.begin() + 1, a.end());
    
    Node *t, *nl, *nm, *nr;
    t = 0;

    for(int i = 1;i <= n;i++) {
        ll key, value;
        key = (ll)x2 * (ll)a[i].first + (ll)a[i].second;
        value = (ll)x1 * (ll)a[i].first + (ll)a[i].second;

        nl = nm = nr = 0;

        split(t, nl, nr, key - 1);
        
        if(nl && nl->mx_value > value) {
            puts("YES");
            return true;
        }

        merge(nl, nl, new Node(key, value));
        merge(t, nl, nr);

    }

    t = 0;

    for(int i = n;i >= 1;i--) {
        ll key, value;
        key = (ll)x1 * (ll)a[i].first + (ll)a[i].second;
        value = (ll)x2 * (ll)a[i].first + (ll)a[i].second;

        nl = nm = nr = 0;

        split(t, nl, nr, key - 1);
        
        if(nl && nl->mx_value > value) {
            puts("YES");
            return true;
        }

        merge(nl, nl, new Node(key, value));
        merge(t, nl, nr);
    }

    puts("NO");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}