#include <bits/stdc++.h>
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;

const int N = 2e3 + 6;
const int M = 1e9 + 7;

int pos1[N][N], pos2[N][N], up[N][N], l[N][N], n, m;
char a[N][N];

int t_up[N][4*N], t_l[N][4*N];

void upd_up(int x, int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
        t_up[x][v] += val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        upd_up(x, v + v, vl, vm, pos, val);
    else
        upd_up(x, v + v + 1, vm + 1, vr, pos, val);
    t_up[x][v] = (t_up[x][v + v] + t_up[x][v + v + 1]) % M;
}


void upd_l(int x, int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
        t_l[x][v] += val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        upd_l(x, v + v, vl, vm, pos, val);
    else
        upd_l(x, v + v + 1, vm + 1, vr, pos, val);
    t_l[x][v] = (t_l[x][v + v] + t_l[x][v + v + 1]) % M;
}

int sum_up(int x, int v, int vl, int vr, int l, int r) {
    if (l == 0)
        l = 1;
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t_up[x][v];
    int vm = (vl + vr) / 2;
    return (sum_up(x, v + v, vl, vm, l, min(r, vm)) + sum_up(x, v + v + 1, vm + 1, vr, max(l, vm + 1), r)) % M;
}


int sum_l(int x, int v, int vl, int vr, int l, int r) {
    if (l == 0)
        l = 1;

    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t_l[x][v];
    int vm = (vl + vr) / 2;
    return (sum_l(x, v + v, vl, vm, l, min(r, vm)) + sum_l(x, v + v + 1, vm + 1, vr, max(l, vm + 1), r)) % M;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    up[1][1] = 1;
    l[1][1] = 1;
    if (n + m == 2) {
        cout << 1;
        return 0;
    }

    ///finding_pos + pos2
    for (int i = 1; i <= n; i++) {
        int kol = 0;
        for (int j = m; j > 0; j--) {
            if (a[i][j] == 'R')
                kol++, pos1[i][kol] = j;
        }
    }
    for (int j = 1; j <= m; j++) {
        int kol = 0;
        for (int i = n; i > 0; i--)
            if (a[i][j] == 'R')
                kol++, pos2[kol][j] = i;
    }
    upd_up(1, 1, 1, m, 1, 1);
    upd_l(1, 1, 1, n, 1, 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        if (i + j != 2) {
            int left = pos1[i][m - j + 1];
            l[i][j] += sum_up(i, 1, 1, m, left, j - 1);
            int upper = pos2[n - i + 1][j];
            up[i][j] += sum_l(j, 1, 1, n, upper, i - 1);
            //cout << i << ' ' << j << ' ' <<left << ' ' << upper << ' ' << up[i][j] << ' ' << l[i][j] << endl;
            upd_up(i, 1, 1, m, j, up[i][j]);
            upd_l(j, 1, 1, n, i, l[i][j]);
        }
    cout << (up[n][m] + l[n][m]) % M;
    return 0;
}