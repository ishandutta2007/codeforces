#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 105;

int n, m;
int g[N][N];
pair< string, int > res[505 * N * N];
int sz;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d", &g[i][j]);
        }
    }

    int ok;

    while(1) {
        ok = 0;
//        for(int i = 1;i <= n;i++) {
//            for(int j = 1;j <= m;j++) {
//                cout << g[i][j] << " ";
//            }
//            cout << "\n";
//        }
        for(int j = 1;j <= m;j++) {
            int mx = -1;
            int mn = -1;
            for(int i = 1;i <= n;i++) {
                if(mx == -1 || g[mx][j] < g[i][j]) {
                    mx = i;
                }
                if(mn == -1 || g[mn][j] > g[i][j]) {
                    mn = i;
                }
            }
            if(g[mx][j] > g[mn][j]) {
                ok = 1;
                res[sz++] = make_pair("row", mx);
                for(int q = 1;q <= m;q++) {
                    if(g[mx][q] == 0) {
                        puts("-1");
                        return 0;
                    }else {
                        g[mx][q]--;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            int mx = -1;
            int mn = -1;
            for(int j = 1;j <= m;j++) {
                if(mx == -1 || g[i][mx] < g[i][j]) {
                    mx = j;
                }
                if(mn == -1 || g[i][mn] > g[i][j]) {
                    mn = j;
                }
            }
            if(g[i][mx] > g[i][mn]) {
                ok = 1;
                res[sz++] = make_pair("col", mx);
                for(int q = 1;q <= n;q++) {
                    if(g[q][mx] == 0) {
                        puts("-1");
                        return 0;
                    }else {
                        g[q][mx]--;
                    }
                }
            }
        }
        if(!ok) break;
    }

    if(g[1][1] > 0) {
        if(n <= m) {
            for(int iter = 0;iter < g[1][1];iter++) {
                for(int i = 1;i <= n;i++) {
                    res[sz++] = make_pair("row", i);
                }
            }
        }else {
            for(int iter = 0;iter < g[1][1];iter++) {
                for(int j = 1;j <= m;j++) {
                    res[sz++] = make_pair("col", j);
                }
            }
        }
    }

    printf("%d\n", sz);

    for(int i = 0;i < sz;i++) {
        for(char c : res[i].first) {
            printf("%c", c);
        }
        printf(" ");
        printf("%d\n", res[i].second);
    }

    return 0;
}