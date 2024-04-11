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

char buffer[50];

const int N = 1e6 + 5;

enum TYPE {AND, OR, XOR, NOT, IN};

int n;
TYPE type[N];
int L[N], R[N];
int st[N];
int h[N], link[N];
int from[N];
int tin[N];
int tout[N];
int timer;

int calc(int v, int lx, int rx) {
    if(type[v] == AND) {
        return lx & rx;
    }else if(type[v] == OR) {
        return lx | rx;
    }else if(type[v] == XOR) {
        return lx ^ rx;
    }
}

void dfs(int v, int par = -1) {
    tin[v] = timer++;
    link[v] = from[v] = par;
    if(par != -1) {
        if(L[par] && R[par]) {
        }else {
            link[v] = link[par];
        }
    }
    h[v] = par == -1 ? 0 : h[par] ^ 1;
    if(!L[v] && !R[v]) {
        tout[v] = timer++;
        return;
    }
    if(L[v] && R[v]) {
        dfs(L[v], v);
        dfs(R[v], v);
        st[v] = calc(v, st[L[v]], st[R[v]]);
    }else {
        dfs(L[v], v);
        st[v] = !st[L[v]];
    }
    tout[v] = timer++;
}

int dp[N][2];

void go(int v) {
    if(L[v] && R[v]) {
        for(int x = 0;x < 2;x++) {
            dp[L[v]][x] = dp[v][calc(v, x, st[R[v]])];
            dp[R[v]][x] = dp[v][calc(v, st[L[v]], x)];
        }
        go(L[v]);
        go(R[v]);
    }else if(L[v]) {
        for(int x = 0;x < 2;x++) {
            dp[L[v]][x] = dp[v][x ^ 1];
        }
        go(L[v]);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%s", buffer);
        if(buffer[0] == 'A') {
            type[i] = AND;
            scanf("%d %d", &L[i], &R[i]);
        }else if(buffer[0] == 'O') {
            type[i] = OR;
            scanf("%d %d", &L[i], &R[i]);
        }else if(buffer[0] == 'X') {
            type[i] = XOR;
            scanf("%d %d", &L[i], &R[i]);
        }else if(buffer[0] == 'N') {
            type[i] = NOT;
            scanf("%d", &L[i]);
        }else if(buffer[0] == 'I') {
            type[i] = IN;
            scanf("%d", &st[i]);
        }
    }

    dfs(1);
    dp[1][0] = 0;
    dp[1][1] = 1;
    go(1);

    for(int v = 1;v <= n;v++) {
        if(type[v] == IN) {
            printf("%d", dp[v][st[v] ^ 1]);
        }
    }

    printf("\n");

    return 0;
}