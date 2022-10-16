#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 2005, P = 1e9 + 7;

int n, m, f[N][N][2], R[N][N], D[N][N], c[N];

char g[N][N]; 

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline del(int &x, int y) {
    x -= y;
    if (x < 0) x += P;
}

struct H{
    int hh, tt, s;
    int v[N], w[N];
    void inline init() {
        hh = 1, tt = s = 0;
    }
    void inline ins(int x, int k) {
        ++tt;
        v[tt] = x, w[tt] = k;
        add(s, k);
    }
    int inline ask(int x) {
        while (hh <= tt && v[hh] > x) del(s, w[hh++]);
        return s;
    }
} t[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= m; j++) D[i][j] = R[i][j] = g[i][j] == 'R';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m - 1; j; j--)
            R[i][j] += R[i][j + 1];
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n - 1; i; i--)
            D[i][j] += D[i + 1][j];
    }
    for (int i = 1; i <= m; i++) t[i].init();
    for (int i = 1; i <= n; i++) {
        t[0].init();
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                f[1][1][1] = f[1][1][0] = 1; 
            } else {
                f[i][j][0] = t[0].ask(m - j);
                f[i][j][1] = t[j].ask(n - i);    
            }
            t[0].ins(R[i][j + 1], f[i][j][1]);
            t[j].ins(D[i + 1][j], f[i][j][0]);
            //cout << f[i][j][0] << " " << f[i][j][1] << " IEE " << i << " " << j << endl;
        }
    }
    f[1][1][0] = 0;
    printf("%d\n", (f[n][m][0] + f[n][m][1]) % P);
    return 0;
}