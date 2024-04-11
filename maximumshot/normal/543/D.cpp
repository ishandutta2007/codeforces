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
#include <list>

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

inline void magic(ll & x) {
    x = (x % base + base) % base;
}

inline void add(ll & x, ll y) {
    magic(x);
    magic(y);
    x = (x * y) % base;
}

int n;
vec< vec< int > > g;
vec< ll > dp;
vec< ll > ans;

void read() {
    scanf("%d", &n);

    g.resize(n + 1);
    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
}

void dfs(int v, int par = -1) {
    int child = 0;
    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(to != par) {
            dfs(to, v);
            child++;
            add(dp[v], dp[to] + 1);
        }
    }
}

void go(int v, int par = -1, ll pv = 0ll) {
    //cout << v << " " << pv << '\n';

    ans[v] = (dp[v] * (pv + 1)) % base; 

    magic(pv);
    int sz = (int)g[v].size(), id = -3;
    vec< ll > pr(sz), sf(sz);
    ll value = 1ll;
    for(int i = 0;i < sz;i++) {
        int to = g[v][i];
        if(to == par) { id = i; continue; }
        add(value, dp[to] + 1);
        pr[i] = value;
    }

    value = 1ll;
    for(int i = sz - 1;i >= 0;i--) {
        int to = g[v][i];
        if(to == par) continue;
        add(value, dp[to] + 1);
        sf[i] = value;
    }

    /*
    cout << "\t";
    for(int i = 0;i < sz;i++) cout << pr[i] << ' ';
    cout << "\n";
    cout << "\t";
    for(int i = 0;i < sz;i++) cout << sf[i] << " ";
    cout << "\n";
    */

    for(int i = 0;i < sz;i++) {
        int to = g[v][i];
        if(to == par) { continue; }
        value = (pv + 1) % base;
        
        if(i - 1 - (i - 1 == id) >= 0) {
            add(value, pr[i - 1 - (i - 1 == id)]);
        }
        
        if(i + 1 + (i + 1 == id) < sz) {
            add(value, sf[i + 1 + (i + 1 == id)]);
        }

        go(to, v, value);
    }
}

void precalc() {
    ans.resize(n + 1, 0ll);
    dp.resize(n + 1, 1ll);
    dfs(1);
    ans[1] = dp[1];
    go(1);
}

bool solve() {
    
    read();
    precalc();

    for(int i = 1;i <= n;i++) {
        int x = ans[i];
        printf("%d ", x);
    }

    puts("");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}