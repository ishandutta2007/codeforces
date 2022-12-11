#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200200;

int n;
int a[MAXN];
vector<int> graph[MAXN];
long long f[MAXN][2], g[2];

void upd(long long &a, long long b) {

    if (a == -1) {
        a = b;
    }
    a = max(a, b);
}

void dfs(int v) {
    f[v][0] = 0;
    f[v][1] = -1;
    for (int u : graph[v] ) {
        dfs(u);
        g[0] = g[1] = -1;
        int au = a[u];
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                if (f[v][a] == -1 || f[u][b] == -1) {
                    continue;
                } 
                upd(g[a ^ b], f[v][a] + f[u][b] );
                if (b == 0) {
                    upd(g[a ^ b ^ 1], f[v][a] + f[u][b] + au);
                }
            }
        }
        upd(f[v][0], g[0] );
        upd(f[v][1], g[1] );
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p; scanf("%d%d", &p, &a[i] );
        if (i > 1) {
            // cerr << p << " -> " << i << "\n";
            graph[p].push_back(i);
        }
    }
    dfs(1);
    cout << max(f[1][1], f[1][0] + a[1] ) << "\n";
}

int main() {
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
    return 0;
}