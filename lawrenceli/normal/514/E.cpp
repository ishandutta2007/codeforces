#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 105;
const int MOD = 1e9 + 7;

int n, x, d[MAXN];

void add(int& a, int b) { a = (a+b)%MOD; }

struct mat {
    int a[MAXN][MAXN];
    void mult(mat b) {
        int c[MAXN][MAXN];
        memset(c, 0, sizeof(c));
        for (int i=0; i<101; i++)
            for (int j=0; j<101; j++)
                for (int k=0; k<101; k++)
                    add(c[i][j], ll(a[i][k])*b.a[k][j]%MOD);
        for (int i=0; i<101; i++)
            for (int j=0; j<101; j++)
                a[i][j] = c[i][j];
    }
} cur, rec;

int main() {
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        int a; cin >> a; d[a]++;
    }
    
    rec.a[0][0] = d[1]+1;
    for (int i=1; i<100; i++) rec.a[i][0] = (d[i+1]-d[i]+MOD)%MOD;
    rec.a[100][0] = (MOD-d[100])%MOD;
    
    for (int i=1; i<101; i++) rec.a[i-1][i] = 1;
    
    for (int i=0; i<101; i++)
        for (int j=0; j<101; j++)
            if (i == j) cur.a[i][j] = 1;
    
    for (int i=31; i>=0; i--) {
        cur.mult(cur);
        if (x&1<<i) cur.mult(rec);
    }
    
    cout << cur.a[0][0] << '\n';
}