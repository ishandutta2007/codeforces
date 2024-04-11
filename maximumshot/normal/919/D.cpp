#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 3e5 + 5;

int n, m;
char s[N];
vec< int > g[N];
int color[N];
int tops[N];
int sz;

int dfs(int v) {
    color[v] = 1;
    for(int to : g[v]) {
        if(!color[to]) {
            if(dfs(to)) {
                return 1;
            }
        }else if(color[to] == 1) {
            return 1;
        }
    }
    color[v] = 2;
    return 0;
}

bool check_acyclic() {
    for(int v = 1;v <= n;v++) {
        if(!color[v]) {
            if(dfs(v)) {
                return false;
            }
        }
    }
    return true;
}

int dp[N];

int calc(char symb) {
    fill(dp, dp + N, -inf);
    for(int i = sz - 1;i >= 0;i--) {
        int v = tops[i];
        dp[v] = s[v] == symb;
        for(int to : g[v]) {
            dp[v] = max(dp[v], dp[to] + (s[v] == symb));
        }
    }
    return *max_element(dp + 1, dp + n + 1);
}

void go(int v) {
    color[v] = 1;
    for(int to : g[v]) {
        if(!color[to]) {
            go(to);
        }
    }
    tops[sz++] = v;
}

void find_tops() {
    fill(color, color + N, 0);
    for(int v = 1;v <= n;v++) {
        if(!color[v]) {
            go(v);
        }
    }
    reverse(tops, tops + sz);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %s", &n, &m, s + 1);

    for(int u, v, i = 1;i <= m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }

    if(!check_acyclic()) {
        puts("-1");
        return 0;
    }

    find_tops();

    int res = 0;

    for(char c = 'a';c <= 'z';c++) {
        res = max(res, calc(c));
    }

    printf("%d\n", res);

    return 0;
}