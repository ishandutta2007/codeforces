#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 7005;

int k[2];
int s[2][N];
int dist[2][N];
int n;
int deg[2][N];
bool win[2][N];
bool lose[2][N];
bool used[2][N];

void dfs(int x, int v) {
    used[x][v] = 1;
    for(int iter = 0;iter < k[x ^ 1];iter++) {
        int from = ((v - s[x ^ 1][iter]) % n + n) % n;
        if(!used[x ^ 1][from]) {
            if(lose[x][v]) {
                win[x ^ 1][from] = 1;
            }else if(--deg[x ^ 1][from] == 0) {
                lose[x ^ 1][from] = 1;
            }else {
                continue;
            }
            dfs(x ^ 1, from);
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 0;i < 2;i++) {
        scanf("%d", &k[i]);
        for(int j = 0;j < k[i];j++) {
            scanf("%d", &s[i][j]);
        }
    }

    lose[0][0] = 1;
    lose[1][0] = 1;

    for(int x = 0;x < 2;x++) {
        for(int v = 0;v < n;v++) {
            deg[x][v] = k[x];
        }
    }

    for(int x = 0;x < 2;x++) {
        for(int v = 0;v < n;v++) {
            if(!used[x][v] && (win[x][v] || lose[x][v])) {
                dfs(x, v);
            }
        }
    }

    for(int x = 0;x < 2;x++) {
        for(int v = 1;v < n;v++) {
            if(win[x][v]) {
                printf("Win ");
            }else if(lose[x][v]) {
                printf("Lose ");
            }else {
                printf("Loop ");
            }
        }
        printf("\n");
    }

    return 0;
}