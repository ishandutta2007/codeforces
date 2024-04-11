#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222, mod = 1000000007;

int dpt[max_n][max_n];
int dpl[max_n][max_n];
int prd[max_n][max_n];
int prr[max_n][max_n];

int cntd[max_n][max_n];
int cntr[max_n][max_n];
char f[max_n][max_n];

int n, m;

int get_sum_row(int i, int fj, int tj) {
    if (tj < fj) {
        return 0;
    }
    int ans = prr[i][fj];
    if (tj != m - 1) {
        ans -= prr[i][tj + 1];
    }
    ans += mod;
    ans %= mod;
    return ans;
}
int get_sum_col(int j, int fi, int ti) {
    if (ti < fi) {
        return 0;
    }
    int ans = prd[fi][j];
    if (ti != n - 1) {
        ans -= prd[ti + 1][j];
    }
    ans += mod;
    ans %= mod;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i= 0 ; i < n; ++i) {
        scanf("%s", f[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            cntr[i][j] = (f[i][j] == 'R');
            if (j != m - 1) {
                cntr[i][j] += cntr[i][j + 1];
            }
            cntd[i][j] = (f[i][j] == 'R');
            if (i != n - 1) {
                cntd[i][j] += cntd[i + 1][j];
            }
        }
    }
    for (int j = m - 1; j >= 0; --j) {
        if (cntr[n - 1][j]) {
            dpt[n - 1][j] = 0;
            dpl[n - 1][j] = 0;
        } else {
            dpt[n - 1][j] = 1;
            dpl[n - 1][j] = 1;
        }
        int i = n - 1;
        prd[i][j] = dpl[i][j];
        if (i != n - 1) {
            prd[i][j] += prd[i + 1][j];
        }
        prd[i][j] %= mod;

        prr[i][j] = dpt[i][j];
        if (j != m - 1) {
            prr[i][j] += prr[i][j + 1];
        }
        prr[i][j] %= mod;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (cntd[i][m - 1]) {
            dpt[i][m - 1] = 0;
            dpl[i][m - 1] = 0;
        } else {
            dpt[i][m - 1] = 1;
            dpl[i][m - 1] = 1;
        }
        int j = m - 1;
        prd[i][j] = dpl[i][j];
        if (i != n - 1) {
            prd[i][j] += prd[i + 1][j];
        }
        prd[i][j] %= mod;

        prr[i][j] = dpt[i][j];
        if (j != m - 1) {
            prr[i][j] += prr[i][j + 1];
        }
        prr[i][j] %= mod;
    }
    for (int i = n - 2; i >= 0; --i) {
        for(int j = m - 2; j >= 0; --j) {
            //// from left
            int cr = cntr[i][j];
            int cd = cntd[i][j];
            if (f[i][j] == 'R') {
                --cd;
            }
            if (cr < m - j) {
                int fj = j + 1;
                int tj = m - 1 - cr;
                int fi = i + 1;
                int ti = n - 1 - cd;
                dpl[i][j] += get_sum_row(i + 1, fj, tj);
                dpl[i][j] %= mod;
                dpl[i][j] += get_sum_col(j + 1, fi, ti);
                dpl[i][j] %= mod;
            }
            //// from top
            cr = cntr[i][j];
            cd = cntd[i][j];
            if (f[i][j] == 'R') {
                --cr;
            }
            if (cd < n - i) {
                int fj = j + 1;
                int tj = m - 1 - cr;
                int fi = i + 1;
                int ti = n - 1 - cd;
                dpt[i][j] += get_sum_row(i + 1, fj, tj);
                dpt[i][j] %= mod;
                dpt[i][j] += get_sum_col(j + 1, fi, ti);
                dpt[i][j] %= mod;
            }

            prd[i][j] = dpl[i][j];
            prd[i][j] += prd[i + 1][j];
            prd[i][j] %= mod;
            prr[i][j] = dpt[i][j];
            prr[i][j] += prr[i][j + 1];
            prr[i][j] %= mod;
        }
    }
    //cout << dpt[1][2] << endl;
    //cout << dpt[1][1] << endl;
    //cout << prr[1][1] << endl;
    //cout << get_sum_row(1, 1, 2) << endl;
    cout << dpl[0][0] << endl;
    return 0;
}