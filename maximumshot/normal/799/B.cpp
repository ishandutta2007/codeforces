#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n;
int p[N];
int a[N];
int b[N];
int m;
set< int > cost[4][4];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
        cost[a[i]][b[i]].insert(p[i]);
    }

    scanf("%d", &m);

    for(int x, iter = 0;iter < m;iter++) {
        int best = -1;
        int cx, cy;
        scanf("%d", &x);
        for(int y = 1;y <= 3;y++) {
            if(cost[x][y].empty()) continue;
            if(best == -1 || *cost[x][y].begin() < best) {
                best = *cost[x][y].begin();
                cx = x;
                cy = y;
            }
        }
        for(int y = 1;y <= 3;y++) {
            if(cost[y][x].empty()) continue;
            if(best == -1 || *cost[y][x].begin() < best) {
                best = *cost[y][x].begin();
                cx = y;
                cy = x;
            }
        }
        if(best == -1) {
            printf("-1 ");
        }else {
            printf("%d ", best);
            cost[cx][cy].erase(cost[cx][cy].begin());
        }
    }

    printf("\n");

    return 0;
}