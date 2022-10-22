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

const int N = 1e6 + 5;

int n, m;
vec< int > g[N], gr[N];
int ptr = 1;
int del[N];
int mark[N];

void solve() {
    while(ptr <= n && del[ptr]) ptr++;
    if(ptr > n) return;
    int v = ptr++;
    for(int to : g[v]) del[to] = 1;
    solve();
    int any = 0;
    for(int to : gr[v]) {
        if(mark[to]) {
            any = 1;
            break;
        }
    }
    if(!any) {
        mark[v] = 1;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    solve();

    printf("%d\n", count(mark + 1, mark + n +1, 1));

    for(int i = 1;i <= n;i++) {
        if(mark[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}