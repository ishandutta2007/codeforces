#include <bits/stdc++.h>

using namespace std;

const int nmax = 4e2 + 10;
const int vmax = 400 * 400 + 10;

int n, m, ans;
int a[nmax][nmax], ap[vmax], r[nmax];;

short int ***prv, ***nxt;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

void clear_ap(int l) {
    for (int j = 1; j <= m; ++j)
        ap[a[l][j]] = 0;
}

void precompute() {
    prv = new short int **[n+1];
    nxt = new short int **[n+1];

    for (int i = 1; i <= n; ++i)
        prv[i] = new short int *[n-i+1],
        nxt[i] = new short int *[n-i+1];

    for (int l1 = n; l1; --l1)
        for (int l2 = l1; l2 <= n; ++l2) {
            prv[l1][l2-l1] = new short int [m+1];
            nxt[l1][l2-l1] = new short int [m+1];

            for (int j = 1; j <= m; ++j) {
                if (l1 != l2) ap[a[l1][j]] = j;
                if (ap[a[l2][j]]) prv[l1][l2-l1][j] = ap[a[l2][j]];
                else prv[l1][l2-l1][j] = 0;
                if (l1 == l2) ap[a[l1][j]] = j;
            }
            clear_ap(l1);

            for (int j = m; j; --j) {
                if (l1 != l2) ap[a[l1][j]] = j;
                if (ap[a[l2][j]]) nxt[l1][l2-l1][j] = ap[a[l2][j]];
                else nxt[l1][l2-l1][j] = m + 1;
                if (l1 == l2) ap[a[l1][j]] = j;
            }
            clear_ap(l1);

            for (int j = 1; j <= m && l1 + 1 <= l2; ++j)
                prv[l1][l2-l1][j] = max(prv[l1][l2-l1][j], prv[l1+1][l2-l1-1][j]),
                nxt[l1][l2-l1][j] = min(nxt[l1][l2-l1][j], nxt[l1+1][l2-l1-1][j]);
        }
}

void compute_answer() {
    for (int l1 = 1; l1 <= n; ++l1) {
        for (int j = 1; j <= m; ++j)
            r[j] = m;

        for (int l2 = l1; l2 <= n; ++l2) {
             for (int j = m; j; --j) {
                r[prv[l1][l2-l1][j]] = min(r[prv[l1][l2-l1][j]], j - 1);
                r[j] = min(r[j], nxt[l1][l2-l1][j] - 1);
             }

             for (int j = m - 1; j; --j)
                r[j] = min(r[j], r[j+1]);

             for (int j = 1; j <= m; ++j)
                ans = max(ans, (l2 - l1 + 1) * (r[j] - j + 1));
        }
    }
}

void output() {
    cout << ans << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    #endif // ONLINE_JUDGE

    input();
    precompute();
    compute_answer();
    output();

    return 0;
}