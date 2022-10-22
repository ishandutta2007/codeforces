#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, q;
vec< int > g[N];
int cnt[N];
int euler[N], sz;
int pos[N];

void dfs(int v) {
    euler[++sz] = v;
    pos[v] = sz;
    cnt[v] = 1;
    for(int to : g[v]) {
        dfs(to);
        cnt[v] += cnt[to];
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        g[x].push_back(i);
    }

    for(int v = 1;v <= n;v++) {
        sort(ALL(g[v]));
    }

    dfs(1);

    for(int iter = 0;iter < q;iter++) {
        int u, k;
        scanf("%d %d", &u, &k);
        if(cnt[u] < k) {
            puts("-1");
        }else {
            printf("%d\n", euler[pos[u] + k - 1]);
        }
    }

    return 0;
}