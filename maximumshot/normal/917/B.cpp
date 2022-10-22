#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef unsigned int ui;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 105;

int n, m;
vec< pair< int, char > > g[N];
int dp[N][N][2][26];
bool used[N][N][2][26];

int rec(int a, int b, int x, int c) {
    if(used[a][b][x][c]) {
        return dp[a][b][x][c];
    }
    used[a][b][x][c] = 1;
    if(x == 0) {
        int any = 0;
        for(pair< int, char > ed : g[a]) {
            if(ed.second < c) continue;
            if(!rec(ed.first, b, x ^ 1, ed.second)) {
                any = 1;
            }
        }
        return dp[a][b][x][c] = any;
    }else {
        int any = 0;
        for(pair< int, char > ed : g[b]) {
            if(ed.second < c) continue;
            if(!rec(a, ed.first, x ^ 1, ed.second)) {
                any = 1;
            }
        }
        return dp[a][b][x][c] = any;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        char symb;
        scanf("%d %d %c", &u, &v, &symb);
        g[u].push_back(make_pair(v, symb - 'a'));
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(rec(i, j, 0, 0)) {
                printf("A");
            }else {
                printf("B");
            }
        }
        printf("\n");
    }

    return 0;
}