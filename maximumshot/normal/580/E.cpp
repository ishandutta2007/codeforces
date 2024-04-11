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
const ld pi = 3.1415926535897932384626433832795;

const ll mod1 = inf + 9;
const ll mod2 = inf + 21;
const ll p = 113ll;
const int N = 100100;

ll w1[N];
ll w2[N];

struct Hash {
    
    ll len, val1, val2;

    Hash() {
        len = val1 = val2 = 0;
    }

    Hash(int x) {
        len = 1;
        val1 = val2 = x;
    }

    Hash operator + (const Hash & b) {
        Hash ans;
        ans.len = len + b.len;
        ans.val1 = (val1 * w1[b.len] + b.val1) % mod1;
        ans.val2 = (val2 * w2[b.len] + b.val2) % mod2;
        return ans;
    }

    Hash operator - (const Hash & b) {
        Hash ans;
        ans.len = len - b.len;
        ans.val1 = val1 - w1[len - b.len] * b.val1; 
        ans.val2 = val2 - w2[len - b.len] * b.val2;
        ans.val1 = (ans.val1 % mod1 + mod1) % mod1;
        ans.val2 = (ans.val2 % mod2 + mod2) % mod2;
        return ans;
    }
    
    bool operator == (const Hash & b) {
        return mt(len, val1, val2) == mt(b.len, b.val1, b.val2);
    }

    const Hash & operator = (const Hash & b) {
        len = b.len;
        val1 = b.val1;
        val2 = b.val2;
        return *this;
    }
};

Hash e[10][N];

void read(vec< int > & a, int n) {
    string x;
    cin >> x;
    for(int i = 1;i <= n;i++) {
        a[i] = x[i - 1] - '0';
    }
}

void init() {
    w1[0] = w2[0] = 1ll;
    for(int i = 1;i < N;i++) {
        w1[i] = (w1[i - 1] * p) % mod1;
        w2[i] = (w2[i - 1] * p) % mod2;
    }

    for(int value = 0;value <= 9;value++) {
        e[value][1] = Hash(value);
        for(int i = 2;i < N;i++) {
            e[value][i] = e[value][i - 1] + Hash(value);
        }
    }
}

vec< Hash > t; 
vec< int > delt;

void build(const vec< int > & a, int v, int tl, int tr) {
    if(tl == tr) t[v] = Hash(a[tl]);
    else {
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

void push(int v, int tl, int tr) {
    if(delt[v] != -1) {
        int tm = (tl + tr) >> 1;
        delt[v << 1] = delt[v << 1 | 1] = delt[v];
        t[v << 1] = e[delt[v]][tm - tl + 1];
        t[v << 1 | 1] = e[delt[v]][tr - tm];
        delt[v] = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int c) {
    if(l <= tl && tr <= r) {
        delt[v] = c;
        t[v] = e[c][tr - tl + 1];
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if(l <= tm) update(v << 1, tl, tm, l, r, c);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, c);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

Hash ask(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) return t[v];
    else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if(l <= tm) {
            if(r > tm) {
                return ask(v << 1, tl, tm, l, r) + ask(v << 1 | 1, tm + 1, tr, l, r);
            }else return ask(v << 1, tl, tm, l, r);
        }else return ask(v << 1 | 1, tm + 1, tr, l, r);
    }
}

bool solve() {
    
    init();

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    vec< int > a(n + 1);
    int ty, l, r, c, d;

    read(a, n);

    t.resize(4 * n);
    delt.resize(4 * n, -1);

    build(a, 1, 1, n);

    for(int i = 0;i < m + k;i++) {
        scanf("%d %d %d", &ty, &l, &r);
        
        if(ty == 1) {
            scanf("%d", &c);
            update(1, 1, n, l, r, c);
        }else {
            scanf("%d", &d);
            if(l + d <= r) {
                Hash h1, h2;
                h1 = ask(1, 1, n, l + d, r);
                h2 = ask(1, 1, n, l, r - d);
                puts(h1 == h2?"YES" : "NO");
            }else puts("YES");
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}