#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)
#define mp make_pair

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
int a[N];
int pos[N];
vec< int > g[N];
int dp[N];

int rec(int v) {
    if(dp[v] != -1) return dp[v];
    if(g[v].empty()) {
        return dp[v] = 0;
    }
    for(int to : g[v]) {
        if(!rec(to)) {
            return dp[v] = 1;
        }
    }
    return dp[v] = 0;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

//    mt19937 rnd(42);

    scanf("%d", &n);
//    n = 1e5;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
//        a[i] = i;
        pos[a[i]] = i;
    }

//    shuffle(a + 1, a + n + 1, rnd);

    for(int x = 1;x <= n;x++) {
        for(int y = x;y <= n;y += x) {
            int d = y;
            if(pos[x] + d <= n && a[ pos[x] + d ] > x) {
                g[pos[x]].push_back(pos[x] + d);
            }
            if(pos[x] - d >= 1 && a[ pos[x] - d ] > x) {
                g[pos[x]].push_back(pos[x] - d);
            }
        }
    }

    fill(dp + 1, dp + n + 1, -1);

    for(int i = 1;i <= n;i++) {
        printf("%c", rec(i) ? 'A' : 'B');
    }
    printf("\n");

    return 0;
}