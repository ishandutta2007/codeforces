#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 45;

int n, k;
int g[N][N];

void printAns(int m) {
    printf("%.10lf\n", 1.0 * k * k * (m - 1) / (2.0 * m));
}

bool good[1 << 20];
int best[1 << 20];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d", &g[i][j]);
        }
    }

    if(n == 1) {
        printAns(1);
        return 0;
    }

    int m = 1;

    int n2 = n / 2;

    good[0] = 1;

    for(int mask = 1;mask < (1 << n2);mask++) {
        int ok = 1;
        for(int i = 0;i < n2 && ok;i++) {
            if((1 << i) & mask) {
                for(int j = i + 1;j < n2 && ok;j++) {
                    if((1 << j) & mask) {
                        if(!g[i][j]) {
                            ok = 0;
                        }
                    }
                }
            }
        }
        good[mask] = ok;
    }

    for(int mask = 0;mask < (1 << n2);mask++) {
        if(good[mask]) {
            best[mask] = __builtin_popcount(mask);
            continue;
        }
        for(int i = 0;i < n2;i++) {
            if((1 << i) & mask) {
                best[mask] = max(best[mask], best[mask ^ (1 << i)]);
            }
        }
    }

    int n3 = n - n2;

    for(int mask = 0;mask < (1 << n3);mask++) {
        int ok = 1;
        for(int i = 0;i < n3 && ok;i++) {
            if((1 << i) & mask) {
                for(int j = i + 1;j < n3 && ok;j++) {
                    if((1 << j) & mask) {
                        if(!g[i + n2][j + n2]) {
                            ok = 0;
                        }
                    }
                }
            }
        }
        int cnt_bit = __builtin_popcount(mask);
        if(ok) {
            int rmask = 0;
            for(int i = 0;i < n2;i++) {
                int cnt = 0;
                for(int j = 0;j < n3;j++) {
                    if((1 << j) & mask) {
                        if(g[i][j + n2]) {
                            cnt++;
                        }
                    }
                }
                if(cnt == cnt_bit) {
                    rmask |= (1 << i);
                }
            }
            m = max(m, cnt_bit + best[rmask]);
        }
    }

    printAns(m);

    return 0;
}