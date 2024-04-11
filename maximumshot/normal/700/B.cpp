#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

int n, k;
vec< char > uni;
vec< vec< int > > g;

ll res = 0;

int dfs(int v, int par = -1) {
    int c = uni[v], t;
    for(int to : g[v]) {
        if(to == par) continue;
        t = dfs(to, v);
        res += min(t, k + k - t);
        c += t;
    }
    return c;
}

bool solve() {

    scanf("%d %d", &n, &k);

    uni.resize(n + 1);

    for(int x, i = 0;i < k + k;i++) {
        scanf("%d", &x);
        uni[x] = 1;
    }

    g.resize(n + 1);

    for(int u, v, i = 0;i < n - 1;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    cout << res << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}