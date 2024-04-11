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

int t, n, k;
vec< string > a;
vec< vec< int > > vis;

void clear() {
    a.clear();
    vis.clear();
}

void dfs(int str, int col) {
    if(str < 0 || str > 2) return;
    if(col >= n) {
        vis[str][n - 1] = 1;
        return;
    }
    if(vis[str][col]) return;
    vis[str][col] = 1;
    if(col == n - 1) return;
    if(a[str][col + 1] != '.') return;

    int ok;

    // front
    ok = 1;
    if(col + 2 < n && a[str][col + 2] != '.') ok = 0;
    if(col + 3 < n && a[str][col + 3] != '.') ok = 0;
    if(ok) dfs(str, col + 3);

    // up
    ok = 1;
    if(str > 0 && col + 1 < n && a[str - 1][col + 1] != '.') ok = 0;
    if(str > 0 && col + 2 < n && a[str - 1][col + 2] != '.') ok = 0;
    if(str > 0 && col + 3 < n && a[str - 1][col + 3] != '.') ok = 0;
    if(ok) dfs(str - 1, col + 3);

    // down
    ok = 1;
    if(str < 2 && col + 1 < n && a[str + 1][col + 1] != '.') ok = 0;
    if(str < 2 && col + 2 < n && a[str + 1][col + 2] != '.') ok = 0;
    if(str < 2 && col + 3 < n && a[str + 1][col + 3] != '.') ok = 0;
    if(ok) dfs(str + 1, col + 3);
}

bool solve() {
    
    scanf("%d", &t);

    while(t--) {
        clear();

        scanf("%d %d", &n, &k);
        a.resize(3);
        for(int i = 0;i < 3;i++) cin >> a[i];
        
        vis.resize(3, vec< int >(n, 0));

        int str, col;
        for(int i = 0;i < 3;i++) {
            if(a[i][0] == 's') str = i, col = 0;
        }

        dfs(str, col);

        int ok = 0;
        for(int i = 0;i < 3;i++) ok |= vis[i][n - 1];

        puts(ok?"YES" : "NO");
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}