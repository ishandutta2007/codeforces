#pragma comment (linker, "/STACK:1280000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve();
        ++testNumber;
        //++timer;
    }

#ifdef room111
    cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

void precalc() {
    /*fact[0] = revfact[0] = 1;
    for (int i = 1; i < 100500; ++i) {
    fact[i] = fact[i - 1] * i % curMod;
    revfact[i] = binpow(fact[i], curMod - 2, curMod);
    }*/

    /*for (int w = 0; w < 2; ++w) {
    powers[w][0] = 1;
    for (int j = 1; j < C; ++j) {
    powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
    }
    }*/

    /*catalan[0] = 1;
    for (int n = 0; n < 200500 - 1; ++n) {
    catalan[n + 1] = catalan[n] * 2 * (2 * n + 1) % MOD * binpow(n + 2, MOD - 2, MOD) % MOD;
    }*/

    /*for (int i = 0; i < 5010; ++i) {
    c[i][i] = c[i][0] = 1;
    for (int j = 1; j < i; ++j) {
    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
    }*/

    /*for (int i = 0; i < 100; ++i) {
    doubleC[i][i] = doubleC[i][0] = 1.0;
    for (int j = 1; j < i; ++j) {
    doubleC[i][j] = doubleC[i - 1][j - 1] + doubleC[i - 1][j];
    }
    }*/

}


int gcd(int q, int w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}

//#define int li

//int mod = 1000000007;

vector<vector<int>> g;

vector<int> type;

bool dfs(int v, int p) {
    vector<int> have(3, 0);
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (!dfs(to, v)) {
            return false;
        }
        ++have[type[to]];
    }
    if (have[2] > 1 && p != -1) {
        return false;
    }
    if (have[2] > 2 && p == -1) {
        return false;
    }
    if (have[2] == 1) {
        type[v] = 2;
        return true;
    }
    if (have[1]) {
        type[v] = 2;
        return true;
    }
    if (have[0] > 2) {
        type[v] = 2;
        return true;
    }
    if (have[0] > 1) {
        type[v] = 1;
        return true;
    }
    type[v] = 0;
    return true;
}

void solve() {
    int n;
    cin >> n;
    g.resize(n);
    type.resize(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 3) {
            root = i;
            break;
        }
    }
    
    if (root == -1 || dfs(root, -1)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    
}