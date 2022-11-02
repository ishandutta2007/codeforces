#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, m;
long long ans;
char mat[MAXN][MAXN], mat2[MAXN][MAXN];
int pr[MAXN][MAXN], pc[MAXN][MAXN];

void init() {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            int x = mat[i][j] == '#' ? 1 : 0;
            pr[i][j+1] = pr[i][j] + x;
            pc[i+1][j] = pc[i][j] + x;
        }
}

void rot() {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            mat2[j][i] = mat[i][j];
    swap(n, m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            mat[i][j] = mat2[i][j];
}

int l, r, a[2*MAXN];

void go() {
    for (int i=1; i+1<n; i++) {
        l = r = 0;
        for (int j=1; j+1<m; j++) {
            int b1=0, b2=0;
            if (!pc[i+1][j]) a[r++] = j, b1=1;
            if (!(pc[n][j]-pc[i][j])) a[r++] = j, b2=1;
            r -= b1+b2;
            while (l<r && pr[i][j+1]-pr[i][a[l]]) l++;
            ans += (b1+b2)*(r-l);
            r += b1+b2;
            
            if (j>1 && !pc[i+1][j] && !pc[i+1][j-1]) ans--;
            if (j>1 && !(pc[n][j]-pc[i][j]) && !(pc[n][j-1]-pc[i][j-1])) ans--;
        }
    }
    for (int i=1; i+1<m; i++)
        if (!pc[n][i]) ans++;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> mat[i];
    
    init();
    
    for (int i=1; i+1<n; i++)
        for (int j=1; j+1<m; j++) {
            int x = (pr[i][j+1]?0:1) + (pr[i][m]-pr[i][j]?0:1);
            int y = (pc[i+1][j]?0:1) + (pc[n][j]-pc[i][j]?0:1);
            ans += x*y;
        }
    
    go(), rot(), init(), go();
    cout << ans;
}