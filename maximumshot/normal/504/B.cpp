#include <iostream>
#include <cmath>
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
const ld pi = acos(-1.0);

struct Node {
    int y, cnt, value;
    Node *l, *r;

    Node() {
        l = r = 0;
        y = rand();
        cnt = 0;
        value = -1;
    }

    Node(int x) {
        y = rand();
        cnt = 1;
        value = x;
        l = r = 0;
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

void split(Node *v, Node *& l, Node *& r, int x) {
    if(!v) {
        l = r = 0;
        return;
    }

    if(get_cnt(v->l) + 1 <= x) {
        split(v->r, v->r, r, x - get_cnt(v->l) - 1);
        l = v;
    }else {
        split(v->l, l, v->l, x);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

//     [0 .. n - 1]
vec< int > Ord(const vec< int > & a) {
    int n = (int)a.size();

    vec< int > c(n), inv(n);

    for(int i = n - 1;i >= 0;i--) {
        // [0 .. a[i])
        inv[n - 1 - i] = 0;
        for(int j = a[i] - 1;j >= 0;j = (j & (j + 1)) - 1) inv[n - 1 - i] += c[j];
        for(int j = a[i];j < n;j = j | (j + 1)) c[j]++;
    }

    return inv;
}

//      ..
vec< int > sum(const vec< int > & a, const vec< int > & b) {
    int n = (int)a.size();
    vec< int > ans(n);
    for(int i = 0;i < n;i++) {
        ans[i] += a[i] + b[i];
        int c = ans[i] / (i + 1);
        if(i + 1 < n) ans[i + 1] += c;
        ans[i] %= (i + 1);
    }
    return ans;
}

//       (  [0 .. n! - 1])
vec< int > Perm(const vec< int > & a) {
    int n = (int)a.size();
    vec< int > ans(n);
    Node *t = 0, *nl, *nr, *nm;
    for(int i = 0;i < n;i++) merge(t, t, new Node(i));
    for(int i = 0;i < n;i++) {
        int id = 1 + a[n - 1 - i];
        nl = nr = nm = 0;
        split(t, nl, nr, id);
        split(nl, nl, nm, id - 1);
        ans[i] = nm->value;
        merge(t, nl, nr);
    }
    return ans;
}

bool solve()
{
    int n;

    scanf("%d", &n);

    vec< int > a(n), b(n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
    for(int i = 0;i < n;i++) scanf("%d", &b[i]);

    a = Perm(sum(Ord(a), Ord(b)));

    for(int i = 0;i < n;i++) printf("%d ", a[i]);
    puts("");

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}