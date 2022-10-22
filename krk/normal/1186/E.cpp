#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m, q;
char B[Maxn][Maxn];
int A[Maxn][Maxn];

ll getNone(int r, int c, int md)
{
    return md? r * c - A[r][c]: A[r][c];
}

ll getRows(int r, int c, int md)
{
    c--;
    int myc = c / (2 * m) * 2 * m;
    ll res = ll(r) * myc / 2;
    if (c < myc + m) res += getNone(r, c - myc + 1, (__builtin_popcount(myc / m) + md) % 2);
    else res += getNone(r, m, (__builtin_popcount(myc / m) + md) % 2) +
                getNone(r, c - myc - m + 1, (__builtin_popcount(myc / m) + md + 1) % 2);
    return res;
}

ll getCols(int r, int c, int md)
{
    r--;
    int myr = r / (2 * n) * 2 * n;
    ll res = ll(c) * myr / 2;
    if (r < myr + n) res += getNone(r - myr + 1, c, (__builtin_popcount(myr / n) + md) % 2);
    else res += getNone(n, c, (__builtin_popcount(myr / n) + md) % 2) +
                getNone(r - myr - n + 1, c, (__builtin_popcount(myr / n) + md + 1) % 2);
    return res;
}

ll Get(int r, int c)
{
    if (r == 0 || c == 0) return 0;
    r--; c--;
    int myr = r / (2 * n) * 2 * n, myc = c / (2 * m) * 2 * m;
    ll res = ll(myr) * myc / 2;
    if (r < myr + n) res += getRows(r - myr + 1, c + 1, __builtin_popcount(myr / n) % 2);
    else res += getRows(n, c + 1, __builtin_popcount(myr / n) % 2) +
                getRows(r - myr - n + 1, c + 1, (__builtin_popcount(myr / n) + 1) % 2);
    if (c < myc + m) res += getCols(myr, c - myc + 1, __builtin_popcount(myc / m) % 2);
    else res += getCols(myr, m, __builtin_popcount(myc / m) % 2) +
                getCols(myr, c - myc - m + 1, (__builtin_popcount(myc / m) + 1) % 2);
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", B[i] + 1);
        for (int j = 1; j <= m; j++)
            A[i][j] = (B[i][j] == '1') + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
    }
    while (q--) {
        int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        printf("%I64d\n", Get(r2, c2) - Get(r1 - 1, c2) - Get(r2, c1 - 1) + Get(r1 - 1, c1 - 1));
    }
    return 0;
}