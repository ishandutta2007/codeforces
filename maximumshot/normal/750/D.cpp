#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 40;
int const delt = 400;
int const MAX_CRD = 900;
int t[N];
int n;
bool used[MAX_CRD][MAX_CRD][35][4];
bool tot_used[MAX_CRD][MAX_CRD];

void check(int x, int y, int i, int x0, int y0, int type) {
    if(i == n) return;
    if(used[x + delt][y + delt][i][type]) return;
    used[x + delt][y + delt][i][type] = 1;
    if(i % 2 == 0) {
        if(type == 0) {
            for(int it = 0;it < t[i];it++) {
                tot_used[x - it + delt][y + delt] = 1;
            }
             check(x - t[i], y + 1, i + 1, x0, y0, 0);
             check(x - t[i], y - 1, i + 1, x0, y0, 3);
        }else if(type == 1) {
            for(int it = 0;it < t[i];it++) {
                tot_used[x + it + delt][y + delt] = 1;
            }
             check(x + t[i], y + 1, i + 1, x0, y0, 2);
             check(x + t[i], y - 1, i + 1, x0, y0, 1);
        }else if(type == 2) {
            for(int it = 0;it < t[i];it++) {
                tot_used[x + delt][y + it + delt] = 1;
            }
             check(x - 1, y + t[i], i + 1, x0, y0, 0);
             check(x + 1, y + t[i], i + 1, x0, y0, 2);
        }else {
            for(int it = 0;it < t[i];it++) {
                tot_used[x + delt][y - it + delt] = 1;
            }
             check(x - 1, y - t[i], i + 1, x0, y0, 3);
             check(x + 1, y - t[i], i + 1, x0, y0, 1);
        }
    }else {
        if(type == 0) {
            for(int it = 0;it < t[i];it++) {
                tot_used[x - it + delt][y + it + delt] = 1;
            }
             check(x - t[i] + 1, y + t[i], i + 1, x0, y0, 2);
             check(x - t[i], y + t[i] - 1, i + 1, x0, y0, 0);
        }else if(type == 1) {
            for(int it = 0;it < t[i];it++) {
                tot_used[x + it + delt][y - it + delt] = 1;
            }
             check(x + t[i], y - t[i] + 1, i + 1, x0, y0, 1);
             check(x + t[i] - 1, y - t[i], i + 1, x0, y0, 3);
        }else if(type == 2) {
            for(int it = 0;it < t[i];it++) {
                tot_used[x + it + delt][y + it + delt] = 1;
            }
             check(x + t[i] - 1, y + t[i], i + 1, x0, y0, 2);
             check(x + t[i], y + t[i] - 1, i + 1, x0, y0, 1);
        }else {
            for(int it = 0;it < t[i];it++) {
                tot_used[x - it + delt][y - it + delt] = 1;
            }
             check(x - t[i], y - t[i] + 1, i + 1, x0, y0, 0);
             check(x - t[i] + 1, y - t[i], i + 1, x0, y0, 3);
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &t[i]);
    }

    check(0, 0, 0, 0, 0, 2);

    int res = 0;

    for(int i = 0;i < MAX_CRD;i++) {
        for(int j = 0;j < MAX_CRD;j++) {
            res += tot_used[i][j];
        }
    }

    cout << res << "\n";

    return 0;
}