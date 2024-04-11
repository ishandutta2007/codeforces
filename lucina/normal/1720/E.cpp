#include <bits/stdc++.h>
using namespace std;
/*
First, thing first, you can increase at most one in each operation, but??

Let's say, we decreased it drastically

the size of distinct is at most 2n
Let's say the values is < 2n now,
The size of increasing will decrease by at most 2, so we can do it in two operations,
The rest is just check that we can do it in one operation or not
*/

const int nax = 512;
int n, k;
int a[nax][nax];
int cnt[nax * nax];
int min_i[nax * nax];
int max_i[nax * nax];
int min_j[nax * nax];
int max_j[nax * nax];
int pref[nax][nax];

void upd_min(int &a, int b) {
    a = min(a, b);
}
void upd_max(int &a, int b) {
    a = max(a, b);
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;

    memset(min_i, 0x3f, sizeof(min_i));
    memset(min_j, 0x3f, sizeof(min_j));

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= n ; ++ j) {
        cin >> a[i][j];
        cnt[a[i][j]] += 1;
        upd_min(min_i[a[i][j]], i);
        upd_max(max_i[a[i][j]], i);
        upd_min(min_j[a[i][j]], j);
        upd_max(max_j[a[i][j]], j);
    }
    int cnt_unique = 0;
    for (int i = 1 ; i <= n * n ; ++ i) {
        if (cnt[i] > 0) {
            cnt_unique += 1;
        }
    }

    if (cnt_unique <= k) {
        cout << k - cnt_unique << '\n';
        return 0;
    }


    int dif = cnt_unique - k;

    for (int len = 1 ; len <= n ; ++ len) {
        for (int i = 0 ; i <= n ; ++ i)
        for (int j = 0 ; j <= n ; ++ j)
            pref[i][j] = 0;
        for (int v = 1 ; v <= n * n ; ++ v) {
            if (cnt[v] > 0) {
                int mn_i = min_i[v], mx_i = max_i[v], mn_j = min_j[v], mx_j = max_j[v];
                mn_i = min(n - len + 1, mn_i);
                mn_j = min(n - len + 1, mn_j);
                mx_i = max(1, mx_i - len + 1);
                mx_j = max(1, mx_j - len + 1);
                if (mx_i <= mn_i && mx_j <= mn_j) {
                    pref[mx_i][mx_j] += 1;
                    pref[mn_i + 1][mx_j] -= 1;
                    pref[mx_i][mn_j + 1] -= 1;
                    pref[mn_j + 1][mn_j + 1] += 1;
                }
            }
        }
        for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= n ; ++ j) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (pref[i][j] == dif || pref[i][j] == dif + 1) {
           //     cout << len << '\n';
                cout << "1\n";
                return 0;
            }
        }
    }
    cout << 2 << '\n';


    /**
        how to check if there exists matrix with cover, X or X - 1 distinct values

        f(x) be the maximum distinct values of size x matrix

        There's roughly O(n^3) matrix,

        Iterate over each length of square matrix,
        the corner of cover rectangle is another rectangle, use prefix sum to calculate it
    */
}