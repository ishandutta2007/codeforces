#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
const int MAXLG = 17;

int n, m, K, a[MAXN][5], mat[MAXN][5][MAXLG];

int qry(int l, int r, int c) {
    int ret = 0;
    for (int i=MAXLG-1; i>=0; i--)
        if (l+(1<<i)<=r)
            ret = max(ret, mat[l][c][i]), l += 1<<i;
    return ret;
}

bool check(int mid) {
    for (int i=1; i<=n; i++)
        if (i-mid >= 0) {
            int sum = 0;
            for (int j=0; j<m; j++) sum += qry(i-mid, i, j);
            if (sum <= K) return 1;
        }
    return 0;
}

int main() {
    cin >> n >> m >> K;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            mat[i][j][0] = a[i][j];
        }
    
    for (int k=0; k<MAXLG-1; k++) for (int j=0; j<m; j++) for (int i=0; i<n; i++) {
        mat[i][j][k+1] = mat[i][j][k];
        if (i+(1<<k)<n) mat[i][j][k+1] = max(mat[i][j][k], mat[i+(1<<k)][j][k]);
    }
    
    int lo = 0, hi = n;
    while (lo<hi) {
        int mid = (lo+hi+1)/2;
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    
    for (int i=1; i<=n; i++)
        if (i-lo >= 0) {
            int sum = 0;
            for (int j=0; j<m; j++) sum += qry(i-lo, i, j);
            if (sum <= K) {
                for (int j=0; j<m; j++) cout << qry(i-lo, i, j) << ' ';
                return 0;
            }
        }
}